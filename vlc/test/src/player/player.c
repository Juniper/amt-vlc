/*****************************************************************************
 * player.c: test vlc_player_t API
 *****************************************************************************
 * Copyright (C) 2018 VLC authors and VideoLAN
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

#include "../../libvlc/test.h"
#include "../lib/libvlc_internal.h"

#include <math.h>

#include <vlc_common.h>
#include <vlc_player.h>
#include <vlc_vector.h>

struct report_capabilities
{
    int old_caps;
    int new_caps;
};

struct report_position
{
    vlc_tick_t time;
    float pos;
};

struct report_track_list
{
    enum vlc_player_list_action action;
    struct vlc_player_track *track;
};

struct report_track_selection
{
    vlc_es_id_t *unselected_id;
    vlc_es_id_t *selected_id;
};

struct report_program_list
{
    enum vlc_player_list_action action;
    struct vlc_player_program *prgm;
};

struct report_program_selection
{
    int unselected_id;
    int selected_id;
};

struct report_chapter_selection
{
    size_t title_idx;
    size_t chapter_idx;
};

struct report_category_delay
{
    enum es_format_category_e cat;
    vlc_tick_t delay;
};

struct report_signal
{
    float quality;
    float strength;
};

struct report_vout
{
    enum vlc_player_vout_action action;
    vout_thread_t *vout;
    enum vlc_vout_order order;
    vlc_es_id_t *es_id;
};

struct report_media_subitems
{
    size_t count;
    input_item_t **items;
};

#define REPORT_LIST \
    X(input_item_t *, on_current_media_changed) \
    X(enum vlc_player_state, on_state_changed) \
    X(enum vlc_player_error, on_error_changed) \
    X(float, on_buffering_changed) \
    X(float, on_rate_changed) \
    X(struct report_capabilities, on_capabilities_changed) \
    X(struct report_position, on_position_changed) \
    X(vlc_tick_t, on_length_changed) \
    X(struct report_track_list, on_track_list_changed) \
    X(struct report_track_selection, on_track_selection_changed) \
    X(struct report_program_list, on_program_list_changed) \
    X(struct report_program_selection, on_program_selection_changed) \
    X(vlc_player_title_list *, on_titles_changed) \
    X(size_t, on_title_selection_changed) \
    X(struct report_chapter_selection, on_chapter_selection_changed) \
    X(struct report_category_delay, on_category_delay_changed) \
    X(bool, on_recording_changed) \
    X(struct report_signal, on_signal_changed) \
    X(struct input_stats_t, on_statistics_changed) \
    X(struct report_vout, on_vout_changed) \
    X(input_item_t *, on_media_meta_changed) \
    X(input_item_t *, on_media_epg_changed) \
    X(struct report_media_subitems, on_media_subitems_changed) \

#define X(type, name) typedef struct VLC_VECTOR(type) vec_##name;
REPORT_LIST
#undef X

#define X(type, name) vec_##name name;
struct reports
{
REPORT_LIST
};
#undef X

static inline void
reports_init(struct reports *report)
{
#define X(type, name) vlc_vector_init(&report->name);
REPORT_LIST
#undef X
}

struct media_params
{
    vlc_tick_t length;
    size_t track_count[DATA_ES];
    size_t program_count;

    bool video_packetized, audio_packetized, sub_packetized;

    size_t title_count;
    size_t chapter_count;

    bool can_seek;
    bool can_pause;
    bool error;
    bool null_names;
};

#define DEFAULT_MEDIA_PARAMS(param_length) { \
    .length = param_length, \
    .track_count = { \
        [VIDEO_ES] = 1, \
        [AUDIO_ES] = 1, \
        [SPU_ES] = 1, \
    }, \
    .program_count = 0, \
    .video_packetized = true, .audio_packetized = true, .sub_packetized = true,\
    .title_count = 0, \
    .chapter_count = 0, \
    .can_seek = true, \
    .can_pause = true, \
    .error = false, \
    .null_names = false, \
}

struct ctx
{
    libvlc_instance_t *vlc;
    vlc_player_t *player;
    vlc_player_listener_id *listener;
    struct VLC_VECTOR(input_item_t *) next_medias;
    struct VLC_VECTOR(input_item_t *) played_medias;

    size_t program_switch_count;
    size_t extra_start_count;
    struct media_params params;
    float rate;

    size_t last_state_idx;

    vlc_cond_t wait;
    struct reports report;
};

static struct ctx *
get_ctx(vlc_player_t *player, void *data)
{
    assert(data);
    struct ctx *ctx = data;
    assert(player == ctx->player);
    return ctx;
}

static input_item_t *
player_get_next(vlc_player_t *player, void *data)
{
    struct ctx *ctx = get_ctx(player, data);
    input_item_t *next_media;
    if (ctx->next_medias.size > 0)
    {
        next_media = ctx->next_medias.data[0];
        vlc_vector_remove(&ctx->next_medias, 0);

        input_item_Hold(next_media);
        bool success = vlc_vector_push(&ctx->played_medias, next_media);
        assert(success);
    }
    else
        next_media = NULL;
    return next_media;
}

#define VEC_PUSH(vec, item) do { \
    bool success = vlc_vector_push(&ctx->report.vec, item); \
    assert(success); \
    vlc_cond_signal(&ctx->wait); \
} while(0)

static void
player_on_current_media_changed(vlc_player_t *player,
                                input_item_t *new_media, void *data)
{
    struct ctx *ctx = get_ctx(player, data);
    if (new_media)
        input_item_Hold(new_media);
    VEC_PUSH(on_current_media_changed, new_media);
}

static void
player_on_state_changed(vlc_player_t *player, enum vlc_player_state state,
                        void *data)
{
    struct ctx *ctx = get_ctx(player, data);
    VEC_PUSH(on_state_changed, state);
}

static void
player_on_error_changed(vlc_player_t *player, enum vlc_player_error error,
                        void *data)
{
    struct ctx *ctx = get_ctx(player, data);
    VEC_PUSH(on_error_changed, error);
}

static void
player_on_buffering_changed(vlc_player_t *player, float new_buffering,
                            void *data)
{
    struct ctx *ctx = get_ctx(player, data);
    VEC_PUSH(on_buffering_changed, new_buffering);
}

static void
player_on_rate_changed(vlc_player_t *player, float new_rate, void *data)
{
    struct ctx *ctx = get_ctx(player, data);
    VEC_PUSH(on_rate_changed, new_rate);
}

static void
player_on_capabilities_changed(vlc_player_t *player, int old_caps, int new_caps,
                               void *data)
{
    struct ctx *ctx = get_ctx(player, data);
    struct report_capabilities report = {
        .old_caps = old_caps,
        .new_caps = new_caps,
    };
    VEC_PUSH(on_capabilities_changed, report);
}

static void
player_on_position_changed(vlc_player_t *player, vlc_tick_t time,
                           float pos, void *data)
{
    struct ctx *ctx = get_ctx(player, data);
    struct report_position report = {
        .time = time,
        .pos = pos,
    };
    VEC_PUSH(on_position_changed, report);
}

static void
player_on_length_changed(vlc_player_t *player, vlc_tick_t new_length,
                         void *data)
{
    struct ctx *ctx = get_ctx(player, data);
    VEC_PUSH(on_length_changed, new_length);
}

static void
player_on_track_list_changed(vlc_player_t *player,
                             enum vlc_player_list_action action,
                             const struct vlc_player_track *track,
                             void *data)
{
    struct ctx *ctx = get_ctx(player, data);
    struct report_track_list report = {
        .action = action,
        .track = vlc_player_track_Dup(track),
    };
    assert(report.track);
    VEC_PUSH(on_track_list_changed, report);
}

static void
player_on_track_selection_changed(vlc_player_t *player,
                                  vlc_es_id_t *unselected_id,
                                  vlc_es_id_t *selected_id, void *data)
{
    struct ctx *ctx = get_ctx(player, data);
    struct report_track_selection report = {
        .unselected_id = unselected_id ? vlc_es_id_Hold(unselected_id) : NULL,
        .selected_id = selected_id ? vlc_es_id_Hold(selected_id) : NULL,
    };
    assert(!!unselected_id == !!report.unselected_id);
    assert(!!selected_id == !!report.selected_id);
    VEC_PUSH(on_track_selection_changed, report);
}

static void
player_on_program_list_changed(vlc_player_t *player,
                               enum vlc_player_list_action action,
                               const struct vlc_player_program *prgm,
                               void *data)
{
    struct ctx *ctx = get_ctx(player, data);
    struct report_program_list report = {
        .action = action,
        .prgm = vlc_player_program_Dup(prgm)
    };
    assert(report.prgm);
    VEC_PUSH(on_program_list_changed, report);
}

static void
player_on_program_selection_changed(vlc_player_t *player,
                                    int unselected_id, int selected_id,
                                    void *data)
{
    struct ctx *ctx = get_ctx(player, data);
    struct report_program_selection report = {
        .unselected_id = unselected_id,
        .selected_id = selected_id,
    };
    VEC_PUSH(on_program_selection_changed, report);
}

static void
player_on_titles_changed(vlc_player_t *player,
                         vlc_player_title_list *titles, void *data)
{
    struct ctx *ctx = get_ctx(player, data);
    if (titles)
        vlc_player_title_list_Hold(titles);
    VEC_PUSH(on_titles_changed, titles);
}

static void
player_on_title_selection_changed(vlc_player_t *player,
                                  const struct vlc_player_title *new_title,
                                  size_t new_idx, void *data)
{
    struct ctx *ctx = get_ctx(player, data);
    VEC_PUSH(on_title_selection_changed, new_idx);
    (void) new_title;
}

static void
player_on_chapter_selection_changed(vlc_player_t *player,
                                    const struct vlc_player_title *title,
                                    size_t title_idx,
                                    const struct vlc_player_chapter *chapter,
                                    size_t chapter_idx, void *data)
{
    struct ctx *ctx = get_ctx(player, data);
    struct report_chapter_selection report = {
        .title_idx = title_idx,
        .chapter_idx = chapter_idx,
    };
    VEC_PUSH(on_chapter_selection_changed, report);
    (void) title;
    (void) chapter;
}

static void
player_on_category_delay_changed(vlc_player_t *player,
                                 enum es_format_category_e cat, vlc_tick_t new_delay,
                                 void *data)
{
    struct ctx *ctx = get_ctx(player, data);
    struct report_category_delay report = {
        .cat = cat,
        .delay = new_delay,
    };
    VEC_PUSH(on_category_delay_changed, report);
}

static void
player_on_recording_changed(vlc_player_t *player, bool recording, void *data)
{
    struct ctx *ctx = get_ctx(player, data);
    VEC_PUSH(on_recording_changed, recording);
}

static void
player_on_signal_changed(vlc_player_t *player,
                         float quality, float strength, void *data)
{
    struct ctx *ctx = get_ctx(player, data);
    struct report_signal report = {
        .quality = quality,
        .strength = strength,
    };
    VEC_PUSH(on_signal_changed, report);
}

static void
player_on_statistics_changed(vlc_player_t *player,
                        const struct input_stats_t *stats, void *data)
{
    struct ctx *ctx = get_ctx(player, data);
    struct input_stats_t dup = *stats;
    VEC_PUSH(on_statistics_changed, dup);
}

static void
player_on_vout_changed(vlc_player_t *player,
                       enum vlc_player_vout_action action,
                       vout_thread_t *vout, enum vlc_vout_order order,
                       vlc_es_id_t *es_id, void *data)
{
    struct ctx *ctx = get_ctx(player, data);
    struct report_vout report = {
        .action = action,
        .vout = vout_Hold(vout),
        .order = order,
        .es_id = vlc_es_id_Hold(es_id),
    };
    assert(report.es_id);
    VEC_PUSH(on_vout_changed, report);
}

static void
player_on_media_meta_changed(vlc_player_t *player, input_item_t *media,
                             void *data)
{
    struct ctx *ctx = get_ctx(player, data);
    input_item_Hold(media);
    VEC_PUSH(on_media_meta_changed, media);
}

static void
player_on_media_epg_changed(vlc_player_t *player, input_item_t *media,
                            void *data)
{
    struct ctx *ctx = get_ctx(player, data);
    input_item_Hold(media);
    VEC_PUSH(on_media_epg_changed, media);
}

static void
player_on_media_subitems_changed(vlc_player_t *player, input_item_t *media,
                           input_item_node_t *subitems, void *data)
{
    (void) media;
    struct ctx *ctx = get_ctx(player, data);

    struct report_media_subitems report = {
        .count = subitems->i_children,
        .items = vlc_alloc(subitems->i_children, sizeof(input_item_t)),
    };
    assert(report.items);
    for (int i = 0; i < subitems->i_children; ++i)
        report.items[i] = input_item_Hold(subitems->pp_children[i]->p_item);
    VEC_PUSH(on_media_subitems_changed, report);
}

#define VEC_LAST(vec) (vec)->data[(vec)->size - 1]
#define assert_position(ctx, report) do { \
    assert(fabs((report)->pos - (report)->time / (float) ctx->params.length) < 0.001); \
} while (0)

/* Wait for the next state event */
static inline void
wait_state(struct ctx *ctx, enum vlc_player_state state)
{
    vec_on_state_changed *vec = &ctx->report.on_state_changed;
    for (;;)
    {
        while (vec->size <= ctx->last_state_idx)
            vlc_player_CondWait(ctx->player, &ctx->wait);
        for (size_t i = ctx->last_state_idx; i < vec->size; ++i)
            if ((vec)->data[i] == state)
            {
                ctx->last_state_idx = i + 1;
                return;
            }
        ctx->last_state_idx = vec->size;
    }
}

