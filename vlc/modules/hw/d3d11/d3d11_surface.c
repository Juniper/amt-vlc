/*****************************************************************************
 * d3d11_surface.c : D3D11 GPU surface conversion module for vlc
 *****************************************************************************
 * Copyright © 2015 VLC authors, VideoLAN and VideoLabs
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

/*****************************************************************************
 * Preamble
 *****************************************************************************/

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <vlc_common.h>
#include <vlc_filter.h>
#include <vlc_picture.h>
#include <vlc_modules.h>

#include <assert.h>

#include "../../video_chroma/copy.h"

#include <windows.h>
#define COBJMACROS
#include <d3d11.h>

#include "d3d11_filters.h"
#include "d3d11_processor.h"
#include "../../video_chroma/d3d11_fmt.h"

typedef picture_sys_d3d11_t VA_PICSYS;
#include "../../codec/avcodec/va_surface.h"

#ifdef ID3D11VideoContext_VideoProcessorBlt
#define CAN_PROCESSOR 1
#else
#define CAN_PROCESSOR 0
#endif

typedef struct
{
    copy_cache_t     cache;
    union {
        ID3D11Texture2D  *staging;
        ID3D11Resource   *staging_resource;
    };
    vlc_mutex_t      staging_lock;

#if CAN_PROCESSOR
    union {
        ID3D11Texture2D  *procOutTexture;
        ID3D11Resource   *procOutResource;
    };
    /* 420_OPAQUE processor */
    ID3D11VideoProcessorOutputView *processorOutput;
    d3d11_processor_t              d3d_proc;
#endif
    d3d11_device_t                 d3d_dev;

    /* CPU to GPU */
    filter_t   *filter;
    picture_t  *staging_pic;

    d3d11_handle_t  hd3d;
} filter_sys_t;

#if CAN_PROCESSOR
static int SetupProcessor(filter_t *p_filter, d3d11_device_t *d3d_dev,
                          DXGI_FORMAT srcFormat, DXGI_FORMAT dstFormat)
{
    filter_sys_t *sys = p_filter->p_sys;
    HRESULT hr;

    if (D3D11_CreateProcessor(p_filter, d3d_dev, D3D11_VIDEO_FRAME_FORMAT_PROGRESSIVE,
                              &p_filter->fmt_in.video, &p_filter->fmt_out.video, &sys->d3d_proc) != VLC_SUCCESS)
        goto error;

    UINT flags;
    /* shortcut for the rendering output */
    hr = ID3D11VideoProcessorEnumerator_CheckVideoProcessorFormat(sys->d3d_proc.procEnumerator, srcFormat, &flags);
    if (FAILED(hr) || !(flags & D3D11_VIDEO_PROCESSOR_FORMAT_SUPPORT_INPUT))
    {
        msg_Dbg(p_filter, "processor format %s not supported for output", DxgiFormatToStr(srcFormat));
        goto error;
    }
    hr = ID3D11VideoProcessorEnumerator_CheckVideoProcessorFormat(sys->d3d_proc.procEnumerator, dstFormat, &flags);
    if (FAILED(hr) || !(flags & D3D11_VIDEO_PROCESSOR_FORMAT_SUPPORT_OUTPUT))
    {
        msg_Dbg(p_filter, "processor format %s not supported for input", DxgiFormatToStr(dstFormat));
        goto error;
    }

    D3D11_VIDEO_PROCESSOR_CAPS processorCaps;
    hr = ID3D11VideoProcessorEnumerator_GetVideoProcessorCaps(sys->d3d_proc.procEnumerator, &processorCaps);
    for (UINT type = 0; type < processorCaps.RateConversionCapsCount; ++type)
    {
        hr = ID3D11VideoDevice_CreateVideoProcessor(sys->d3d_proc.d3dviddev,
                                                    sys->d3d_proc.procEnumerator, type, &sys->d3d_proc.videoProcessor);
        if (SUCCEEDED(hr))
        {
            D3D11_VIDEO_PROCESSOR_OUTPUT_VIEW_DESC outDesc = {
                .ViewDimension = D3D11_VPOV_DIMENSION_TEXTURE2D,
            };

            hr = ID3D11VideoDevice_CreateVideoProcessorOutputView(sys->d3d_proc.d3dviddev,
                                                             sys->procOutResource,
                                                             sys->d3d_proc.procEnumerator,
                                                             &outDesc,
                                                             &sys->processorOutput);
            if (FAILED(hr))
                msg_Err(p_filter, "Failed to create the processor output. (hr=0x%lX)", hr);
            else
            {
                return VLC_SUCCESS;
            }
        }
        if (sys->d3d_proc.videoProcessor)
        {
            ID3D11VideoProcessor_Release(sys->d3d_proc.videoProcessor);
            sys->d3d_proc.videoProcessor = NULL;
        }
    }

error:
    D3D11_ReleaseProcessor(&sys->d3d_proc);
    return VLC_EGENERIC;
}
#endif

