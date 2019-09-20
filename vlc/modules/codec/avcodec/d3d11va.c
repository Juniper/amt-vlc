/*****************************************************************************
 * d3d11va.c: Direct3D11 Video Acceleration decoder
 *****************************************************************************
 * Copyright © 2009 Geoffroy Couprie
 * Copyright © 2009 Laurent Aimar
 * Copyright © 2015 Steve Lhomme
 * Copyright © 2015 VideoLabs
 *
 * Authors: Geoffroy Couprie <geal@videolan.org>
 *          Laurent Aimar <fenrir _AT_ videolan _DOT_ org>
 *          Steve Lhomme <robux4@gmail.com>
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

/**
  * See https://msdn.microsoft.com/en-us/library/windows/desktop/hh162912%28v=vs.85%29.aspx
  **/
#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

# undef WINAPI_FAMILY
# define WINAPI_FAMILY WINAPI_FAMILY_DESKTOP_APP

#include <assert.h>

#include <vlc_common.h>
#include <vlc_picture.h>
#include <vlc_plugin.h>
#include <vlc_charset.h>
#include <vlc_codec.h>

#define COBJMACROS
#include <initguid.h>
#include <d3d11.h>
#include <libavcodec/d3d11va.h>

#include "../../video_chroma/d3d11_fmt.h"

typedef picture_sys_d3d11_t VA_PICSYS;
#include "va_surface.h"

#include "directx_va.h"

static int Open(vlc_va_t *, AVCodecContext *, enum PixelFormat,
                const es_format_t *, void *);

vlc_module_begin()
    set_description(N_("Direct3D11 Video Acceleration"))
    set_category(CAT_INPUT)
    set_subcategory(SUBCAT_INPUT_VCODEC)
    set_va_callback(Open, 110)
vlc_module_end()

/*
 * In this mode libavcodec doesn't need the whole array on texture on startup
 * So we get the surfaces from the decoder pool when needed. We don't need to
 * extract the decoded surface into the decoder picture anymore.
 */
#define D3D11_DIRECT_DECODE  LIBAVCODEC_VERSION_CHECK( 57, 30, 3, 72, 101 )

#include <initguid.h> /* must be last included to not redefine existing GUIDs */

/* dxva2api.h GUIDs: http://msdn.microsoft.com/en-us/library/windows/desktop/ms697067(v=vs100).aspx
 * assume that they are declared in dxva2api.h */
#define MS_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8)

#ifdef __MINGW32__
# include <_mingw.h>

# if !defined(__MINGW64_VERSION_MAJOR)
#  undef MS_GUID
#  define MS_GUID DEFINE_GUID /* dxva2api.h fails to declare those, redefine as static */
#  define DXVA2_E_NEW_VIDEO_DEVICE MAKE_HRESULT(1, 4, 4097)
# else
#  include <dxva.h>
# endif

#endif /* __MINGW32__ */

DEFINE_GUID(DXVA_Intel_H264_NoFGT_ClearVideo,       0x604F8E68, 0x4951, 0x4c54, 0x88, 0xFE, 0xAB, 0xD2, 0x5C, 0x15, 0xB3, 0xD6);

DEFINE_GUID(DXVA2_NoEncrypt,                        0x1b81bed0, 0xa0c7, 0x11d3, 0xb9, 0x84, 0x00, 0xc0, 0x4f, 0x2e, 0x73, 0xc5);

struct vlc_va_sys_t
{
    UINT                         totalTextureSlices;
    unsigned                     textureWidth;
    unsigned                     textureHeight;

    d3d11_handle_t               hd3d;
    d3d11_device_t               d3d_dev;

    /* Video service */
    DXGI_FORMAT                  render;

    /* pool */
    picture_t                    *extern_pics[MAX_SURFACE_COUNT];

    /* Video decoder */
    D3D11_VIDEO_DECODER_CONFIG   cfg;
    GUID                         decoder_guid;
    ID3D11VideoDevice            *d3ddec;

    /* avcodec internals */
    struct AVD3D11VAContext      hw;

    /* pool */
    va_pool_t                     va_pool;
    ID3D11VideoDecoderOutputView *hw_surface[MAX_SURFACE_COUNT];

    ID3D11ShaderResourceView     *renderSrc[MAX_SURFACE_COUNT * D3D11_MAX_SHADER_VIEW];
};

/* */
static int D3dCreateDevice(vlc_va_t *);
static void D3dDestroyDevice(vlc_va_t *);

static int DxGetInputList(vlc_va_t *, input_list_t *);
static int DxSetupOutput(vlc_va_t *, const GUID *, const video_format_t *);

static int DxCreateDecoderSurfaces(vlc_va_t *, int codec_id,
                                   const video_format_t *fmt, unsigned surface_count);
static void DxDestroySurfaces(vlc_va_sys_t *);