#define assert_state(ctx, state) do { \
    vec_on_state_changed *vec = &ctx->report.on_state_changed; \
    assert(VEC_LAST(vec) == state); \
} while(0)

#define assert_normal_state(ctx) do { \
    vec_on_state_changed *vec = &ctx->report.on_state_changed; \
    assert(vec->size >= 4); \
    assert(vec->data[vec->size - 4] == VLC_PLAYER_STATE_STARTED); \
    assert(vec->data[vec->size - 3] == VLC_PLAYER_STATE_PLAYING); \
    assert(vec->data[vec->size - 2] == VLC_PLAYER_STATE_STOPPING); \
    assert(vec->data[vec->size - 1] == VLC_PLAYER_STATE_STOPPED); \
} while(0)

static void
ctx_reset(struct ctx *ctx)
{
#define FOREACH_VEC(item, vec) vlc_vector_foreach(item, &ctx->report.vec)
#define CLEAN_MEDIA_VEC(vec) do { \
    input_item_t *media; \
    FOREACH_VEC(media, vec) { \
        if (media) \
            input_item_Release(media); \
    } \
} while(0)


    CLEAN_MEDIA_VEC(on_current_media_changed);
    CLEAN_MEDIA_VEC(on_media_meta_changed);
    CLEAN_MEDIA_VEC(on_media_epg_changed);

    {
        struct report_track_list report;
        FOREACH_VEC(report, on_track_list_changed)
            vlc_player_track_Delete(report.track);
    }

    {
        struct report_track_selection report;
        FOREACH_VEC(report, on_track_selection_changed)
        {
            if (report.unselected_id)
                vlc_es_id_Release(report.unselected_id);
            if (report.selected_id)
                vlc_es_id_Release(report.selected_id);
        }
    }

    {
        struct report_program_list report;
        FOREACH_VEC(report, on_program_list_changed)
            vlc_player_program_Delete(report.prgm);
    }

    {
        vlc_player_title_list *titles;
        FOREACH_VEC(titles, on_titles_changed)
        {
            if (titles)
                vlc_player_title_list_Release(titles);
        }
    }

    {
        struct report_vout report;
        FOREACH_VEC(report, on_vout_changed)
        {
            vout_Release(report.vout);
            vlc_es_id_Release(report.es_id);
        }
    }

    {
        struct report_media_subitems report;
        FOREACH_VEC(report, on_media_subitems_changed)
        {
            for (size_t i = 0; i < report.count; ++i)
                input_item_Release(report.items[i]);
            free(report.items);
        }
    }