static HRESULT can_map(filter_sys_t *sys, ID3D11DeviceContext *context)
{
    D3D11_MAPPED_SUBRESOURCE lock;
    HRESULT hr = ID3D11DeviceContext_Map(context, sys->staging_resource, 0,
                                         D3D11_MAP_READ, 0, &lock);
    ID3D11DeviceContext_Unmap(context, sys->staging_resource, 0);
    return hr;
}

static int assert_staging(filter_t *p_filter, picture_sys_d3d11_t *p_sys)
{
    filter_sys_t *sys = p_filter->p_sys;
    HRESULT hr;

    if (sys->staging)
        goto ok;

    D3D11_TEXTURE2D_DESC texDesc;
    ID3D11Texture2D_GetDesc( p_sys->texture[KNOWN_DXGI_INDEX], &texDesc);

    texDesc.MipLevels = 1;
    texDesc.SampleDesc.Count = 1;
    texDesc.MiscFlags = 0;
    texDesc.ArraySize = 1;
    texDesc.Usage = D3D11_USAGE_STAGING;
    texDesc.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
    texDesc.BindFlags = 0;

    d3d11_device_t d3d_dev = { .d3dcontext = p_sys->context };
    ID3D11DeviceContext_GetDevice(d3d_dev.d3dcontext, &d3d_dev.d3ddevice);
    sys->staging = NULL;
    hr = ID3D11Device_CreateTexture2D( d3d_dev.d3ddevice, &texDesc, NULL, &sys->staging);
    /* test if mapping the texture works ref #18746 */
    if (SUCCEEDED(hr) && FAILED(hr = can_map(sys, p_sys->context)))
        msg_Dbg(p_filter, "can't map default staging texture (hr=0x%lX)", hr);
#if CAN_PROCESSOR
    if (FAILED(hr)) {
        /* failed with the this format, try a different one */
        UINT supportFlags = D3D11_FORMAT_SUPPORT_SHADER_LOAD | D3D11_FORMAT_SUPPORT_VIDEO_PROCESSOR_OUTPUT;
        const d3d_format_t *new_fmt =
                FindD3D11Format( p_filter, &d3d_dev, 0, false, 0, 0, 0, false, supportFlags );
        if (new_fmt && texDesc.Format != new_fmt->formatTexture)
        {
            DXGI_FORMAT srcFormat = texDesc.Format;
            texDesc.Format = new_fmt->formatTexture;
            hr = ID3D11Device_CreateTexture2D( d3d_dev.d3ddevice, &texDesc, NULL, &sys->staging);
            if (SUCCEEDED(hr))
            {
                texDesc.Usage = D3D11_USAGE_DEFAULT;
                texDesc.CPUAccessFlags = 0;
                texDesc.BindFlags |= D3D11_BIND_RENDER_TARGET;
                hr = ID3D11Device_CreateTexture2D( d3d_dev.d3ddevice, &texDesc, NULL, &sys->procOutTexture);
                if (SUCCEEDED(hr) && SUCCEEDED(hr = can_map(sys, p_sys->context)))
                {
                    d3d11_device_t proc_dev = { .d3ddevice = d3d_dev.d3ddevice, .d3dcontext = p_sys->context };
                    if (SetupProcessor(p_filter, &proc_dev, srcFormat, new_fmt->formatTexture))
                    {
                        ID3D11Texture2D_Release(sys->procOutTexture);
                        ID3D11Texture2D_Release(sys->staging);
                        sys->staging = NULL;
                        hr = E_FAIL;
                    }
                    else
                        msg_Dbg(p_filter, "Using shader+processor format %s", new_fmt->name);
                }
                else
                {
                    msg_Dbg(p_filter, "can't create intermediate texture (hr=0x%lX)", hr);
                    ID3D11Texture2D_Release(sys->staging);
                    sys->staging = NULL;
                }
            }
        }
    }
#endif
    ID3D11Device_Release(d3d_dev.d3ddevice);
    if (FAILED(hr)) {
        msg_Err(p_filter, "Failed to create a %s staging texture to extract surface pixels (hr=0x%lX)", DxgiFormatToStr(texDesc.Format), hr );
        return VLC_EGENERIC;
    }
ok:
    return VLC_SUCCESS;
}