static void SetupAVCodecContext(vlc_va_sys_t *sys, unsigned surfaces)
{
    sys->hw.cfg = &sys->cfg;
    sys->hw.surface_count = surfaces;
    sys->hw.surface = sys->hw_surface;
    sys->hw.context_mutex = sys->d3d_dev.context_mutex;

    if (IsEqualGUID(&sys->decoder_guid, &DXVA_Intel_H264_NoFGT_ClearVideo))
        sys->hw.workaround |= FF_DXVA2_WORKAROUND_INTEL_CLEARVIDEO;
}

static void d3d11_pic_context_destroy(struct picture_context_t *opaque)
{
    struct va_pic_context *pic_ctx = (struct va_pic_context*)opaque;
    if (pic_ctx->va_surface)
        va_surface_Release(pic_ctx->va_surface);
    ReleaseD3D11PictureSys(&pic_ctx->picsys);
    free(pic_ctx);
}

static struct va_pic_context *CreatePicContext(ID3D11VideoDecoderOutputView *,
                                               ID3D11Resource *,
                                               ID3D11DeviceContext *,
                                               UINT slice,
                                               ID3D11ShaderResourceView *resourceView[D3D11_MAX_SHADER_VIEW]);

static struct picture_context_t *d3d11_pic_context_copy(struct picture_context_t *ctx)
{
    struct va_pic_context *src_ctx = (struct va_pic_context*)ctx;
    struct va_pic_context *pic_ctx = CreatePicContext(src_ctx->picsys.decoder,
                                                      src_ctx->picsys.resource[0], src_ctx->picsys.context,
                                                      src_ctx->picsys.slice_index, src_ctx->picsys.renderSrc);
    if (unlikely(pic_ctx==NULL))
        return NULL;
    if (src_ctx->va_surface) {
        pic_ctx->va_surface = src_ctx->va_surface;
        va_surface_AddRef(pic_ctx->va_surface);
    }
    return &pic_ctx->s;
}

static struct va_pic_context *CreatePicContext(
                                                  ID3D11VideoDecoderOutputView *decoderSurface,
                                                  ID3D11Resource *p_resource,
                                                  ID3D11DeviceContext *context,
                                                  UINT slice,
                                                  ID3D11ShaderResourceView *renderSrc[D3D11_MAX_SHADER_VIEW])
{
    struct va_pic_context *pic_ctx = calloc(1, sizeof(*pic_ctx));
    if (unlikely(pic_ctx==NULL))
        goto done;
    pic_ctx->s.destroy = d3d11_pic_context_destroy;
    pic_ctx->s.copy    = d3d11_pic_context_copy;

    D3D11_TEXTURE2D_DESC txDesc;
    ID3D11Texture2D_GetDesc((ID3D11Texture2D*)p_resource, &txDesc);

    pic_ctx->picsys.formatTexture = txDesc.Format;
    pic_ctx->picsys.context = context;
    pic_ctx->picsys.slice_index = slice;
    pic_ctx->picsys.decoder = decoderSurface;
    for (int i=0;i<D3D11_MAX_SHADER_VIEW; i++)
    {
        pic_ctx->picsys.resource[i] = p_resource;
        pic_ctx->picsys.renderSrc[i] = renderSrc[i];
    }
    AcquireD3D11PictureSys(&pic_ctx->picsys);
    pic_ctx->picsys.context = context;
done:
    return pic_ctx;
}

static struct va_pic_context* NewSurfacePicContext(vlc_va_t *va, int surface_index, vlc_va_surface_t *va_surface)
{
    vlc_va_sys_t *sys = va->sys;
    ID3D11VideoDecoderOutputView *surface = sys->hw_surface[surface_index];
    ID3D11ShaderResourceView *resourceView[D3D11_MAX_SHADER_VIEW];
    ID3D11Resource *p_resource;
    ID3D11VideoDecoderOutputView_GetResource(surface, &p_resource);

    D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC viewDesc;
    ID3D11VideoDecoderOutputView_GetDesc(surface, &viewDesc);

    for (int i=0; i<D3D11_MAX_SHADER_VIEW; i++)
        resourceView[i] = sys->renderSrc[viewDesc.Texture2D.ArraySlice*D3D11_MAX_SHADER_VIEW + i];

    struct va_pic_context *pic_ctx = CreatePicContext(
                                                  surface,
                                                  p_resource,
                                                  sys->d3d_dev.d3dcontext,
                                                  viewDesc.Texture2D.ArraySlice,
                                                  resourceView);
    ID3D11Resource_Release(p_resource);
    if (unlikely(pic_ctx==NULL))
        return NULL;
    /* all the resources are acquired during surfaces init, and a second time in
     * CreatePicContext(), undo one of them otherwise we need an extra release
     * when the pool is emptied */
    ReleaseD3D11PictureSys(&pic_ctx->picsys);
    pic_ctx->va_surface = va_surface;
    return pic_ctx;
}