#undef CLEAN_MEDIA_VEC
#undef FOREACH_VEC

#define X(type, name) vlc_vector_clear(&ctx->report.name);
REPORT_LIST
#undef X

    input_item_t *media;
    vlc_vector_foreach(media, &ctx->next_medias)
    {
        assert(media);
        input_item_Release(media);
    }
    vlc_vector_clear(&ctx->next_medias);

    vlc_vector_foreach(media, &ctx->played_medias)
        if (media)
            input_item_Release(media);
    vlc_vector_clear(&ctx->played_medias);

    ctx->extra_start_count = 0;
    ctx->program_switch_count = 1;
    ctx->rate = 1.f;

    ctx->last_state_idx = 0;
};

static input_item_t *
create_mock_media(const char *name, const struct media_params *params)
{
    assert(params);
    char *url;
    int ret = asprintf(&url,
        "mock://video_track_count=%zu;audio_track_count=%zu;sub_track_count=%zu;"
        "program_count=%zu;video_packetized=%d;audio_packetized=%d;"
        "sub_packetized=%d;length=%"PRId64";title_count=%zu;chapter_count=%zu;"
        "can_seek=%d;can_pause=%d;error=%d;null_names=%d",
        params->track_count[VIDEO_ES], params->track_count[AUDIO_ES],
        params->track_count[SPU_ES], params->program_count,
        params->video_packetized, params->audio_packetized,
        params->sub_packetized, params->length, params->title_count,
        params->chapter_count, params->can_seek, params->can_pause,
        params->error, params->null_names);
    assert(ret != -1);

    input_item_t *item = input_item_New(url, name);
    assert(item);
    free(url);
    return item;
}

static void
player_set_current_mock_media(struct ctx *ctx, const char *name,
                              const struct media_params *params, bool ignored)
{
    input_item_t *media;
    if (name)
    {
        assert(params);

        media = create_mock_media(name, params);
        assert(media);

        ctx->params = *params;
        if (ctx->params.chapter_count > 0 && ctx->params.title_count == 0)
            ctx->params.title_count = 1;
        if (ctx->params.program_count == 0)
            ctx->params.program_count = 1;
    }
    else
        media = NULL;
    int ret = vlc_player_SetCurrentMedia(ctx->player, media);
    assert(ret == VLC_SUCCESS);

    if (ignored)
    {
        if (media)
            input_item_Release(media);
    }
    else
    {
        bool success = vlc_vector_push(&ctx->played_medias, media);
        assert(success);
    }
}

static void
player_set_next_mock_media(struct ctx *ctx, const char *name,
                           const struct media_params *params)
{
    if (vlc_player_GetCurrentMedia(ctx->player) == NULL)
    {
        assert(ctx->played_medias.size == 0);
        player_set_current_mock_media(ctx, name, params, false);
    }
    else
    {
        input_item_t *media = create_mock_media(name, params);
        assert(media);

        assert(ctx->played_medias.size > 0);
        bool success = vlc_vector_push(&ctx->next_medias, media);
        assert(success);
    }
}

static void
player_set_rate(struct ctx *ctx, float rate)
{
    vlc_player_ChangeRate(ctx->player, rate);
    ctx->rate = rate;
}

static void
player_start(struct ctx *ctx)
{
    int ret = vlc_player_Start(ctx->player);
    assert(ret == VLC_SUCCESS);
}

static void
test_end_prestop_rate(struct ctx *ctx)
{
    if (ctx->rate != 1.0f)
    {
        vec_on_rate_changed *vec = &ctx->report.on_rate_changed;
        while (vec->size == 0)
            vlc_player_CondWait(ctx->player, &ctx->wait);
        assert(vec->size > 0);
        assert(VEC_LAST(vec) == ctx->rate);
    }

}

static void
test_end_prestop_length(struct ctx *ctx)
{
    vlc_player_t *player = ctx->player;
    vec_on_length_changed *vec = &ctx->report.on_length_changed;
    while (vec->size != ctx->played_medias.size)
        vlc_player_CondWait(ctx->player, &ctx->wait);
    for (size_t i = 0; i < vec->size; ++i)
        assert(vec->data[i] == ctx->params.length);
    assert(ctx->params.length == vlc_player_GetLength(player));
}

static void
test_end_prestop_capabilities(struct ctx *ctx)
{
    vlc_player_t *player = ctx->player;
    vec_on_capabilities_changed *vec = &ctx->report.on_capabilities_changed;
    while (vec->size == 0)
        vlc_player_CondWait(ctx->player, &ctx->wait);
    int new_caps = VEC_LAST(vec).new_caps;
    assert(vlc_player_CanSeek(player) == ctx->params.can_seek
        && !!(new_caps & VLC_PLAYER_CAP_SEEK) == ctx->params.can_seek);
    assert(vlc_player_CanPause(player) == ctx->params.can_pause
        && !!(new_caps & VLC_PLAYER_CAP_PAUSE) == ctx->params.can_pause);
}

static void
test_end_prestop_buffering(struct ctx *ctx)
{
    vec_on_buffering_changed *vec = &ctx->report.on_buffering_changed;
    while (vec->size == 0 || VEC_LAST(vec) != 1.0f)
        vlc_player_CondWait(ctx->player, &ctx->wait);
    assert(vec->size >= 2);
    assert(vec->data[0] == 0.0f);
}


static void
test_end_poststop_state(struct ctx *ctx)
{
    vec_on_state_changed *vec = &ctx->report.on_state_changed;
    assert(vec->size > 1);
    assert(vec->data[0] == VLC_PLAYER_STATE_STARTED);
    assert(VEC_LAST(vec) == VLC_PLAYER_STATE_STOPPED);
}