static void D3D11_YUY2(filter_t *p_filter, picture_t *src, picture_t *dst)
{
    if (src->context == NULL)
    {
        /* the previous stages creating a D3D11 picture should always fill the context */
        msg_Err(p_filter, "missing source context");
        return;
    }

    filter_sys_t *sys = p_filter->p_sys;
    picture_sys_d3d11_t *p_sys = &((struct va_pic_context*)src->context)->picsys;

    D3D11_TEXTURE2D_DESC desc;
    D3D11_MAPPED_SUBRESOURCE lock;

    vlc_mutex_lock(&sys->staging_lock);
    if (assert_staging(p_filter, p_sys) != VLC_SUCCESS)
    {
        vlc_mutex_unlock(&sys->staging_lock);
        return;
    }

    UINT srcSlice;
    D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC viewDesc;
    if (p_sys->decoder)
    {
        ID3D11VideoDecoderOutputView_GetDesc( p_sys->decoder, &viewDesc );
        srcSlice = viewDesc.Texture2D.ArraySlice;
    }
    else
        srcSlice = 0;
    ID3D11Resource *srcResource = p_sys->resource[KNOWN_DXGI_INDEX];

#if CAN_PROCESSOR
    if (sys->d3d_proc.procEnumerator)
    {
        HRESULT hr;
        assert(p_sys->slice_index == viewDesc.Texture2D.ArraySlice);
        if (FAILED( D3D11_Assert_ProcessorInput(p_filter, &sys->d3d_proc, p_sys) ))
            return;

        D3D11_VIDEO_PROCESSOR_STREAM stream = {
            .Enable = TRUE,
            .pInputSurface = p_sys->processorInput,
        };

        hr = ID3D11VideoContext_VideoProcessorBlt(sys->d3d_proc.d3dvidctx, sys->d3d_proc.videoProcessor,
                                                          sys->processorOutput,
                                                          0, 1, &stream);
        if (FAILED(hr))
        {
            msg_Err(p_filter, "Failed to process the video. (hr=0x%lX)", hr);
            vlc_mutex_unlock(&sys->staging_lock);
            return;
        }

        srcResource = sys->procOutResource;
        srcSlice = 0;
    }
#endif
    ID3D11DeviceContext_CopySubresourceRegion(p_sys->context, sys->staging_resource,
                                              0, 0, 0, 0,
                                              srcResource,
                                              srcSlice,
                                              NULL);

    HRESULT hr = ID3D11DeviceContext_Map(p_sys->context, sys->staging_resource,
                                         0, D3D11_MAP_READ, 0, &lock);
    if (FAILED(hr)) {
        msg_Err(p_filter, "Failed to map source surface. (hr=0x%lX)", hr);
        vlc_mutex_unlock(&sys->staging_lock);
        return;
    }

    if (dst->format.i_chroma == VLC_CODEC_I420)
        picture_SwapUV( dst );

    ID3D11Texture2D_GetDesc(sys->staging, &desc);

    if (desc.Format == DXGI_FORMAT_YUY2) {
        size_t chroma_pitch = (lock.RowPitch / 2);

        const size_t pitch[3] = {
            lock.RowPitch,
            chroma_pitch,
            chroma_pitch,
        };

        const uint8_t *plane[3] = {
            (uint8_t*)lock.pData,
            (uint8_t*)lock.pData + pitch[0] * desc.Height,
            (uint8_t*)lock.pData + pitch[0] * desc.Height
                                 + pitch[1] * desc.Height / 2,
        };

        Copy420_P_to_P(dst, plane, pitch,
                       src->format.i_visible_height + src->format.i_y_offset,
                       &sys->cache);
    } else if (desc.Format == DXGI_FORMAT_NV12 ||
               desc.Format == DXGI_FORMAT_P010) {
        const uint8_t *plane[2] = {
            lock.pData,
            (uint8_t*)lock.pData + lock.RowPitch * desc.Height
        };
        const size_t  pitch[2] = {
            lock.RowPitch,
            lock.RowPitch,
        };
        if (desc.Format == DXGI_FORMAT_NV12)
            Copy420_SP_to_P(dst, plane, pitch,
                            __MIN(desc.Height, src->format.i_y_offset + src->format.i_visible_height),
                            &sys->cache);
        else
            Copy420_16_SP_to_P(dst, plane, pitch,
                               __MIN(desc.Height, src->format.i_y_offset + src->format.i_visible_height),
                               6, &sys->cache);
        picture_SwapUV(dst);
    } else {
        msg_Err(p_filter, "Unsupported D3D11VA conversion from 0x%08X to YV12", desc.Format);
    }

    if (dst->format.i_chroma == VLC_CODEC_I420 || dst->format.i_chroma == VLC_CODEC_I420_10L)
        picture_SwapUV( dst );

    /* */
    ID3D11DeviceContext_Unmap(p_sys->context, sys->staging_resource, 0);
    vlc_mutex_unlock(&sys->staging_lock);
}

