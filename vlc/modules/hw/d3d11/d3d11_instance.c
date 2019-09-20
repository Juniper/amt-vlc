/*****************************************************************************
 * d3d11_instance.c: D3D11 unique device context instance
 *****************************************************************************
 * Copyright © 2017 VLC authors, VideoLAN and VideoLabs
 *
 * Authors: Steve Lhomme <robux4@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <vlc_filter.h>
#include <vlc_picture.h>

#include <assert.h>

#define COBJMACROS
#include <d3d11.h>

#include "d3d11_filters.h"
typedef picture_sys_d3d11_t VA_PICSYS;
#include "../../codec/avcodec/va_surface.h"

static vlc_mutex_t inst_lock = VLC_STATIC_MUTEX;
static d3d11_device_t device = { .context_mutex = INVALID_HANDLE_VALUE };
static size_t instances = 0;

void D3D11_FilterHoldInstance(filter_t *filter, d3d11_device_t *out, D3D11_TEXTURE2D_DESC *dstDesc)
{
    *out = (d3d11_device_t) { .context_mutex = INVALID_HANDLE_VALUE };
    picture_t *pic = filter_NewPicture(filter);
    if (!pic)
        return;

    picture_sys_d3d11_t *p_sys = ActivePictureSys(pic);

    vlc_mutex_lock(&inst_lock);
    if (p_sys)
    {
        out->d3dcontext = p_sys->context;
        ID3D11DeviceContext_GetDevice(out->d3dcontext, &out->d3ddevice);

        UINT dataSize = sizeof(out->context_mutex);
        HRESULT hr = ID3D11DeviceContext_GetPrivateData(out->d3dcontext, &GUID_CONTEXT_MUTEX,
                                                        &dataSize, &out->context_mutex);
        if (FAILED(hr) || dataSize != sizeof(out->context_mutex))
        {
            msg_Warn(filter, "No mutex found to lock the decoder");
            out->context_mutex = INVALID_HANDLE_VALUE;
        }

        ID3D11Device_Release(out->d3ddevice);
        if (device.d3dcontext == NULL)
        {
            device = *out;
            instances++;
        }
        if (device.context_mutex == INVALID_HANDLE_VALUE)
            device.context_mutex = out->context_mutex;

        ID3D11Texture2D_GetDesc(p_sys->texture[KNOWN_DXGI_INDEX], dstDesc);
    }
    else
    {
        *out = device;
        if (device.d3dcontext != NULL)
            instances++;

        memset(dstDesc, 0, sizeof(*dstDesc));
        dstDesc->Format = DxgiFourccFormat( filter->fmt_in.video.i_chroma );
        if (dstDesc->Format == DXGI_FORMAT_UNKNOWN)
            switch (filter->fmt_in.video.i_chroma)
            {
            case VLC_CODEC_D3D11_OPAQUE:      dstDesc->Format = DXGI_FORMAT_NV12; break;
            case VLC_CODEC_D3D11_OPAQUE_10B:  dstDesc->Format = DXGI_FORMAT_P010; break;
            case VLC_CODEC_D3D11_OPAQUE_BGRA: dstDesc->Format = DXGI_FORMAT_B8G8R8A8_UNORM; break;
            case VLC_CODEC_D3D11_OPAQUE_RGBA: dstDesc->Format = DXGI_FORMAT_R8G8B8A8_UNORM; break;
            default: break;
            }
        dstDesc->Width  = filter->fmt_out.video.i_width;
        dstDesc->Height = filter->fmt_out.video.i_height;
    }

    out->owner = false;
    if (unlikely(out->d3dcontext == NULL))
        msg_Warn(filter, "no context available");
    else
    {
        ID3D11DeviceContext_AddRef(out->d3dcontext);
        ID3D11Device_AddRef(out->d3ddevice);
        D3D11_GetDriverVersion(filter, out);
    }

    vlc_mutex_unlock(&inst_lock);

    picture_Release(pic);
}

void D3D11_FilterReleaseInstance(d3d11_device_t *d3d_dev)
{
    vlc_mutex_lock(&inst_lock);
    if (d3d_dev->d3dcontext && d3d_dev->d3dcontext == device.d3dcontext)
    {
        assert(instances != 0);
        if (--instances == 0)
            device.d3dcontext = NULL;
    }
    D3D11_ReleaseDevice(d3d_dev);
    vlc_mutex_unlock(&inst_lock);
}