static void
test_end_poststop_tracks(struct ctx *ctx)
{
    vec_on_track_list_changed *vec = &ctx->report.on_track_list_changed;
    struct {
        size_t added;
        size_t removed;
    } tracks[] = {
        [VIDEO_ES] = { 0, 0 },
        [AUDIO_ES] = { 0, 0 },
        [SPU_ES] = { 0, 0 },
    };
    struct report_track_list report;
    vlc_vector_foreach(report, vec)
    {
        assert(report.track->fmt.i_cat == VIDEO_ES
            || report.track->fmt.i_cat == AUDIO_ES
            || report.track->fmt.i_cat == SPU_ES);
        if (report.action == VLC_PLAYER_LIST_ADDED)
            tracks[report.track->fmt.i_cat].added++;
        else if (report.action == VLC_PLAYER_LIST_REMOVED)
            tracks[report.track->fmt.i_cat].removed++;
    }

    static const enum es_format_category_e cats[] = {
        VIDEO_ES, AUDIO_ES, SPU_ES,
    };
    for (size_t i = 0; i < ARRAY_SIZE(cats); ++i)
    {
        enum es_format_category_e cat = cats[i];

        assert(tracks[cat].added == tracks[cat].removed);

        /* The next check doesn't work if we selected new programs and started
         * more than one time */
        assert(ctx->program_switch_count == 1 || ctx->extra_start_count == 0);

        const size_t track_count =
            ctx->params.track_count[cat] * ctx->program_switch_count *
            (ctx->played_medias.size + ctx->extra_start_count);
        assert(tracks[cat].added == track_count);
    }
}

static void
test_end_poststop_programs(struct ctx *ctx)
{
    vec_on_program_list_changed *vec = &ctx->report.on_program_list_changed;
    size_t program_added = 0, program_removed = 0;
    struct report_program_list report;
    vlc_vector_foreach(report, vec)
    {
        if (report.action == VLC_PLAYER_LIST_ADDED)
            program_added++;
        else if (report.action == VLC_PLAYER_LIST_REMOVED)
            program_removed++;
    }

    assert(program_added == program_removed);
    size_t program_count = ctx->params.program_count *
        (ctx->played_medias.size + ctx->extra_start_count);
    assert(program_added == program_count);
}

static void
test_end_poststop_titles(struct ctx *ctx)
{
    if (!ctx->params.chapter_count && !ctx->params.title_count)
        return;

    vec_on_titles_changed *vec = &ctx->report.on_titles_changed;
    assert(vec->size == 2);
    assert(vec->data[0] != NULL);
    assert(vec->data[1] == NULL);

    vlc_player_title_list *titles = vec->data[0];
    size_t title_count = vlc_player_title_list_GetCount(titles);
    assert(title_count == ctx->params.title_count);

    for (size_t title_idx = 0; title_idx < title_count; ++title_idx)
    {
        const struct vlc_player_title *title =
            vlc_player_title_list_GetAt(titles, title_idx);
        assert(title);
        assert(title->name && title->name[strlen(title->name)] == 0);
        assert(title->chapter_count == ctx->params.chapter_count);
        assert(title->length == ctx->params.length);

        for (size_t chapter_idx = 0; chapter_idx < title->chapter_count;
             ++chapter_idx)
        {
            const struct vlc_player_chapter *chapter =
                &title->chapters[chapter_idx];
            assert(chapter->name && chapter->name[strlen(chapter->name)] == 0);
            assert(chapter->time < ctx->params.length);
            if (chapter_idx != 0)
                assert(chapter->time > 0);
        }
    }
}

static void
test_end_poststop_vouts(struct ctx *ctx)
{
    vec_on_vout_changed *vec = &ctx->report.on_vout_changed;

    size_t vout_started = 0, vout_stopped = 0;

    struct report_vout report;
    vlc_vector_foreach(report, vec)
    {
        if (report.action == VLC_PLAYER_VOUT_STARTED)
            vout_started++;
        else if (report.action == VLC_PLAYER_VOUT_STOPPED)
            vout_stopped++;
        else
            vlc_assert_unreachable();
    }
    assert(vout_started == vout_stopped);
}

static void
test_end_poststop_medias(struct ctx *ctx)
{
    vlc_player_t *player = ctx->player;
    vec_on_current_media_changed *vec = &ctx->report.on_current_media_changed;

    assert(vec->size > 0);
    assert(vlc_player_GetCurrentMedia(player) != NULL);
    assert(VEC_LAST(vec) == vlc_player_GetCurrentMedia(player));
    const size_t oldsize = vec->size;

    player_set_current_mock_media(ctx, NULL, NULL, false);

    while (vec->size == oldsize)
        vlc_player_CondWait(player, &ctx->wait);

    assert(vec->size == ctx->played_medias.size);
    for (size_t i  = 0; i < vec->size; ++i)
        assert(vec->data[i] == ctx->played_medias.data[i]);

    assert(VEC_LAST(vec) == NULL);
    assert(vlc_player_GetCurrentMedia(player) == NULL);
}

static void
test_prestop(struct ctx *ctx)
{
    test_end_prestop_rate(ctx);
    test_end_prestop_length(ctx);
    test_end_prestop_capabilities(ctx);
    test_end_prestop_buffering(ctx);
}

static void
test_end(struct ctx *ctx)
{
    vlc_player_t *player = ctx->player;

    /* Don't wait if we already stopped or waited for a stop */
    const bool wait_stopped =
        VEC_LAST(&ctx->report.on_state_changed) != VLC_PLAYER_STATE_STOPPED;
    /* Can be no-op */
    vlc_player_Stop(player);
    assert(vlc_player_GetCurrentMedia(player) != NULL);
    if (wait_stopped)
        wait_state(ctx, VLC_PLAYER_STATE_STOPPED);

    if (!ctx->params.error)
    {
        test_end_poststop_state(ctx);
        test_end_poststop_tracks(ctx);
        test_end_poststop_programs(ctx);
        test_end_poststop_titles(ctx);
        test_end_poststop_vouts(ctx);
    }
    test_end_poststop_medias(ctx);

    player_set_rate(ctx, 1.0f);
    vlc_player_SetStartPaused(player, false);

    ctx_reset(ctx);
}

static size_t
vec_on_program_list_get_action_count(vec_on_program_list_changed *vec,
                                    enum vlc_player_list_action action)
{
    size_t count = 0;
    struct report_program_list report;
    vlc_vector_foreach(report, vec)
        if (report.action == action)
            count++;
    return count;
}

static size_t
vec_on_program_selection_has_event(vec_on_program_selection_changed *vec,
                                   size_t from_idx,
                                   int unselected_id, int selected_id)
{
    assert(vec->size >= from_idx);
    bool has_unselected_id = false, has_selected_id = false;
    for (size_t i = from_idx; i < vec->size; ++i)
    {
        struct report_program_selection report = vec->data[i];
        if (unselected_id != -1 && report.unselected_id == unselected_id)
        {
            assert(!has_unselected_id);
            has_unselected_id = true;
        }
        if (selected_id != -1 && report.selected_id == selected_id)
        {
            assert(!has_selected_id);
            has_selected_id = true;
        }
    }
    if (unselected_id != -1 && selected_id != -1)
        return has_unselected_id && has_selected_id;
    else if (unselected_id)
    {
        assert(!has_selected_id);
        return has_unselected_id;
    }
    else
    {
        assert(selected_id != -1);
        assert(!has_unselected_id);
        return has_selected_id;
    }
}