static int Get(vlc_va_t *va, picture_t *pic, uint8_t **data)
{
    vlc_va_sys_t *sys = va->sys;
    picture_sys_d3d11_t *p_sys = pic->p_sys;
#if D3D11_DIRECT_DECODE
    if (sys->va_pool.can_extern_pool)
    {
        /* copy the original picture_sys_d3d11_t in the va_pic_context */
        if (!pic->context)
        {
            assert(p_sys!=NULL);
            if (!p_sys->decoder)
            {
                HRESULT hr;
                D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC viewDesc;
                ZeroMemory(&viewDesc, sizeof(viewDesc));
                viewDesc.DecodeProfile = sys->decoder_guid;
                viewDesc.ViewDimension = D3D11_VDOV_DIMENSION_TEXTURE2D;
                viewDesc.Texture2D.ArraySlice = p_sys->slice_index;

                hr = ID3D11VideoDevice_CreateVideoDecoderOutputView( sys->d3ddec,
                                                                     p_sys->resource[KNOWN_DXGI_INDEX],
                                                                     &viewDesc,
                                                                     &p_sys->decoder );
                if (FAILED(hr))
                    return VLC_EGENERIC;
            }

            pic->context = (picture_context_t*)CreatePicContext(
                                             p_sys->decoder,
                                             p_sys->resource[KNOWN_DXGI_INDEX],
                                             sys->d3d_dev.d3dcontext,
                                             p_sys->slice_index,
                                             p_sys->renderSrc );
            if (pic->context == NULL)
                return VLC_EGENERIC;
        }
    }
    else
#endif
    {
        picture_context_t *pic_ctx = va_pool_Get(&sys->va_pool);
        if (unlikely(pic_ctx == NULL))
            return VLC_ENOITEM;
        pic->context = pic_ctx;
    }
    *data = (uint8_t*)((struct va_pic_context *)pic->context)->picsys.decoder;
    return VLC_SUCCESS;
}

static void Close(vlc_va_t *va)
{
    vlc_va_sys_t *sys = va->sys;

    va_pool_Close(va, &sys->va_pool);

    D3D11_Destroy( &sys->hd3d );

    free(sys);
}

static const struct vlc_va_operations ops = { Get, Close, };

static int Open(vlc_va_t *va, AVCodecContext *ctx, enum PixelFormat pix_fmt,
                const es_format_t *fmt, void *picsys)
{
    int err = VLC_EGENERIC;

    ctx->hwaccel_context = NULL;

    if (pix_fmt != AV_PIX_FMT_D3D11VA_VLD)
        return VLC_EGENERIC;

#if !VLC_WINSTORE_APP
    /* Allow using D3D11VA automatically starting from Windows 8.1 */
    if (!va->obj.force)
    {
        bool isWin81OrGreater = false;
        HMODULE hKernel32 = GetModuleHandle(TEXT("kernel32.dll"));
        if (likely(hKernel32 != NULL))
            isWin81OrGreater = GetProcAddress(hKernel32, "IsProcessCritical") != NULL;
        if (!isWin81OrGreater)
            return VLC_EGENERIC;
    }
#endif

    vlc_va_sys_t *sys = calloc(1, sizeof (*sys));
    if (unlikely(sys == NULL))
        return VLC_ENOMEM;

    err = D3D11_Create( va, &sys->hd3d, false );
    if (err != VLC_SUCCESS)
        goto error;

    va->sys = sys;

    sys->d3d_dev.d3ddevice = NULL;
    sys->render = DXGI_FORMAT_UNKNOWN;
    picture_sys_d3d11_t *p_sys = picsys;
    if ( p_sys != NULL && p_sys->context != NULL ) {
        HRESULT hr = D3D11_CreateDeviceExternal(va, p_sys->context, true, &sys->d3d_dev);
        if (FAILED(hr))
            msg_Err(va, "can't use the provided D3D11 context");
        else
        {
            if (sys->d3d_dev.context_mutex == INVALID_HANDLE_VALUE)
                msg_Warn(va, "No mutex found to lock the decoder");
            void *d3dvidctx = NULL;
            hr = ID3D11DeviceContext_QueryInterface(p_sys->context, &IID_ID3D11VideoContext, &d3dvidctx);
            if (FAILED(hr)) {
               msg_Err(va, "Could not Query ID3D11VideoContext Interface from the picture. (hr=0x%lX)", hr);
               D3D11_ReleaseDevice(&sys->d3d_dev);
            } else {
                sys->hw.video_context = d3dvidctx;

                assert(p_sys->texture[KNOWN_DXGI_INDEX] != NULL);
                D3D11_TEXTURE2D_DESC dstDesc;
                ID3D11Texture2D_GetDesc( p_sys->texture[KNOWN_DXGI_INDEX], &dstDesc);
                sys->render = dstDesc.Format;
                if (dstDesc.BindFlags & D3D11_BIND_DECODER)
                {
                    sys->textureWidth = dstDesc.Width;
                    sys->textureHeight = dstDesc.Height;
                    sys->totalTextureSlices = dstDesc.ArraySize;
                }
            }
        }
    }

    static const struct va_pool_cfg pool_cfg = {
        D3dCreateDevice,
        D3dDestroyDevice,
        DxCreateDecoderSurfaces,
        DxDestroySurfaces,
        SetupAVCodecContext,
        NewSurfacePicContext,
    };

    err = va_pool_Open(va, &pool_cfg, &sys->va_pool);
    if (err!=VLC_SUCCESS)
        goto error;

    video_format_t fmt_out;
    static const directx_sys_t dx_sys = { DxGetInputList, DxSetupOutput };
    err = directx_va_Setup(va, &dx_sys, ctx, fmt, isXboxHardware(sys->d3d_dev.d3ddevice), &fmt_out, &sys->hw.surface_count, &sys->decoder_guid);
    if (err != VLC_SUCCESS)
        goto error;

    err = va_pool_SetupDecoder(va, &sys->va_pool, ctx, &fmt_out, sys->hw.surface_count);
    if (err != VLC_SUCCESS)
        goto error;

    IDXGIAdapter *p_adapter = D3D11DeviceAdapter(sys->d3d_dev.d3ddevice);
    if (p_adapter) {
        DXGI_ADAPTER_DESC adapterDesc;
        if (SUCCEEDED(IDXGIAdapter_GetDesc(p_adapter, &adapterDesc))) {
            msg_Info(va, "Using D3D11VA (%ls, vendor %x(%s), device %x, revision %x)",
                        adapterDesc.Description,
                        adapterDesc.VendorId, DxgiVendorStr(adapterDesc.VendorId), adapterDesc.DeviceId, adapterDesc.Revision);
        }
        IDXGIAdapter_Release(p_adapter);
    }

    ctx->hwaccel_context = &sys->hw;

    va->ops = &ops;
    return VLC_SUCCESS;

error:
    Close(va);
    return err;
}