static void D3D11_NV12(filter_t *p_filter, picture_t *src, picture_t *dst)
{
    if (src->context == NULL)
    {
        /* the previous stages creating a D3D11 picture should always fill the context */
        msg_Err(p_filter, "missing source context");
        return;
    }

    filter_sys_t *sys = p_filter->p_sys;
    picture_sys_d3d11_t *p_sys = &((struct va_pic_context*)src->context)->picsys;

    D3D11_TEXTURE2D_DESC desc;
    D3D11_MAPPED_SUBRESOURCE lock;

    vlc_mutex_lock(&sys->staging_lock);
    if (assert_staging(p_filter, p_sys) != VLC_SUCCESS)
    {
        vlc_mutex_unlock(&sys->staging_lock);
        return;
    }

    UINT srcSlice;
    if (!p_sys->decoder)
        srcSlice = p_sys->slice_index;
    else
    {
        D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC viewDesc;
        ID3D11VideoDecoderOutputView_GetDesc( p_sys->decoder, &viewDesc );
        srcSlice = viewDesc.Texture2D.ArraySlice;
    }
    ID3D11Resource *srcResource = p_sys->resource[KNOWN_DXGI_INDEX];

#if CAN_PROCESSOR
    if (sys->d3d_proc.procEnumerator)
    {
        HRESULT hr;
        if (FAILED( D3D11_Assert_ProcessorInput(p_filter, &sys->d3d_proc, p_sys) ))
            return;

        D3D11_VIDEO_PROCESSOR_STREAM stream = {
            .Enable = TRUE,
            .pInputSurface = p_sys->processorInput,
        };

        hr = ID3D11VideoContext_VideoProcessorBlt(sys->d3d_proc.d3dvidctx, sys->d3d_proc.videoProcessor,
                                                          sys->processorOutput,
                                                          0, 1, &stream);
        if (FAILED(hr))
        {
            msg_Err(p_filter, "Failed to process the video. (hr=0x%lX)", hr);
            vlc_mutex_unlock(&sys->staging_lock);
            return;
        }

        srcResource = sys->procOutResource;
        srcSlice = 0;
    }
#endif
    ID3D11DeviceContext_CopySubresourceRegion(p_sys->context, sys->staging_resource,
                                              0, 0, 0, 0,
                                              srcResource,
                                              srcSlice,
                                              NULL);

    HRESULT hr = ID3D11DeviceContext_Map(p_sys->context, sys->staging_resource,
                                         0, D3D11_MAP_READ, 0, &lock);
    if (FAILED(hr)) {
        msg_Err(p_filter, "Failed to map source surface. (hr=0x%lX)", hr);
        vlc_mutex_unlock(&sys->staging_lock);
        return;
    }

    ID3D11Texture2D_GetDesc(sys->staging, &desc);

    if (desc.Format == DXGI_FORMAT_NV12 || desc.Format == DXGI_FORMAT_P010) {
        const uint8_t *plane[2] = {
            lock.pData,
            (uint8_t*)lock.pData + lock.RowPitch * desc.Height
        };
        size_t  pitch[2] = {
            lock.RowPitch,
            lock.RowPitch,
        };
        Copy420_SP_to_SP(dst, plane, pitch,
                         __MIN(desc.Height, src->format.i_y_offset + src->format.i_visible_height),
                         &sys->cache);
    } else {
        msg_Err(p_filter, "Unsupported D3D11VA conversion from 0x%08X to NV12", desc.Format);
    }

    /* */
    ID3D11DeviceContext_Unmap(p_sys->context, sys->staging_resource, 0);
    vlc_mutex_unlock(&sys->staging_lock);
}