static void
test_programs(struct ctx *ctx)
{
    test_log("programs\n");

    vlc_player_t *player = ctx->player;
    struct media_params params = DEFAULT_MEDIA_PARAMS(VLC_TICK_FROM_SEC(100));
    params.program_count = 3;
    player_set_next_mock_media(ctx, "media1", &params);

    player_start(ctx);

    {
        vec_on_program_list_changed *vec = &ctx->report.on_program_list_changed;
        while (vec_on_program_list_get_action_count(vec, VLC_PLAYER_LIST_ADDED)
               != params.program_count)
            vlc_player_CondWait(player, &ctx->wait);
    }
    assert(vlc_player_GetProgramCount(player) == params.program_count);

    /* Select every programs ! */
    while (true)
    {
        const struct vlc_player_program *new_prgm = NULL;
        const struct vlc_player_program *old_prgm;
        for (size_t i = 0; i < params.program_count; ++i)
        {
            old_prgm = vlc_player_GetProgramAt(player, i);
            assert(old_prgm);
            assert(old_prgm == vlc_player_GetProgram(player, old_prgm->group_id));
            if (old_prgm->selected)
            {
                if (i + 1 != params.program_count)
                    new_prgm = vlc_player_GetProgramAt(player, i + 1);
                break;
            }
        }
        if (!new_prgm)
            break;
        const int old_id = old_prgm->group_id;
        const int new_id = new_prgm->group_id;
        vlc_player_SelectProgram(player, new_id);

        vec_on_program_selection_changed *vec =
            &ctx->report.on_program_selection_changed;

        size_t vec_oldsize = vec->size;
        while (!vec_on_program_selection_has_event(vec, vec_oldsize, old_id,
                                                   new_id))
            vlc_player_CondWait(player, &ctx->wait);
        ctx->program_switch_count++; /* test_end_poststop_tracks check */
    }

    test_prestop(ctx);
    test_end(ctx);
}

static size_t
vec_on_track_list_get_action_count(vec_on_track_list_changed *vec,
                                   enum vlc_player_list_action action)
{
    size_t count = 0;
    struct report_track_list report;
    vlc_vector_foreach(report, vec)
        if (report.action == action)
            count++;
    return count;
}

static bool
vec_on_track_selection_has_event(vec_on_track_selection_changed *vec,
                                 size_t from_idx, vlc_es_id_t *unselected_id,
                                 vlc_es_id_t *selected_id)
{
    assert(vec->size >= from_idx);
    bool has_unselected_id = false, has_selected_id = false;
    for (size_t i = from_idx; i < vec->size; ++i)
    {
        struct report_track_selection report = vec->data[i];
        if (unselected_id && report.unselected_id == unselected_id)
        {
            assert(!has_unselected_id);
            has_unselected_id = true;
        }
        if (selected_id && report.selected_id == selected_id)
        {
            assert(!has_selected_id);
            has_selected_id = true;
        }
    }
    if (unselected_id && selected_id)
        return has_unselected_id && has_selected_id;
    else if (unselected_id)
    {
        assert(!has_selected_id);
        return has_unselected_id;
    }
    else
    {
        assert(selected_id);
        assert(!has_unselected_id);
        return has_selected_id;
    }
}

static bool
player_select_next_unselected_track(struct ctx *ctx,
                                    enum es_format_category_e cat)
{
    vlc_player_t *player = ctx->player;

    const struct vlc_player_track *new_track = NULL;
    const struct vlc_player_track *old_track = NULL;
    bool has_selected_track = false;
    vlc_es_id_t *new_id, *old_id;

    /* Find the next track to select (selected +1) */
    const size_t count = vlc_player_GetTrackCount(player, cat);
    for (size_t i = 0; i < count; ++i)
    {
        old_track = vlc_player_GetTrackAt(player, cat, i);
        assert(old_track);
        if (old_track->selected)
        {
            has_selected_track = true;
            if (i + 1 != count)
                new_track = vlc_player_GetTrackAt(player, cat, i + 1);
            /* else: trigger UnselectTrack path */
            break;
        }
    }

    if (!has_selected_track)
    {
        /* subs are not selected by default */
        assert(cat == SPU_ES);
        old_track = NULL;
        new_track = vlc_player_GetTrackAt(player, cat, 0);
    }
    new_id = new_track ? vlc_es_id_Hold(new_track->es_id) : NULL;
    old_id = old_track ? vlc_es_id_Hold(old_track->es_id) : NULL;

    if (new_id)
        vlc_player_SelectEsId(player, new_id, VLC_PLAYER_SELECT_EXCLUSIVE);
    else
    {
        assert(old_id);
        vlc_player_UnselectEsId(player, old_id);
    }

    {
        vec_on_track_selection_changed *vec =
            &ctx->report.on_track_selection_changed;

        size_t vec_oldsize = vec->size;
        while (!vec_on_track_selection_has_event(vec, vec_oldsize, old_id,
                                                 new_id))
            vlc_player_CondWait(player, &ctx->wait);
    }
    if (new_id)
        vlc_es_id_Release(new_id);
    if (old_id)
        vlc_es_id_Release(old_id);

    return !!new_track;
}