/**
 * It creates a Direct3D device usable for decoding
 */
static int D3dCreateDevice(vlc_va_t *va)
{
    vlc_va_sys_t *sys = va->sys;
    HRESULT hr;

    if (sys->d3d_dev.d3ddevice && sys->d3d_dev.d3dcontext) {
        msg_Dbg(va, "Reusing Direct3D11 device");
        ID3D11DeviceContext_AddRef(sys->d3d_dev.d3dcontext);
    }
    else
    {
#if VLC_WINSTORE_APP
        if (sys->d3d_dev.d3dcontext == NULL)
            sys->d3d_dev.d3dcontext = var_InheritInteger(va, "winrt-d3dcontext"); /* LEGACY */
#endif
        if (sys->d3d_dev.d3dcontext != NULL)
        {
            ID3D11DeviceContext_GetDevice(sys->d3d_dev.d3dcontext, &sys->d3d_dev.d3ddevice);
            ID3D11DeviceContext_AddRef(sys->d3d_dev.d3dcontext);
            ID3D11Device_Release(sys->d3d_dev.d3ddevice);
        }
        else
        {
            hr = D3D11_CreateDevice(va, &sys->hd3d, NULL, true, &sys->d3d_dev);
            if (FAILED(hr)) {
                msg_Err(va, "D3D11CreateDevice failed. (hr=0x%lX)", hr);
                return VLC_EGENERIC;
            }
        }
    }

    void *d3dvidctx = NULL;
    hr = ID3D11DeviceContext_QueryInterface(sys->d3d_dev.d3dcontext, &IID_ID3D11VideoContext, &d3dvidctx);
    if (FAILED(hr)) {
       msg_Err(va, "Could not Query ID3D11VideoContext Interface. (hr=0x%lX)", hr);
       ID3D11DeviceContext_Release(sys->d3d_dev.d3dcontext);
       ID3D11Device_Release(sys->d3d_dev.d3ddevice);
       return VLC_EGENERIC;
    }
    sys->hw.video_context = d3dvidctx;

    void *d3dviddev = NULL;
    hr = ID3D11Device_QueryInterface(sys->d3d_dev.d3ddevice, &IID_ID3D11VideoDevice, &d3dviddev);
    if (FAILED(hr)) {
       msg_Err(va, "Could not Query ID3D11VideoDevice Interface. (hr=0x%lX)", hr);
       ID3D11DeviceContext_Release(sys->d3d_dev.d3dcontext);
       ID3D11Device_Release(sys->d3d_dev.d3ddevice);
       ID3D11VideoContext_Release(sys->hw.video_context);
       return VLC_EGENERIC;
    }
    sys->d3ddec = d3dviddev;

    return VLC_SUCCESS;
}

/**
 * It releases a Direct3D device and its resources.
 */
static void D3dDestroyDevice(vlc_va_t *va)
{
    vlc_va_sys_t *sys = va->sys;
    if (sys->d3ddec)
        ID3D11VideoDevice_Release(sys->d3ddec);
    if (sys->hw.video_context)
        ID3D11VideoContext_Release(sys->hw.video_context);
    D3D11_ReleaseDevice( &sys->d3d_dev );
}

static void ReleaseInputList(input_list_t *p_list)
{
    free(p_list->list);
}