static void D3D11_RGBA(filter_t *p_filter, picture_t *src, picture_t *dst)
{
    filter_sys_t *sys = p_filter->p_sys;
    assert(src->context != NULL);
    picture_sys_d3d11_t *p_sys = &((struct va_pic_context*)src->context)->picsys;

    D3D11_TEXTURE2D_DESC desc;
    D3D11_MAPPED_SUBRESOURCE lock;

    vlc_mutex_lock(&sys->staging_lock);
    if (assert_staging(p_filter, p_sys) != VLC_SUCCESS)
    {
        vlc_mutex_unlock(&sys->staging_lock);
        return;
    }

    ID3D11DeviceContext_CopySubresourceRegion(p_sys->context, sys->staging_resource,
                                              0, 0, 0, 0,
                                              p_sys->resource[KNOWN_DXGI_INDEX],
                                              p_sys->slice_index,
                                              NULL);

    HRESULT hr = ID3D11DeviceContext_Map(p_sys->context, sys->staging_resource,
                                         0, D3D11_MAP_READ, 0, &lock);
    if (FAILED(hr)) {
        msg_Err(p_filter, "Failed to map source surface. (hr=0x%lX)", hr);
        vlc_mutex_unlock(&sys->staging_lock);
        return;
    }

    ID3D11Texture2D_GetDesc(sys->staging, &desc);

    plane_t src_planes  = dst->p[0];
    src_planes.i_lines  = desc.Height;
    src_planes.i_pitch  = lock.RowPitch;
    src_planes.p_pixels = lock.pData;
    plane_CopyPixels( dst->p, &src_planes );

    /* */
    ID3D11DeviceContext_Unmap(p_sys->context,
                              p_sys->resource[KNOWN_DXGI_INDEX], p_sys->slice_index);
    vlc_mutex_unlock(&sys->staging_lock);
}

static void DestroyPicture(picture_t *picture)
{
    picture_sys_d3d11_t *p_sys = picture->p_sys;
    ReleaseD3D11PictureSys( p_sys );
    free(p_sys);
}

static void DeleteFilter( filter_t * p_filter )
{
    if( p_filter->p_module )
        module_unneed( p_filter, p_filter->p_module );

    es_format_Clean( &p_filter->fmt_in );
    es_format_Clean( &p_filter->fmt_out );

    vlc_object_delete(p_filter);
}

static picture_t *NewBuffer(filter_t *p_filter)
{
    filter_t *p_parent = p_filter->owner.sys;
    filter_sys_t *p_sys = p_parent->p_sys;
    return p_sys->staging_pic;
}

static filter_t *CreateCPUtoGPUFilter( vlc_object_t *p_this, const es_format_t *p_fmt_in,
                               vlc_fourcc_t dst_chroma )
{
    filter_t *p_filter;

    p_filter = vlc_object_create( p_this, sizeof(filter_t) );
    if (unlikely(p_filter == NULL))
        return NULL;

    static const struct filter_video_callbacks cbs = { NewBuffer };
    p_filter->b_allow_fmt_out_change = false;
    p_filter->owner.video = &cbs;
    p_filter->owner.sys = p_this;

    es_format_InitFromVideo( &p_filter->fmt_in,  &p_fmt_in->video );
    es_format_InitFromVideo( &p_filter->fmt_out, &p_fmt_in->video );
    p_filter->fmt_out.i_codec = p_filter->fmt_out.video.i_chroma = dst_chroma;
    p_filter->p_module = module_need( p_filter, "video converter", NULL, false );

    if( !p_filter->p_module )
    {
        msg_Dbg( p_filter, "no video converter found" );
        DeleteFilter( p_filter );
        return NULL;
    }

    return p_filter;
}

static void d3d11_pic_context_destroy(struct picture_context_t *opaque)
{
    struct va_pic_context *pic_ctx = (struct va_pic_context*)opaque;
    ReleaseD3D11PictureSys(&pic_ctx->picsys);
    free(pic_ctx);
}