static void
test_tracks(struct ctx *ctx, bool packetized)
{
    test_log("tracks (packetized: %d)\n", packetized);

    vlc_player_t *player = ctx->player;
    struct media_params params = DEFAULT_MEDIA_PARAMS(VLC_TICK_FROM_SEC(100));
    params.track_count[VIDEO_ES] = 1;
    params.track_count[AUDIO_ES] = 9;
    params.track_count[SPU_ES] = 9;
    params.video_packetized = params.audio_packetized = params.sub_packetized
                            = packetized;
    player_set_next_mock_media(ctx, "media1", &params);
    const size_t track_count = params.track_count[VIDEO_ES] +
                               params.track_count[AUDIO_ES] +
                               params.track_count[SPU_ES];

    player_start(ctx);

    /* Wait that all tracks are added */
    {
        vec_on_track_list_changed *vec = &ctx->report.on_track_list_changed;
        while (vec_on_track_list_get_action_count(vec, VLC_PLAYER_LIST_ADDED)
               != track_count)
            vlc_player_CondWait(player, &ctx->wait);
    }

    /* Wait that video and audio are selected */
    {
        vec_on_track_selection_changed *vec =
            &ctx->report.on_track_selection_changed;
        while (vec->size != 2)
            vlc_player_CondWait(player, &ctx->wait);
        for (size_t i = 0; i < vec->size; ++i)
        {
            assert(!vec->data[i].unselected_id);
            assert(vec->data[i].selected_id);
            const struct vlc_player_track *track =
                vlc_player_GetTrack(player, vec->data[i].selected_id);
            assert(track);
            assert(track->fmt.i_cat == VIDEO_ES || track->fmt.i_cat == AUDIO_ES);
            assert(track == vlc_player_GetTrackAt(player, track->fmt.i_cat, 0));
        }
    }

    static const enum es_format_category_e cats[] = {
        SPU_ES, VIDEO_ES, AUDIO_ES /* Test SPU before the vout is disabled */
    };
    for (size_t i = 0; i < ARRAY_SIZE(cats); ++i)
    {
        /* Select every possible tracks with getters and setters */
        enum es_format_category_e cat = cats[i];
        assert(params.track_count[cat] == vlc_player_GetTrackCount(player, cat));
        while (player_select_next_unselected_track(ctx, cat));

        /* All tracks are unselected now */
        assert(vlc_player_GetSelectedTrack(player, cat) == NULL);

        if (cat == VIDEO_ES)
            continue;

        vec_on_track_selection_changed *vec =
            &ctx->report.on_track_selection_changed;
        size_t vec_oldsize = vec->size;

        /* Select all track via next calls */
        for (size_t j = 0; j < params.track_count[cat]; ++j)
        {
            vlc_player_SelectNextTrack(player, cat);

            /* Wait that the next track is selected */
            const struct vlc_player_track *track =
                vlc_player_GetTrackAt(player, cat, j);
            while (!vec_on_track_selection_has_event(vec, vec_oldsize,
                                                     NULL, track->es_id))
                vlc_player_CondWait(player, &ctx->wait);
            vec_oldsize = vec->size;
        }

        /* Select all track via previous calls */
        for (size_t j = params.track_count[cat] - 1; j > 0; --j)
        {
            vlc_player_SelectPrevTrack(player, cat);

            const struct vlc_player_track *track =
                vlc_player_GetTrackAt(player, cat, j - 1);

            /* Wait that the previous track is selected */
            while (!vec_on_track_selection_has_event(vec, vec_oldsize,
                                                     NULL, track->es_id))
                vlc_player_CondWait(player, &ctx->wait);
            vec_oldsize = vec->size;

        }
        /* Current track index is 0, a previous will unselect the track */
        vlc_player_SelectPrevTrack(player, cat);
        const struct vlc_player_track *track =
            vlc_player_GetTrackAt(player, cat, 0);
        /* Wait that the track is unselected */
        while (!vec_on_track_selection_has_event(vec, vec_oldsize,
                                                 track->es_id, NULL))
            vlc_player_CondWait(player, &ctx->wait);

        assert(vlc_player_GetSelectedTrack(player, cat) == NULL);
    }

    test_prestop(ctx);
    test_end(ctx);
}

static void
test_titles(struct ctx *ctx, bool null_names)
{
    test_log("titles (null_names: %d)\n", null_names);
    vlc_player_t *player = ctx->player;

    struct media_params params = DEFAULT_MEDIA_PARAMS(VLC_TICK_FROM_SEC(100));
    params.title_count = 5;
    params.chapter_count = 2000;
    params.null_names = null_names;
    player_set_next_mock_media(ctx, "media1", &params);

    player_start(ctx);

    /* Wait for the title list */
    vlc_player_title_list *titles;
    {
        vec_on_titles_changed *vec = &ctx->report.on_titles_changed;
        while (vec->size == 0)
            vlc_player_CondWait(player, &ctx->wait);
        titles = vec->data[0];
        assert(titles != NULL && titles == vlc_player_GetTitleList(player));
    }

    /* Select a new title and a new chapter */
    const size_t last_chapter_idx = params.chapter_count - 1;
    {
        vec_on_title_selection_changed *vec =
            &ctx->report.on_title_selection_changed;
        while (vec->size == 0)
            vlc_player_CondWait(player, &ctx->wait);
        assert(vec->data[0] == 0);

        const struct vlc_player_title *title =
            vlc_player_title_list_GetAt(titles, 4);
        vlc_player_SelectTitle(player, title);

        while (vec->size == 1)
            vlc_player_CondWait(player, &ctx->wait);
        assert(vec->data[1] == 4);

        assert(title->chapter_count == params.chapter_count);
        vlc_player_SelectChapter(player, title, last_chapter_idx);
    }

    /* Wait for the chapter selection */
    {
        vec_on_chapter_selection_changed *vec =
            &ctx->report.on_chapter_selection_changed;

        while (vec->size == 0 || VEC_LAST(vec).chapter_idx != last_chapter_idx)
            vlc_player_CondWait(player, &ctx->wait);
        assert(VEC_LAST(vec).title_idx == 4);
    }

    test_prestop(ctx);
    wait_state(ctx, VLC_PLAYER_STATE_STOPPED);
    assert_normal_state(ctx);
    test_end(ctx);
}

static void
test_error(struct ctx *ctx)
{
    test_log("error\n");
    vlc_player_t *player = ctx->player;

    struct media_params params = DEFAULT_MEDIA_PARAMS(VLC_TICK_FROM_SEC(1));
    params.error = true;
    player_set_next_mock_media(ctx, "media1", &params);

    player_start(ctx);

    {
        vec_on_error_changed *vec = &ctx->report.on_error_changed;
        while (vec->size == 0 || VEC_LAST(vec) == VLC_PLAYER_ERROR_NONE)
            vlc_player_CondWait(player, &ctx->wait);
    }
    wait_state(ctx, VLC_PLAYER_STATE_STOPPED);

    test_end(ctx);
}

static void
test_unknown_uri(struct ctx *ctx)
{
    test_log("unknown_uri");
    vlc_player_t *player = ctx->player;

    input_item_t *media = input_item_New("unknownuri://foo", "fail");
    assert(media);
    int ret = vlc_player_SetCurrentMedia(player, media);
    assert(ret == VLC_SUCCESS);

    ctx->params.error = true;
    bool success = vlc_vector_push(&ctx->played_medias, media);
    assert(success);

    player_start(ctx);

    wait_state(ctx, VLC_PLAYER_STATE_STARTED);
    wait_state(ctx, VLC_PLAYER_STATE_STOPPED);
    {
        vec_on_error_changed *vec = &ctx->report.on_error_changed;
        assert(vec->size == 1);
        assert(vec->data[0] != VLC_PLAYER_ERROR_NONE);
    }

    test_end(ctx);
}

static void
test_capabilities_seek(struct ctx *ctx)
{
    test_log("capabilites_seek\n");
    vlc_player_t *player = ctx->player;

    struct media_params params = DEFAULT_MEDIA_PARAMS(VLC_TICK_FROM_SEC(1));
    params.can_seek = false;
    player_set_next_mock_media(ctx, "media1", &params);

    player_start(ctx);

    {
        vec_on_capabilities_changed *vec = &ctx->report.on_capabilities_changed;
        while (vec->size == 0)
            vlc_player_CondWait(player, &ctx->wait);
    }

    vlc_player_ChangeRate(player, 4.f);

    /* Ensure that seek back to 0 doesn't work */
    {
        vlc_tick_t last_time = 0;
        vec_on_state_changed *vec = &ctx->report.on_state_changed;
        while (vec->size == 0 || VEC_LAST(vec) != VLC_PLAYER_STATE_STOPPED)
        {
            vec_on_position_changed *posvec = &ctx->report.on_position_changed;
            if (posvec->size > 0 && last_time != VEC_LAST(posvec).time)
            {
                last_time = VEC_LAST(posvec).time;
                vlc_player_SetTime(player, 0);
            }
            vlc_player_CondWait(player, &ctx->wait);
        }
    }

    assert_state(ctx, VLC_PLAYER_STATE_STOPPED);
    test_end(ctx);
}