static int DxGetInputList(vlc_va_t *va, input_list_t *p_list)
{
    vlc_va_sys_t *sys = va->sys;
    HRESULT hr;

    UINT input_count = ID3D11VideoDevice_GetVideoDecoderProfileCount(sys->d3ddec);

    p_list->count = input_count;
    p_list->list = calloc(input_count, sizeof(*p_list->list));
    if (unlikely(p_list->list == NULL)) {
        return VLC_ENOMEM;
    }
    p_list->pf_release = ReleaseInputList;

    for (unsigned i = 0; i < input_count; i++) {
        hr = ID3D11VideoDevice_GetVideoDecoderProfile(sys->d3ddec, i, &p_list->list[i]);
        if (FAILED(hr))
        {
            msg_Err(va, "GetVideoDecoderProfile %d failed. (hr=0x%lX)", i, hr);
            ReleaseInputList(p_list);
            return VLC_EGENERIC;
        }
    }

    return VLC_SUCCESS;
}

extern const GUID DXVA_ModeHEVC_VLD_Main10;
extern const GUID DXVA_ModeVP9_VLD_10bit_Profile2;

static int DxSetupOutput(vlc_va_t *va, const GUID *input, const video_format_t *fmt)
{
    vlc_va_sys_t *sys = va->sys;
    HRESULT hr;

#ifndef NDEBUG
    BOOL bSupported = false;
    for (int format = 0; format < 188; format++) {
        hr = ID3D11VideoDevice_CheckVideoDecoderFormat(sys->d3ddec, input, format, &bSupported);
        if (SUCCEEDED(hr) && bSupported)
            msg_Dbg(va, "format %s is supported for output", DxgiFormatToStr(format));
    }
#endif

    IDXGIAdapter *pAdapter = D3D11DeviceAdapter(sys->d3d_dev.d3ddevice);
    if (!pAdapter)
        return VLC_EGENERIC;

    DXGI_ADAPTER_DESC adapterDesc;
    hr = IDXGIAdapter_GetDesc(pAdapter, &adapterDesc);
    IDXGIAdapter_Release(pAdapter);
    if (FAILED(hr))
        return VLC_EGENERIC;

    char *psz_decoder_name = directx_va_GetDecoderName(input);

    if (!directx_va_canUseDecoder(va, adapterDesc.VendorId, adapterDesc.DeviceId,
                                  input, sys->d3d_dev.WDDM.build))
    {
        msg_Warn(va, "GPU blacklisted for %s codec", psz_decoder_name);
        free(psz_decoder_name);
        return VLC_EGENERIC;
    }

    DXGI_FORMAT processorInput[5];
    int idx = 0;
    if ( sys->render != DXGI_FORMAT_UNKNOWN )
        processorInput[idx++] = sys->render;
    if (IsEqualGUID(input, &DXVA_ModeHEVC_VLD_Main10) || IsEqualGUID(input, &DXVA_ModeVP9_VLD_10bit_Profile2))
        processorInput[idx++] = DXGI_FORMAT_P010;
    processorInput[idx++] = DXGI_FORMAT_NV12;
    processorInput[idx++] = DXGI_FORMAT_420_OPAQUE;
    processorInput[idx++] = DXGI_FORMAT_UNKNOWN;

    /* */
    for (idx = 0; processorInput[idx] != DXGI_FORMAT_UNKNOWN; ++idx)
    {
        BOOL is_supported = false;
        hr = ID3D11VideoDevice_CheckVideoDecoderFormat(sys->d3ddec, input, processorInput[idx], &is_supported);
        if (SUCCEEDED(hr) && is_supported)
            msg_Dbg(va, "%s output is supported for decoder %s.", DxgiFormatToStr(processorInput[idx]), psz_decoder_name);
        else
        {
            msg_Dbg(va, "Can't get a decoder output format %s for decoder %s.", DxgiFormatToStr(processorInput[idx]), psz_decoder_name);
            continue;
        }

       // check if we can create render texture of that format
       // check the decoder can output to that format
       if ( !DeviceSupportsFormat(sys->d3d_dev.d3ddevice, processorInput[idx],
                                  D3D11_FORMAT_SUPPORT_SHADER_LOAD) )
       {
#ifndef ID3D11VideoContext_VideoProcessorBlt
           msg_Dbg(va, "Format %s needs a processor but is not supported",
                   DxgiFormatToStr(processorInput[idx]));
#else
           if ( !DeviceSupportsFormat(sys->d3d_dev.d3ddevice, processorInput[idx],
                                      D3D11_FORMAT_SUPPORT_VIDEO_PROCESSOR_INPUT) )
           {
               msg_Dbg(va, "Format %s needs a processor but is not available",
                       DxgiFormatToStr(processorInput[idx]));
               continue;
           }
#endif
        }

        D3D11_VIDEO_DECODER_DESC decoderDesc;
        ZeroMemory(&decoderDesc, sizeof(decoderDesc));
        decoderDesc.Guid = *input;
        decoderDesc.SampleWidth = fmt->i_width;
        decoderDesc.SampleHeight = fmt->i_height;
        decoderDesc.OutputFormat = processorInput[idx];

        UINT cfg_count = 0;
        hr = ID3D11VideoDevice_GetVideoDecoderConfigCount( sys->d3ddec, &decoderDesc, &cfg_count );
        if (FAILED(hr))
        {
            msg_Err( va, "Failed to get configuration for decoder %s. (hr=0x%lX)", psz_decoder_name, hr );
            continue;
        }
        if (cfg_count == 0) {
            msg_Err( va, "No decoder configuration possible for %s %dx%d",
                     DxgiFormatToStr(decoderDesc.OutputFormat),
                     decoderDesc.SampleWidth, decoderDesc.SampleHeight );
            continue;
        }

        msg_Dbg(va, "Using output format %s for decoder %s", DxgiFormatToStr(processorInput[idx]), psz_decoder_name);
        if ( sys->render == processorInput[idx] && sys->totalTextureSlices > 4)
        {
            if (CanUseVoutPool(&sys->d3d_dev, sys->totalTextureSlices))
                sys->va_pool.can_extern_pool = true;
            else
                msg_Warn( va, "use internal pool" );
        }
        sys->render = processorInput[idx];
        free(psz_decoder_name);
        return VLC_SUCCESS;
    }
    free(psz_decoder_name);

    msg_Dbg(va, "Output format from picture source not supported.");
    return VLC_EGENERIC;
}