static struct picture_context_t *d3d11_pic_context_copy(struct picture_context_t *ctx)
{
    struct va_pic_context *src_ctx = (struct va_pic_context*)ctx;
    struct va_pic_context *pic_ctx = calloc(1, sizeof(*pic_ctx));
    if (unlikely(pic_ctx==NULL))
        return NULL;
    pic_ctx->s.destroy = d3d11_pic_context_destroy;
    pic_ctx->s.copy    = d3d11_pic_context_copy;
    pic_ctx->picsys = src_ctx->picsys;
    AcquireD3D11PictureSys(&pic_ctx->picsys);
    return &pic_ctx->s;
}

static void NV12_D3D11(filter_t *p_filter, picture_t *src, picture_t *dst)
{
    filter_sys_t *sys = p_filter->p_sys;
    picture_sys_d3d11_t *p_sys = dst->p_sys;
    if (unlikely(p_sys==NULL))
    {
        /* the output filter configuration may have changed since the filter
         * was opened */
        return;
    }

    picture_sys_d3d11_t *p_staging_sys = sys->staging_pic->p_sys;

    D3D11_TEXTURE2D_DESC texDesc;
    ID3D11Texture2D_GetDesc( p_staging_sys->texture[KNOWN_DXGI_INDEX], &texDesc);

    D3D11_MAPPED_SUBRESOURCE lock;
    HRESULT hr = ID3D11DeviceContext_Map(p_sys->context, p_staging_sys->resource[KNOWN_DXGI_INDEX],
                                         0, D3D11_MAP_WRITE, 0, &lock);
    if (FAILED(hr)) {
        msg_Err(p_filter, "Failed to map source surface. (hr=0x%lX)", hr);
        return;
    }

    picture_UpdatePlanes(sys->staging_pic, lock.pData, lock.RowPitch);

    picture_Hold( src );
    sys->filter->pf_video_filter(sys->filter, src);

    ID3D11DeviceContext_Unmap(p_sys->context, p_staging_sys->resource[KNOWN_DXGI_INDEX], 0);

    D3D11_BOX copyBox = {
        .right = dst->format.i_width, .bottom = dst->format.i_height, .back = 1,
    };
    ID3D11DeviceContext_CopySubresourceRegion(p_sys->context,
                                              p_sys->resource[KNOWN_DXGI_INDEX],
                                              p_sys->slice_index,
                                              0, 0, 0,
                                              p_staging_sys->resource[KNOWN_DXGI_INDEX], 0,
                                              &copyBox);
    if (dst->context == NULL)
    {
        struct va_pic_context *pic_ctx = calloc(1, sizeof(*pic_ctx));
        if (likely(pic_ctx))
        {
            pic_ctx->s.destroy = d3d11_pic_context_destroy;
            pic_ctx->s.copy    = d3d11_pic_context_copy;
            pic_ctx->picsys = *p_sys;
            AcquireD3D11PictureSys(&pic_ctx->picsys);
            dst->context = &pic_ctx->s;
        }
    }
}

VIDEO_FILTER_WRAPPER (D3D11_NV12)
VIDEO_FILTER_WRAPPER (D3D11_YUY2)
VIDEO_FILTER_WRAPPER (D3D11_RGBA)
VIDEO_FILTER_WRAPPER (NV12_D3D11)

