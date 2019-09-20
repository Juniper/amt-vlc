/*****************************************************************************
 * vaapi.c: VAAPI helpers for the libavcodec decoder
 *****************************************************************************
 * Copyright (C) 2017 VLC authors and VideoLAN
 * Copyright (C) 2009-2010 Laurent Aimar
 * Copyright (C) 2012-2014 Rémi Denis-Courmont
 *
 * Authors: Laurent Aimar <fenrir_AT_ videolan _DOT_ org>
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

#include <assert.h>

#include <vlc_common.h>
#include <vlc_plugin.h>
#include <vlc_fourcc.h>
#include <vlc_picture.h>
#include <vlc_picture_pool.h>

#ifdef VLC_VA_BACKEND_DRM
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <vlc_fs.h>
# include <va/va_drm.h>
#endif
#include <libavcodec/avcodec.h>
#include <libavcodec/vaapi.h>

#include "avcodec.h"
#include "va.h"
#include "../../hw/vaapi/vlc_vaapi.h"

struct vlc_va_sys_t
{
    vlc_decoder_device *dec_device;
    struct vaapi_context hw_ctx;
};

static int GetVaProfile(const AVCodecContext *ctx, const es_format_t *fmt,
                        VAProfile *va_profile, int *vlc_chroma,
                        unsigned *pic_count)
{
    VAProfile i_profile;
    unsigned count = 3;
    int i_vlc_chroma = VLC_CODEC_VAAPI_420;

    switch(ctx->codec_id)
    {
    case AV_CODEC_ID_MPEG1VIDEO:
    case AV_CODEC_ID_MPEG2VIDEO:
        i_profile = VAProfileMPEG2Main;
        count = 4;
        break;
    case AV_CODEC_ID_MPEG4:
        i_profile = VAProfileMPEG4AdvancedSimple;
        break;
    case AV_CODEC_ID_WMV3:
        i_profile = VAProfileVC1Main;
        break;
    case AV_CODEC_ID_VC1:
        i_profile = VAProfileVC1Advanced;
        break;
    case AV_CODEC_ID_H264:
        i_profile = VAProfileH264High;
        count = 18;
        break;
    case AV_CODEC_ID_HEVC:
        if (fmt->i_profile == FF_PROFILE_HEVC_MAIN)
            i_profile = VAProfileHEVCMain;
        else if (fmt->i_profile == FF_PROFILE_HEVC_MAIN_10)
        {
            i_profile = VAProfileHEVCMain10;
            i_vlc_chroma = VLC_CODEC_VAAPI_420_10BPP;
        }
        else
            return VLC_EGENERIC;
        count = 18;
        break;
    case AV_CODEC_ID_VP8:
        i_profile = VAProfileVP8Version0_3;
        count = 5;
        break;
    case AV_CODEC_ID_VP9:
        if (ctx->profile == FF_PROFILE_VP9_0)
            i_profile = VAProfileVP9Profile0;
#if VA_CHECK_VERSION( 0, 39, 0 )
        else if (ctx->profile == FF_PROFILE_VP9_2)
        {
            i_profile = VAProfileVP9Profile2;
            i_vlc_chroma = VLC_CODEC_VAAPI_420_10BPP;
        }
#endif
        else
            return VLC_EGENERIC;
        count = 10;
        break;
    default:
        return VLC_EGENERIC;
    }

    *va_profile = i_profile;
    *pic_count = count + ctx->thread_count;
    *vlc_chroma = i_vlc_chroma;
    return VLC_SUCCESS;
}

static int Get(vlc_va_t *va, picture_t *pic, uint8_t **data)
{
    (void) va;

    vlc_vaapi_PicAttachContext(pic);
    *data = (void *) (uintptr_t) vlc_vaapi_PicGetSurface(pic);

    return VLC_SUCCESS;
}

static void Delete(vlc_va_t *va)
{
    vlc_va_sys_t *sys = va->sys;
    vlc_object_t *o = VLC_OBJECT(va);

    vlc_vaapi_DestroyContext(o, sys->hw_ctx.display, sys->hw_ctx.context_id);
    vlc_vaapi_DestroyConfig(o, sys->hw_ctx.display, sys->hw_ctx.config_id);
    vlc_decoder_device_Release(sys->dec_device);
    free(sys);
}

static const struct vlc_va_operations ops = { Get, Delete, };

static int Create(vlc_va_t *va, AVCodecContext *ctx, enum PixelFormat pix_fmt,
                  const es_format_t *fmt, void *p_sys)
{
    if (pix_fmt != AV_PIX_FMT_VAAPI_VLD || p_sys == NULL)
        return VLC_EGENERIC;

    vlc_va_sys_t *sys = malloc(sizeof *sys);
    if (unlikely(sys == NULL))
        return VLC_ENOMEM;
    memset(sys, 0, sizeof (*sys));

    vlc_object_t *o = VLC_OBJECT(va);

    int ret = VLC_EGENERIC;

    /* The picture must be allocated by the vout */
    VADisplay va_dpy;
    vlc_decoder_device *dec_device =
        vlc_vaapi_PicSysHoldInstance(p_sys, &va_dpy);

    VASurfaceID *render_targets;
    unsigned num_render_targets =
        vlc_vaapi_PicSysGetRenderTargets(p_sys, &render_targets);
    if (num_render_targets == 0)
        goto error;

    VAProfile i_profile;
    unsigned count;
    int i_vlc_chroma;
    if (GetVaProfile(ctx, fmt, &i_profile, &i_vlc_chroma, &count) != VLC_SUCCESS)
        goto error;

    /* */
    sys->dec_device = dec_device;
    sys->hw_ctx.display = va_dpy;
    sys->hw_ctx.config_id = VA_INVALID_ID;
    sys->hw_ctx.context_id = VA_INVALID_ID;

    sys->hw_ctx.config_id =
        vlc_vaapi_CreateConfigChecked(o, sys->hw_ctx.display, i_profile,
                                      VAEntrypointVLD, i_vlc_chroma);
    if (sys->hw_ctx.config_id == VA_INVALID_ID)
        goto error;

    /* Create a context */
    sys->hw_ctx.context_id =
        vlc_vaapi_CreateContext(o, sys->hw_ctx.display, sys->hw_ctx.config_id,
                                ctx->coded_width, ctx->coded_height, VA_PROGRESSIVE,
                                render_targets, num_render_targets);
    if (sys->hw_ctx.context_id == VA_INVALID_ID)
        goto error;

    msg_Info(va, "Using %s", vaQueryVendorString(sys->hw_ctx.display));

    ctx->hwaccel_context = &sys->hw_ctx;
    va->sys = sys;
    va->ops = &ops;
    return VLC_SUCCESS;

error:
    if (sys->hw_ctx.context_id != VA_INVALID_ID)
        vlc_vaapi_DestroyContext(o, sys->hw_ctx.display, sys->hw_ctx.context_id);
    if (sys->hw_ctx.config_id != VA_INVALID_ID)
        vlc_vaapi_DestroyConfig(o, sys->hw_ctx.display, sys->hw_ctx.config_id);
    free(sys);
    vlc_decoder_device_Release(dec_device);
    return ret;
}

vlc_module_begin ()
    set_description( N_("VA-API video decoder") )
    set_va_callback( Create, 100 )
    add_shortcut( "vaapi" )
    set_category( CAT_INPUT )
    set_subcategory( SUBCAT_INPUT_VCODEC )
vlc_module_end ()