static bool CanUseDecoderPadding(vlc_va_sys_t *sys)
{
    IDXGIAdapter *pAdapter = D3D11DeviceAdapter(sys->d3d_dev.d3ddevice);
    if (!pAdapter)
        return false;

    DXGI_ADAPTER_DESC adapterDesc;
    HRESULT hr = IDXGIAdapter_GetDesc(pAdapter, &adapterDesc);
    IDXGIAdapter_Release(pAdapter);
    if (FAILED(hr))
        return false;

    /* Qualcomm hardware has issues with textures and pixels that should not be
    * part of the decoded area */
    return adapterDesc.VendorId != GPU_MANUFACTURER_QUALCOMM;
}

/**
 * It creates a Direct3D11 decoder using the given video format
 */
static int DxCreateDecoderSurfaces(vlc_va_t *va, int codec_id,
                                   const video_format_t *fmt, unsigned surface_count)
{
    vlc_va_sys_t *sys = va->sys;
    HRESULT hr;

    ID3D10Multithread *pMultithread;
    hr = ID3D11Device_QueryInterface( sys->d3d_dev.d3ddevice, &IID_ID3D10Multithread, (void **)&pMultithread);
    if (SUCCEEDED(hr)) {
        ID3D10Multithread_SetMultithreadProtected(pMultithread, TRUE);
        ID3D10Multithread_Release(pMultithread);
    }

    if (!sys->textureWidth || !sys->textureHeight)
    {
        sys->textureWidth  = fmt->i_width;
        sys->textureHeight = fmt->i_height;
    }

    assert(sys->textureWidth  >= fmt->i_width);
    assert(sys->textureHeight >= fmt->i_height);

    if ((sys->textureWidth != fmt->i_width || sys->textureHeight != fmt->i_height) &&
        !CanUseDecoderPadding(sys))
    {
        msg_Dbg(va, "mismatching external pool sizes use the internal one %dx%d vs %dx%d",
                sys->textureWidth, sys->textureHeight, fmt->i_width, fmt->i_height);
        sys->va_pool.can_extern_pool = false;
        sys->textureWidth  = fmt->i_width;
        sys->textureHeight = fmt->i_height;
    }
    if (sys->totalTextureSlices && sys->totalTextureSlices < surface_count)
    {
        msg_Warn(va, "not enough decoding slices in the texture (%d/%d)",
                 sys->totalTextureSlices, surface_count);
        sys->va_pool.can_extern_pool = false;
    }
#if VLC_WINSTORE_APP
    /* On the Xbox 1/S, any decoding of H264 with one dimension over 2304
     * crashes totally the device */
    if (codec_id == AV_CODEC_ID_H264 &&
        (sys->textureWidth > 2304 || sys->textureHeight > 2304) &&
        isXboxHardware(sys->d3d_dev.d3ddevice))
    {
        msg_Warn(va, "%dx%d resolution not supported by your hardware", fmt->i_width, fmt->i_height);
        return VLC_EGENERIC;
    }
#endif

    D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC viewDesc;
    ZeroMemory(&viewDesc, sizeof(viewDesc));
    viewDesc.DecodeProfile = sys->decoder_guid;
    viewDesc.ViewDimension = D3D11_VDOV_DIMENSION_TEXTURE2D;

    const d3d_format_t *textureFmt = NULL;
    for (const d3d_format_t *output_format = GetRenderFormatList();
         output_format->name != NULL; ++output_format)
    {
        if (output_format->formatTexture == sys->render &&
                is_d3d11_opaque(output_format->fourcc))
        {
            textureFmt = output_format;
            break;
        }
    }
    if (unlikely(textureFmt==NULL))
    {
        msg_Dbg(va, "no hardware decoder matching %s", DxgiFormatToStr(sys->render));
        return VLC_EGENERIC;
    }

    if (sys->va_pool.can_extern_pool)
    {
#if !D3D11_DIRECT_DECODE
        size_t surface_idx;
        for (surface_idx = 0; surface_idx < surface_count; surface_idx++) {
            picture_t *pic = decoder_NewPicture( (decoder_t*) vlc_object_parent(va) );
            sys->extern_pics[surface_idx] = pic;
            sys->hw_surface[surface_idx] = NULL;
            if (pic==NULL)
            {
                msg_Warn(va, "not enough decoder pictures %d out of %d", surface_idx, surface_count);
                sys->va_pool.can_extern_pool = false;
                break;
            }

            D3D11_TEXTURE2D_DESC texDesc;
            picture_sys_d3d11_t * p_sys = pic->p_sys;
            ID3D11Texture2D_GetDesc(p_sys->texture[KNOWN_DXGI_INDEX], &texDesc);
            assert(texDesc.Format == sys->render);
            assert(texDesc.BindFlags & D3D11_BIND_DECODER);

#if !LIBAVCODEC_VERSION_CHECK( 57, 27, 2, 61, 102 )
            if (p_sys->slice_index != surface_idx)
            {
                msg_Warn(va, "d3d11va requires decoding slices to be the first in the texture (%d/%d)",
                         p_sys->slice_index, surface_idx);
                sys->va_pool.can_extern_pool = false;
                break;
            }
#endif

            viewDesc.Texture2D.ArraySlice = p_sys->slice_index;
            hr = ID3D11VideoDevice_CreateVideoDecoderOutputView( sys->d3ddec,
                                                                 p_sys->resource[KNOWN_DXGI_INDEX],
                                                                 &viewDesc,
                                                                 &p_sys->decoder );
            if (FAILED(hr)) {
                msg_Warn(va, "CreateVideoDecoderOutputView %d failed. (hr=0x%lX)", surface_idx, hr);
                sys->va_pool.can_extern_pool = false;
                break;
            }

            D3D11_AllocateResourceView(va, sys->d3d_dev.d3ddevice, textureFmt, pic->p_sys->texture, pic->p_sys->slice_index, pic->p_sys->renderSrc);

            sys->hw_surface[surface_idx] = p_sys->decoder;
        }

        if (!sys->va_pool.can_extern_pool)
        {
            for (size_t i = 0; i < surface_idx; ++i)
            {
                if (sys->hw_surface[i])
                {
                    ID3D11VideoDecoderOutputView_Release(sys->hw_surface[i]);
                    sys->hw_surface[i] = NULL;
                }
                if (sys->extern_pics[i])
                {
                    picture_sys_d3d11_t *p_sys = sys->extern_pics[i]->p_sys;
                    p_sys->decoder = NULL;
                    picture_Release(sys->extern_pics[i]);
                    sys->extern_pics[i] = NULL;
                }
            }
        }
        else
#endif
            msg_Dbg(va, "using external surface pool");
    }

    if (!sys->va_pool.can_extern_pool)
    {
        D3D11_TEXTURE2D_DESC texDesc;
        ZeroMemory(&texDesc, sizeof(texDesc));
        texDesc.Width = sys->textureWidth;
        texDesc.Height = sys->textureHeight;
        texDesc.MipLevels = 1;
        texDesc.Format = sys->render;
        texDesc.SampleDesc.Count = 1;
        texDesc.MiscFlags = 0;
        texDesc.ArraySize = surface_count;
        texDesc.Usage = D3D11_USAGE_DEFAULT;
        texDesc.BindFlags = D3D11_BIND_DECODER;
        texDesc.CPUAccessFlags = 0;

        if (DeviceSupportsFormat(sys->d3d_dev.d3ddevice, texDesc.Format, D3D11_FORMAT_SUPPORT_SHADER_LOAD))
            texDesc.BindFlags |= D3D11_BIND_SHADER_RESOURCE;

        ID3D11Texture2D *p_texture;
        hr = ID3D11Device_CreateTexture2D( sys->d3d_dev.d3ddevice, &texDesc, NULL, &p_texture );
        if (FAILED(hr)) {
            msg_Err(va, "CreateTexture2D %d failed. (hr=0x%lX)", surface_count, hr);
            return VLC_EGENERIC;
        }

        unsigned surface_idx;
        for (surface_idx = 0; surface_idx < surface_count; surface_idx++) {
            sys->extern_pics[surface_idx] = NULL;
            viewDesc.Texture2D.ArraySlice = surface_idx;

            hr = ID3D11VideoDevice_CreateVideoDecoderOutputView( sys->d3ddec,
                                                                 (ID3D11Resource*) p_texture,
                                                                 &viewDesc,
                                                                 &sys->hw_surface[surface_idx] );
            if (FAILED(hr)) {
                msg_Err(va, "CreateVideoDecoderOutputView %d failed. (hr=0x%lX)", surface_idx, hr);
                ID3D11Texture2D_Release(p_texture);
                return VLC_EGENERIC;
            }

            if (texDesc.BindFlags & D3D11_BIND_SHADER_RESOURCE)
            {
                ID3D11Texture2D *textures[D3D11_MAX_SHADER_VIEW] = {p_texture, p_texture, p_texture};
                D3D11_AllocateResourceView(va, sys->d3d_dev.d3ddevice, textureFmt, textures, surface_idx,
                                   &sys->renderSrc[surface_idx * D3D11_MAX_SHADER_VIEW]);
            }
        }
    }
    msg_Dbg(va, "ID3D11VideoDecoderOutputView succeed with %d surfaces (%dx%d)",
            surface_count, fmt->i_width, fmt->i_height);

    D3D11_VIDEO_DECODER_DESC decoderDesc;
    ZeroMemory(&decoderDesc, sizeof(decoderDesc));
    decoderDesc.Guid = sys->decoder_guid;
    decoderDesc.SampleWidth = fmt->i_width;
    decoderDesc.SampleHeight = fmt->i_height;
    decoderDesc.OutputFormat = sys->render;

    UINT cfg_count;
    hr = ID3D11VideoDevice_GetVideoDecoderConfigCount( sys->d3ddec, &decoderDesc, &cfg_count );
    if (FAILED(hr)) {
        msg_Err(va, "GetVideoDecoderConfigCount failed. (hr=0x%lX)", hr);
        return VLC_EGENERIC;
    }

    /* List all configurations available for the decoder */
    D3D11_VIDEO_DECODER_CONFIG cfg_list[cfg_count];
    for (unsigned i = 0; i < cfg_count; i++) {
        hr = ID3D11VideoDevice_GetVideoDecoderConfig( sys->d3ddec, &decoderDesc, i, &cfg_list[i] );
        if (FAILED(hr)) {
            msg_Err(va, "GetVideoDecoderConfig failed. (hr=0x%lX)", hr);
            return VLC_EGENERIC;
        }
    }

    msg_Dbg(va, "we got %d decoder configurations", cfg_count);

    /* Select the best decoder configuration */
    int cfg_score = 0;
    for (unsigned i = 0; i < cfg_count; i++) {
        const D3D11_VIDEO_DECODER_CONFIG *cfg = &cfg_list[i];

        /* */
        msg_Dbg(va, "configuration[%d] ConfigBitstreamRaw %d",
                i, cfg->ConfigBitstreamRaw);

        /* */
        int score;
        if (cfg->ConfigBitstreamRaw == 1)
            score = 1;
        else if (codec_id == AV_CODEC_ID_H264 && cfg->ConfigBitstreamRaw == 2)
            score = 2;
        else
            continue;
        if (IsEqualGUID(&cfg->guidConfigBitstreamEncryption, &DXVA2_NoEncrypt))
            score += 16;

        if (cfg_score < score) {
            sys->cfg = *cfg;
            cfg_score = score;
        }
    }
    if (cfg_score <= 0) {
        msg_Err(va, "Failed to find a supported decoder configuration");
        return VLC_EGENERIC;
    }

    /* Create the decoder */
    ID3D11VideoDecoder *decoder;
    hr = ID3D11VideoDevice_CreateVideoDecoder( sys->d3ddec, &decoderDesc, &sys->cfg, &decoder );
    if (FAILED(hr)) {
        msg_Err(va, "ID3D11VideoDevice_CreateVideoDecoder failed. (hr=0x%lX)", hr);
        sys->hw.decoder = NULL;
        return VLC_EGENERIC;
    }
    sys->hw.decoder = decoder;

    msg_Dbg(va, "DxCreateDecoderSurfaces succeed");
    return VLC_SUCCESS;
}

static void DxDestroySurfaces(vlc_va_sys_t *sys)
{
    if (sys->va_pool.surface_count && !sys->va_pool.can_extern_pool) {
        ID3D11Resource *p_texture;
        ID3D11VideoDecoderOutputView_GetResource( sys->hw_surface[0], &p_texture );
        ID3D11Resource_Release(p_texture);
        ID3D11Resource_Release(p_texture);
    }
    for (unsigned i = 0; i < sys->va_pool.surface_count; i++)
    {
        ID3D11VideoDecoderOutputView_Release( sys->hw_surface[i] );
        for (int j = 0; j < D3D11_MAX_SHADER_VIEW; j++)
        {
            if (sys->renderSrc[i*D3D11_MAX_SHADER_VIEW + j])
                ID3D11ShaderResourceView_Release(sys->renderSrc[i*D3D11_MAX_SHADER_VIEW + j]);
        }
    }
    if (sys->hw.decoder)
        ID3D11VideoDecoder_Release(sys->hw.decoder);
}