int D3D11OpenConverter( vlc_object_t *obj )
{
    filter_t *p_filter = (filter_t *)obj;

    if ( p_filter->fmt_in.video.i_chroma != VLC_CODEC_D3D11_OPAQUE &&
         p_filter->fmt_in.video.i_chroma != VLC_CODEC_D3D11_OPAQUE_10B &&
         p_filter->fmt_in.video.i_chroma != VLC_CODEC_D3D11_OPAQUE_RGBA &&
         p_filter->fmt_in.video.i_chroma != VLC_CODEC_D3D11_OPAQUE_BGRA )
        return VLC_EGENERIC;

    if ( p_filter->fmt_in.video.i_visible_height != p_filter->fmt_out.video.i_visible_height
         || p_filter->fmt_in.video.i_width != p_filter->fmt_out.video.i_width )
        return VLC_EGENERIC;

    uint8_t pixel_bytes = 1;
    switch( p_filter->fmt_out.video.i_chroma ) {
    case VLC_CODEC_I420:
    case VLC_CODEC_YV12:
        if( p_filter->fmt_in.video.i_chroma != VLC_CODEC_D3D11_OPAQUE )
            return VLC_EGENERIC;
        p_filter->pf_video_filter = D3D11_YUY2_Filter;
        break;
    case VLC_CODEC_I420_10L:
        if( p_filter->fmt_in.video.i_chroma != VLC_CODEC_D3D11_OPAQUE_10B )
            return VLC_EGENERIC;
        p_filter->pf_video_filter = D3D11_YUY2_Filter;
        pixel_bytes = 2;
        break;
    case VLC_CODEC_NV12:
        if( p_filter->fmt_in.video.i_chroma != VLC_CODEC_D3D11_OPAQUE )
            return VLC_EGENERIC;
        p_filter->pf_video_filter = D3D11_NV12_Filter;
        break;
    case VLC_CODEC_P010:
        if( p_filter->fmt_in.video.i_chroma != VLC_CODEC_D3D11_OPAQUE_10B )
            return VLC_EGENERIC;
        p_filter->pf_video_filter = D3D11_NV12_Filter;
        pixel_bytes = 2;
        break;
    case VLC_CODEC_RGBA:
        if( p_filter->fmt_in.video.i_chroma != VLC_CODEC_D3D11_OPAQUE_RGBA )
            return VLC_EGENERIC;
        p_filter->pf_video_filter = D3D11_RGBA_Filter;
        break;
    case VLC_CODEC_BGRA:
        if( p_filter->fmt_in.video.i_chroma != VLC_CODEC_D3D11_OPAQUE_BGRA )
            return VLC_EGENERIC;
        p_filter->pf_video_filter = D3D11_RGBA_Filter;
        break;
    default:
        return VLC_EGENERIC;
    }

    filter_sys_t *p_sys = vlc_obj_calloc(obj, 1, sizeof(filter_sys_t));
    if (!p_sys)
        return VLC_ENOMEM;

    if (CopyInitCache(&p_sys->cache, p_filter->fmt_in.video.i_width * pixel_bytes))
        return VLC_ENOMEM;

    if (D3D11_Create(p_filter, &p_sys->hd3d, false) != VLC_SUCCESS)
    {
        msg_Warn(p_filter, "cannot load d3d11.dll, aborting");
        CopyCleanCache(&p_sys->cache);
        return VLC_EGENERIC;
    }

    vlc_mutex_init(&p_sys->staging_lock);
    p_filter->p_sys = p_sys;
    return VLC_SUCCESS;
}