static void
test_capabilities_pause(struct ctx *ctx)
{
    test_log("capabilites_pause\n");
    vlc_player_t *player = ctx->player;

    struct media_params params = DEFAULT_MEDIA_PARAMS(VLC_TICK_FROM_SEC(1));
    params.can_pause = false;
    player_set_next_mock_media(ctx, "media1", &params);

    player_start(ctx);

    {
        vec_on_capabilities_changed *vec = &ctx->report.on_capabilities_changed;
        while (vec->size == 0)
            vlc_player_CondWait(player, &ctx->wait);
    }

    /* Ensure that pause doesn't work */
    vlc_player_Pause(player);
    vlc_player_ChangeRate(player, 32.f);

    test_prestop(ctx);

    wait_state(ctx, VLC_PLAYER_STATE_STOPPED);
    assert_normal_state(ctx);

    test_end(ctx);
}

static void
test_pause(struct ctx *ctx)
{
    test_log("pause\n");
    vlc_player_t *player = ctx->player;

    struct media_params params = DEFAULT_MEDIA_PARAMS(VLC_TICK_FROM_SEC(10));
    player_set_next_mock_media(ctx, "media1", &params);

    /* Start paused */
    vlc_player_SetStartPaused(player, true);
    player_start(ctx);
    {
        vec_on_state_changed *vec = &ctx->report.on_state_changed;
        while (vec->size == 0 || VEC_LAST(vec) != VLC_PLAYER_STATE_PAUSED)
            vlc_player_CondWait(player, &ctx->wait);
        assert(vec->size == 3);
        assert(vec->data[0] == VLC_PLAYER_STATE_STARTED);
        assert(vec->data[1] == VLC_PLAYER_STATE_PLAYING);
        assert(vec->data[2] == VLC_PLAYER_STATE_PAUSED);
    }

    {
        vec_on_position_changed *vec = &ctx->report.on_position_changed;
        assert(vec->size == 0);
    }

    /* Resume */
    vlc_player_Resume(player);

    {
        vec_on_state_changed *vec = &ctx->report.on_state_changed;
        while (VEC_LAST(vec) != VLC_PLAYER_STATE_PLAYING)
            vlc_player_CondWait(player, &ctx->wait);
        assert(vec->size == 4);
    }

    {
        vec_on_position_changed *vec = &ctx->report.on_position_changed;
        while (vec->size == 0)
            vlc_player_CondWait(player, &ctx->wait);
    }

    /* Pause again (while playing) */
    vlc_player_Pause(player);

    {
        vec_on_state_changed *vec = &ctx->report.on_state_changed;
        while (VEC_LAST(vec) != VLC_PLAYER_STATE_PAUSED)
            vlc_player_CondWait(player, &ctx->wait);
        assert(vec->size == 5);
    }

    test_end(ctx);
}

static void
test_seeks(struct ctx *ctx)
{
    test_log("seeks\n");
    vlc_player_t *player = ctx->player;

    struct media_params params = DEFAULT_MEDIA_PARAMS(VLC_TICK_FROM_SEC(10));
    player_set_next_mock_media(ctx, "media1", &params);

    /* only the last one will be taken into account before start */
    vlc_player_SetTimeFast(player, 0);
    vlc_player_SetTimeFast(player, VLC_TICK_FROM_SEC(100));
    vlc_player_SetTimeFast(player, 10);

    vlc_tick_t seek_time = VLC_TICK_FROM_SEC(5);
    vlc_player_SetTimeFast(player, seek_time);
    player_start(ctx);

    {
        vec_on_position_changed *vec = &ctx->report.on_position_changed;
        while (vec->size == 0)
            vlc_player_CondWait(player, &ctx->wait);

        assert(VEC_LAST(vec).time >= seek_time);
        assert_position(ctx, &VEC_LAST(vec));

        vlc_tick_t last_time = VEC_LAST(vec).time;

        vlc_tick_t jump_time = -VLC_TICK_FROM_SEC(2);
        vlc_player_JumpTime(player, jump_time);

        while (VEC_LAST(vec).time >= last_time)
            vlc_player_CondWait(player, &ctx->wait);

        assert(VEC_LAST(vec).time >= last_time + jump_time);
        assert_position(ctx, &VEC_LAST(vec));
    }

    vlc_player_SetPosition(player, 2.0f);

    test_prestop(ctx);

    wait_state(ctx, VLC_PLAYER_STATE_STOPPED);
    assert_normal_state(ctx);

    test_end(ctx);
}

#define assert_media_name(media, name) do { \
    assert(media); \
    char *media_name = input_item_GetName(media); \
    assert(media_name && strcmp(media_name, name) == 0); \
    free(media_name); \
} while(0)

static void
test_next_media(struct ctx *ctx)
{
    test_log("next_media\n");
    const char *media_names[] = { "media1", "media2", "media3" };
    const size_t media_count = ARRAY_SIZE(media_names);

    struct media_params params = DEFAULT_MEDIA_PARAMS(VLC_TICK_FROM_MS(100));

    for (size_t i = 0; i < media_count; ++i)
        player_set_next_mock_media(ctx, media_names[i], &params);
    player_set_rate(ctx, 4.f);
    player_start(ctx);

    test_prestop(ctx);
    wait_state(ctx, VLC_PLAYER_STATE_STOPPED);
    assert_normal_state(ctx);

    {
        vec_on_current_media_changed *vec = &ctx->report.on_current_media_changed;

        assert(vec->size == media_count);
        assert(ctx->next_medias.size == 0);
        for (size_t i = 0; i < ctx->played_medias.size; ++i)
            assert_media_name(vec->data[i], media_names[i]);
    }

    test_end(ctx);
}

static void
test_set_current_media(struct ctx *ctx)
{
    test_log("current_media\n");
    const char *media_names[] = { "media1", "media2", "media3" };
    const size_t media_count = ARRAY_SIZE(media_names);

    vlc_player_t *player = ctx->player;
    struct media_params params = DEFAULT_MEDIA_PARAMS(VLC_TICK_FROM_MS(100));

    player_set_current_mock_media(ctx, media_names[0], &params, false);
    player_start(ctx);

    wait_state(ctx, VLC_PLAYER_STATE_PLAYING);

    /* Call vlc_player_SetCurrentMedia for the remaining medias interrupting
     * the player and without passing by the next_media provider. */
    {
        vec_on_current_media_changed *vec = &ctx->report.on_current_media_changed;
        assert(vec->size == 1);
        for (size_t i = 1; i <= media_count; ++i)
        {
            while (vec->size != i)
                vlc_player_CondWait(player, &ctx->wait);

            input_item_t *last_media = VEC_LAST(vec);
            assert(last_media);
            assert(last_media == vlc_player_GetCurrentMedia(player));
            assert(last_media == VEC_LAST(&ctx->played_medias));
            assert_media_name(last_media, media_names[i - 1]);

            if (i < media_count)
            {
                /* Next vlc_player_SetCurrentMedia() call should be
                 * asynchronous since we are still playing. Therefore,
                 * vlc_player_GetCurrentMedia() should return the last one. */
                player_set_current_mock_media(ctx, "ignored", &params, true);
                assert(vlc_player_GetCurrentMedia(player) == last_media);

                /* The previous media is ignored due to this call */
                player_set_current_mock_media(ctx, media_names[i], &params, false);
            }
        }
    }

    test_prestop(ctx);
    wait_state(ctx, VLC_PLAYER_STATE_STOPPED);
    assert_normal_state(ctx);

    /* Test that the player can be played again with the same media */
    player_start(ctx);
    ctx->extra_start_count++; /* Since we play the same media  */

    /* Current state is already stopped, wait first for started then */
    wait_state(ctx, VLC_PLAYER_STATE_STARTED);
    wait_state(ctx, VLC_PLAYER_STATE_STOPPED);

    assert_normal_state(ctx);

    /* Playback is stopped: vlc_player_SetCurrentMedia should be synchronous */
    player_set_current_mock_media(ctx, media_names[0], &params, false);
    assert(vlc_player_GetCurrentMedia(player) == VEC_LAST(&ctx->played_medias));

    player_start(ctx);

    wait_state(ctx, VLC_PLAYER_STATE_STARTED);
    wait_state(ctx, VLC_PLAYER_STATE_STOPPED);

    test_end(ctx);
}

static void
test_delete_while_playback(vlc_object_t *obj, bool start)
{
    test_log("delete_while_playback (start: %d)\n", start);
    vlc_player_t *player = vlc_player_New(obj, VLC_PLAYER_LOCK_NORMAL,
                                          NULL, NULL);

    struct media_params params = DEFAULT_MEDIA_PARAMS(VLC_TICK_FROM_SEC(10));
    input_item_t *media = create_mock_media("media1", &params);
    assert(media);

    vlc_player_Lock(player);
    int ret = vlc_player_SetCurrentMedia(player, media);
    assert(ret == VLC_SUCCESS);
    input_item_Release(media);

    if (start)
    {
        ret = vlc_player_Start(player);
        assert(ret == VLC_SUCCESS);
    }

    vlc_player_Unlock(player);

    vlc_player_Delete(player);
}

static void
test_no_outputs(struct ctx *ctx)
{
    test_log("test_no_outputs\n");
    vlc_player_t *player = ctx->player;

    struct media_params params = DEFAULT_MEDIA_PARAMS(VLC_TICK_FROM_MS(10));
    player_set_current_mock_media(ctx, "media1", &params, false);
    player_start(ctx);

    wait_state(ctx, VLC_PLAYER_STATE_STOPPING);
    {
        vec_on_vout_changed *vec = &ctx->report.on_vout_changed;
        assert(vec->size == 0);
    }

    audio_output_t *aout = vlc_player_aout_Hold(player);
    assert(!aout);

    test_end(ctx);
}

static void
test_outputs(struct ctx *ctx)
{
    test_log("test_outputs\n");
    vlc_player_t *player = ctx->player;

    /* Test that the player has a valid aout and vout, even before first
     * playback */
    audio_output_t *aout = vlc_player_aout_Hold(player);
    assert(aout);

    vout_thread_t *vout = vlc_player_vout_Hold(player);
    assert(vout);

    size_t vout_count;
    vout_thread_t **vout_list = vlc_player_vout_HoldAll(player, &vout_count);
    assert(vout_count == 1 && vout_list[0] == vout);
    vout_Release(vout_list[0]);
    free(vout_list);
    vout_Release(vout);

    /* Test that the player keep the same aout and vout during playback */
    struct media_params params = DEFAULT_MEDIA_PARAMS(VLC_TICK_FROM_MS(10));

    player_set_current_mock_media(ctx, "media1", &params, false);
    player_start(ctx);

    wait_state(ctx, VLC_PLAYER_STATE_STOPPING);

    {
        vec_on_vout_changed *vec = &ctx->report.on_vout_changed;
        assert(vec->size >= 1);
        assert(vec->data[0].action == VLC_PLAYER_VOUT_STARTED);

        vout_thread_t *same_vout = vlc_player_vout_Hold(player);
        assert(vec->data[0].vout == same_vout);
        vout_Release(same_vout);
    }

    audio_output_t *same_aout = vlc_player_aout_Hold(player);
    assert(same_aout == aout);
    aout_Release(same_aout);

    aout_Release(aout);
    test_end(ctx);
}

static void
ctx_destroy(struct ctx *ctx)
{
#define X(type, name) vlc_vector_destroy(&ctx->report.name);
REPORT_LIST
#undef X
    vlc_player_RemoveListener(ctx->player, ctx->listener);
    vlc_player_Unlock(ctx->player);
    vlc_player_Delete(ctx->player);

    libvlc_release(ctx->vlc);
}

static void
ctx_init(struct ctx *ctx, bool use_outputs)
{
    const char * argv[] = {
        "-v",
        "--ignore-config",
        "-Idummy",
        "--no-media-library",
        /* Avoid leaks from various dlopen... */
        "--codec=araw,rawvideo,subsdec,none",
        "--dec-dev=none",
        use_outputs ? "--vout=dummy" : "--vout=none",
        use_outputs ? "--aout=dummy" : "--aout=none",
    };
    libvlc_instance_t *vlc = libvlc_new(ARRAY_SIZE(argv), argv);
    assert(vlc);

    static const struct vlc_player_media_provider provider = {
        .get_next = player_get_next,
    };

#define X(type, name) .name = player_##name,
    static const struct vlc_player_cbs cbs = {
REPORT_LIST
    };
#undef X

    *ctx = (struct ctx) {
        .vlc = vlc,
        .next_medias = VLC_VECTOR_INITIALIZER,
        .played_medias = VLC_VECTOR_INITIALIZER,
        .program_switch_count = 1,
        .extra_start_count = 0,
        .rate = 1.f,
        .wait = VLC_STATIC_COND,
    };
    reports_init(&ctx->report);

    /* Force wdummy window */
    int ret = var_Create(vlc->p_libvlc_int, "window", VLC_VAR_STRING);
    assert(ret == VLC_SUCCESS);
    ret = var_SetString(vlc->p_libvlc_int, "window", "wdummy");
    assert(ret == VLC_SUCCESS);

    ctx->player = vlc_player_New(VLC_OBJECT(vlc->p_libvlc_int),
                                 VLC_PLAYER_LOCK_NORMAL, &provider, ctx);
    assert(ctx->player);

    vlc_player_Lock(ctx->player);
    ctx->listener = vlc_player_AddListener(ctx->player, &cbs, ctx);
    assert(ctx->listener);
}


int
main(void)
{
    test_init();

    struct ctx ctx;

    /* Test with --aout=none --vout=none */
    ctx_init(&ctx, false);
    test_no_outputs(&ctx);
    ctx_destroy(&ctx);

    ctx_init(&ctx, true);

    test_outputs(&ctx); /* Must be the first test */

    test_set_current_media(&ctx);
    test_next_media(&ctx);
    test_seeks(&ctx);
    test_pause(&ctx);
    test_capabilities_pause(&ctx);
    test_capabilities_seek(&ctx);
    test_error(&ctx);
    test_unknown_uri(&ctx);
    test_titles(&ctx, true);
    test_titles(&ctx, false);
    test_tracks(&ctx, true);
    test_tracks(&ctx, false);
    test_programs(&ctx);

    test_delete_while_playback(VLC_OBJECT(ctx.vlc->p_libvlc_int), true);
    test_delete_while_playback(VLC_OBJECT(ctx.vlc->p_libvlc_int), false);

    ctx_destroy(&ctx);
    return 0;
}