int D3D11OpenCPUConverter( vlc_object_t *obj )
{
    filter_t *p_filter = (filter_t *)obj;
    int err = VLC_EGENERIC;
    ID3D11Texture2D *texture = NULL;
    filter_t *p_cpu_filter = NULL;
    video_format_t fmt_staging;
    filter_sys_t *p_sys = NULL;

    if ( p_filter->fmt_out.video.i_chroma != VLC_CODEC_D3D11_OPAQUE
     &&  p_filter->fmt_out.video.i_chroma != VLC_CODEC_D3D11_OPAQUE_10B )
        return VLC_EGENERIC;

    if ( p_filter->fmt_in.video.i_height != p_filter->fmt_out.video.i_height
         || p_filter->fmt_in.video.i_width != p_filter->fmt_out.video.i_width )
        return VLC_EGENERIC;

    switch( p_filter->fmt_in.video.i_chroma ) {
    case VLC_CODEC_I420:
    case VLC_CODEC_I420_10L:
    case VLC_CODEC_YV12:
    case VLC_CODEC_NV12:
    case VLC_CODEC_P010:
        p_filter->pf_video_filter = NV12_D3D11_Filter;
        break;
    default:
        return VLC_EGENERIC;
    }

    d3d11_device_t d3d_dev;
    D3D11_TEXTURE2D_DESC texDesc;
    D3D11_FilterHoldInstance(p_filter, &d3d_dev, &texDesc);
    if (unlikely(!d3d_dev.d3dcontext))
    {
        msg_Dbg(p_filter, "D3D11 opaque without a texture");
        return VLC_EGENERIC;
    }

    video_format_Init(&fmt_staging, 0);

    vlc_fourcc_t d3d_fourcc = DxgiFormatFourcc(texDesc.Format);
    if (d3d_fourcc == 0)
        goto done;

    picture_resource_t res = {
        .pf_destroy = DestroyPicture,
    };
    picture_sys_d3d11_t *res_sys = calloc(1, sizeof(picture_sys_d3d11_t));
    if (res_sys == NULL) {
        err = VLC_ENOMEM;
        goto done;
    }
    res.p_sys = res_sys;
    res_sys->context = d3d_dev.d3dcontext;
    res_sys->formatTexture = texDesc.Format;

    video_format_Copy(&fmt_staging, &p_filter->fmt_out.video);
    fmt_staging.i_chroma = d3d_fourcc;
    fmt_staging.i_height = texDesc.Height;
    fmt_staging.i_width  = texDesc.Width;

    picture_t *p_dst = picture_NewFromResource(&fmt_staging, &res);
    if (p_dst == NULL) {
        msg_Err(p_filter, "Failed to map create the temporary picture.");
        goto done;
    }
    picture_sys_d3d11_t *p_dst_sys = p_dst->p_sys;
    picture_Setup(p_dst, &p_dst->format);

    texDesc.MipLevels = 1;
    texDesc.SampleDesc.Count = 1;
    texDesc.MiscFlags = 0;
    texDesc.ArraySize = 1;
    texDesc.Usage = D3D11_USAGE_STAGING;
    texDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    texDesc.BindFlags = 0;
    texDesc.Height = p_dst->format.i_height; /* make sure we match picture_Setup() */

    HRESULT hr = ID3D11Device_CreateTexture2D( d3d_dev.d3ddevice, &texDesc, NULL, &texture);
    if (FAILED(hr)) {
        msg_Err(p_filter, "Failed to create a %s staging texture to extract surface pixels (hr=0x%lX)", DxgiFormatToStr(texDesc.Format), hr );
        goto done;
    }

    res_sys->texture[KNOWN_DXGI_INDEX] = texture;
    ID3D11DeviceContext_AddRef(p_dst_sys->context);

    if ( p_filter->fmt_in.video.i_chroma != d3d_fourcc )
    {
        p_cpu_filter = CreateCPUtoGPUFilter(VLC_OBJECT(p_filter), &p_filter->fmt_in, p_dst->format.i_chroma);
        if (!p_cpu_filter)
            goto done;
    }

    p_sys = vlc_obj_calloc(obj, 1, sizeof(filter_sys_t));
    if (!p_sys) {
         err = VLC_ENOMEM;
         goto done;
    }

    if (D3D11_Create(p_filter, &p_sys->hd3d, false) != VLC_SUCCESS)
    {
        msg_Warn(p_filter, "cannot load d3d11.dll, aborting");
        goto done;
    }

    p_sys->filter = p_cpu_filter;
    p_sys->staging_pic = p_dst;
    p_filter->p_sys = p_sys;
    err = VLC_SUCCESS;

done:
    video_format_Clean(&fmt_staging);
    if (err != VLC_SUCCESS)
    {
        if (p_cpu_filter)
            DeleteFilter( p_cpu_filter );
        if (texture)
            ID3D11Texture2D_Release(texture);
        D3D11_FilterReleaseInstance(&d3d_dev);
    }
    else
    {
        p_sys->d3d_dev = d3d_dev;
    }
    return err;
}

void D3D11CloseConverter( vlc_object_t *obj )
{
    filter_t *p_filter = (filter_t *)obj;
    filter_sys_t *p_sys = p_filter->p_sys;
#if CAN_PROCESSOR
    if (p_sys->procOutTexture)
        ID3D11Texture2D_Release(p_sys->procOutTexture);
    D3D11_ReleaseProcessor( &p_sys->d3d_proc );
#endif
    CopyCleanCache(&p_sys->cache);
    vlc_mutex_destroy(&p_sys->staging_lock);
    if (p_sys->staging)
        ID3D11Texture2D_Release(p_sys->staging);
    D3D11_FilterReleaseInstance(&p_sys->d3d_dev);
    D3D11_Destroy(&p_sys->hd3d);
}

void D3D11CloseCPUConverter( vlc_object_t *obj )
{
    filter_t *p_filter = (filter_t *)obj;
    filter_sys_t *p_sys = p_filter->p_sys;
    DeleteFilter(p_sys->filter);
    picture_Release(p_sys->staging_pic);
    D3D11_Destroy(&p_sys->hd3d);
}
