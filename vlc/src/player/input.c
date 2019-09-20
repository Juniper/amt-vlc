/*****************************************************************************
 * player_input.c: Player input implementation
 *****************************************************************************
 * Copyright © 2018-2019 VLC authors and VideoLAN
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

#include <vlc_common.h>
#include <vlc_interface.h>
#include "player.h"

struct vlc_player_track_priv *
vlc_player_input_FindTrackById(struct vlc_player_input *input, vlc_es_id_t *id,
                               size_t *idx)
{
    vlc_player_track_vector *vec =
        vlc_player_input_GetTrackVector(input, vlc_es_id_GetCat(id));
    return vec ? vlc_player_track_vector_FindById(vec, id, idx) : NULL;
}

static void
vlc_player_input_HandleAtoBLoop(struct vlc_player_input *input, vlc_tick_t time,
                                float pos)
{
    vlc_player_t *player = input->player;

    if (player->input != input)
        return;

    assert(input->abloop_state[0].set && input->abloop_state[1].set);

    if (time != VLC_TICK_INVALID
     && input->abloop_state[0].time != VLC_TICK_INVALID
     && input->abloop_state[1].time != VLC_TICK_INVALID)
    {
        if (time >= input->abloop_state[1].time)
            vlc_player_SetTime(player, input->abloop_state[0].time);
    }
    else if (pos >= input->abloop_state[1].pos)
        vlc_player_SetPosition(player, input->abloop_state[0].pos);
}

vlc_tick_t
vlc_player_input_GetTime(struct vlc_player_input *input)
{
    return input->time;
}

float
vlc_player_input_GetPos(struct vlc_player_input *input)
{
    return input->position;
}

static void
vlc_player_input_UpdateTime(struct vlc_player_input *input)
{
    if (input->abloop_state[0].set && input->abloop_state[1].set)
        vlc_player_input_HandleAtoBLoop(input, vlc_player_input_GetTime(input),
                                        vlc_player_input_GetPos(input));
}

int
vlc_player_input_Start(struct vlc_player_input *input)
{
    int ret = input_Start(input->thread);
    if (ret != VLC_SUCCESS)
        return ret;
    input->started = true;
    return ret;
}

static bool
vlc_player_WaitRetryDelay(vlc_player_t *player)
{
#define RETRY_TIMEOUT_BASE VLC_TICK_FROM_MS(100)
#define RETRY_TIMEOUT_MAX VLC_TICK_FROM_MS(3200)
    if (player->error_count)
    {
        /* Delay the next opening in case of error to avoid busy loops */
        vlc_tick_t delay = RETRY_TIMEOUT_BASE;
        for (unsigned i = 1; i < player->error_count
          && delay < RETRY_TIMEOUT_MAX; ++i)
            delay *= 2; /* Wait 100, 200, 400, 800, 1600 and finally 3200ms */
        delay += vlc_tick_now();

        while (player->error_count > 0
            && vlc_cond_timedwait(&player->start_delay_cond, &player->lock,
                                  delay) == 0);
        if (player->error_count == 0)
            return false; /* canceled */
    }
    return true;
}

void
vlc_player_input_HandleState(struct vlc_player_input *input,
                             enum vlc_player_state state)
{
    vlc_player_t *player = input->player;

    /* The STOPPING state can be set earlier by the player. In that case,
     * ignore all future events except the STOPPED one */
    if (input->state == VLC_PLAYER_STATE_STOPPING
     && state != VLC_PLAYER_STATE_STOPPED)
        return;

    input->state = state;

    /* Override the global state if the player is still playing and has a next
     * media to play */
    bool send_event = player->global_state != state;
    switch (input->state)
    {
        case VLC_PLAYER_STATE_STOPPED:
            assert(!input->started);
            assert(input != player->input);

            if (input->titles)
            {
                vlc_player_title_list_Release(input->titles);
                input->titles = NULL;
                vlc_player_SendEvent(player, on_titles_changed, NULL);
            }

            if (input->error != VLC_PLAYER_ERROR_NONE)
                player->error_count++;
            else
                player->error_count = 0;

            vlc_player_WaitRetryDelay(player);

            if (!player->deleting)
                vlc_player_OpenNextMedia(player);
            if (!player->input)
                player->started = false;

            switch (player->media_stopped_action)
            {
                case VLC_PLAYER_MEDIA_STOPPED_EXIT:
                    if (player->input && player->started)
                        vlc_player_input_Start(player->input);
                    else
                        libvlc_Quit(vlc_object_instance(player));
                    break;
                case VLC_PLAYER_MEDIA_STOPPED_CONTINUE:
                    if (player->input && player->started)
                        vlc_player_input_Start(player->input);
                    break;
                default:
                    break;
            }

            send_event = !player->started;
            break;
        case VLC_PLAYER_STATE_STOPPING:
            input->started = false;
            if (input == player->input)
                player->input = NULL;

            if (player->started)
            {
                vlc_player_PrepareNextMedia(player);
                if (!player->next_media)
                    player->started = false;
            }
            send_event = !player->started;
            break;
        case VLC_PLAYER_STATE_STARTED:
        case VLC_PLAYER_STATE_PLAYING:
            if (player->started &&
                player->global_state == VLC_PLAYER_STATE_PLAYING)
                send_event = false;
            break;

        case VLC_PLAYER_STATE_PAUSED:
            assert(player->started && input->started);
            break;
        default:
            vlc_assert_unreachable();
    }

    if (send_event)
    {
        player->global_state = input->state;
        vlc_player_SendEvent(player, on_state_changed, player->global_state);
    }
}

static void
vlc_player_input_HandleStateEvent(struct vlc_player_input *input,
                                  input_state_e state)
{
    switch (state)
    {
        case OPENING_S:
            vlc_player_input_HandleState(input, VLC_PLAYER_STATE_STARTED);
            break;
        case PLAYING_S:
            vlc_player_input_HandleState(input, VLC_PLAYER_STATE_PLAYING);
            break;
        case PAUSE_S:
            vlc_player_input_HandleState(input, VLC_PLAYER_STATE_PAUSED);
            break;
        case END_S:
            vlc_player_input_HandleState(input, VLC_PLAYER_STATE_STOPPING);
            vlc_player_destructor_AddStoppingInput(input->player, input);
            break;
        case ERROR_S:
            /* Don't send errors if the input is stopped by the user */
            if (input->started)
            {
                /* Contrary to the input_thead_t, an error is not a state */
                input->error = VLC_PLAYER_ERROR_GENERIC;
                vlc_player_SendEvent(input->player, on_error_changed, input->error);
            }
            break;
        default:
            vlc_assert_unreachable();
    }
}

static void
vlc_player_input_HandleProgramEvent(struct vlc_player_input *input,
                                    const struct vlc_input_event_program *ev)
{
    vlc_player_t *player = input->player;
    struct vlc_player_program *prgm;
    vlc_player_program_vector *vec = &input->program_vector;

    switch (ev->action)
    {
        case VLC_INPUT_PROGRAM_ADDED:
            prgm = vlc_player_program_New(ev->id, ev->title);
            if (!prgm)
                break;

            if (!vlc_vector_push(vec, prgm))
            {
                vlc_player_program_Delete(prgm);
                break;
            }
            vlc_player_SendEvent(player, on_program_list_changed,
                                 VLC_PLAYER_LIST_ADDED, prgm);
            break;
        case VLC_INPUT_PROGRAM_DELETED:
        {
            size_t idx;
            prgm = vlc_player_program_vector_FindById(vec, ev->id, &idx);
            if (prgm)
            {
                vlc_player_SendEvent(player, on_program_list_changed,
                                     VLC_PLAYER_LIST_REMOVED, prgm);
                vlc_vector_remove(vec, idx);
                vlc_player_program_Delete(prgm);
            }
            break;
        }
        case VLC_INPUT_PROGRAM_UPDATED:
        case VLC_INPUT_PROGRAM_SCRAMBLED:
            prgm = vlc_player_program_vector_FindById(vec, ev->id, NULL);
            if (!prgm)
                break;
            if (ev->action == VLC_INPUT_PROGRAM_UPDATED)
            {
                if (vlc_player_program_Update(prgm, ev->id, ev->title) != 0)
                    break;
            }
            else
                prgm->scrambled = ev->scrambled;
            vlc_player_SendEvent(player, on_program_list_changed,
                                 VLC_PLAYER_LIST_UPDATED, prgm);
            break;
        case VLC_INPUT_PROGRAM_SELECTED:
        {
            int unselected_id = -1, selected_id = -1;
            vlc_vector_foreach(prgm, vec)
            {
                if (prgm->group_id == ev->id)
                {
                    if (!prgm->selected)
                    {
                        assert(selected_id == -1);
                        prgm->selected = true;
                        selected_id = prgm->group_id;
                    }
                }
                else
                {
                    if (prgm->selected)
                    {
                        assert(unselected_id == -1);
                        prgm->selected = false;
                        unselected_id = prgm->group_id;
                    }
                }
            }
            if (unselected_id != -1 || selected_id != -1)
                vlc_player_SendEvent(player, on_program_selection_changed,
                                     unselected_id, selected_id);
            break;
        }
        default:
            vlc_assert_unreachable();
    }
}

static void
vlc_player_input_HandleTeletextMenu(struct vlc_player_input *input,
                                    const struct vlc_input_event_es *ev)
{
    vlc_player_t *player = input->player;
    switch (ev->action)
    {
        case VLC_INPUT_ES_ADDED:
            if (input->teletext_menu)
            {
                msg_Warn(player, "Can't handle more than one teletext menu "
                         "track. Using the last one.");
                vlc_player_track_priv_Delete(input->teletext_menu);
            }
            input->teletext_menu = vlc_player_track_priv_New(ev->id, ev->title,
                                                             ev->fmt);
            if (!input->teletext_menu)
                return;

            vlc_player_SendEvent(player, on_teletext_menu_changed, true);
            break;
        case VLC_INPUT_ES_DELETED:
        {
            if (input->teletext_menu && input->teletext_menu->t.es_id == ev->id)
            {
                assert(!input->teletext_enabled);

                vlc_player_track_priv_Delete(input->teletext_menu);
                input->teletext_menu = NULL;
                vlc_player_SendEvent(player, on_teletext_menu_changed, false);
            }
            break;
        }
        case VLC_INPUT_ES_UPDATED:
            break;
        case VLC_INPUT_ES_SELECTED:
        case VLC_INPUT_ES_UNSELECTED:
            if (input->teletext_menu->t.es_id == ev->id)
            {
                input->teletext_enabled = ev->action == VLC_INPUT_ES_SELECTED;
                vlc_player_SendEvent(player, on_teletext_enabled_changed,
                                     input->teletext_enabled);
            }
            break;
        default:
            vlc_assert_unreachable();
    }
}

static void
vlc_player_input_HandleEsEvent(struct vlc_player_input *input,
                               const struct vlc_input_event_es *ev)
{
    assert(ev->id && ev->title && ev->fmt);

    if (ev->fmt->i_cat == SPU_ES && ev->fmt->i_codec == VLC_CODEC_TELETEXT
     && (ev->fmt->subs.teletext.i_magazine == 1
      || ev->fmt->subs.teletext.i_magazine > 8))
    {
        vlc_player_input_HandleTeletextMenu(input, ev);
        return;
    }

    vlc_player_track_vector *vec =
        vlc_player_input_GetTrackVector(input, ev->fmt->i_cat);
    if (!vec)
        return; /* UNKNOWN_ES or DATA_ES not handled */

    vlc_player_t *player = input->player;
    struct vlc_player_track_priv *trackpriv;
    switch (ev->action)
    {
        case VLC_INPUT_ES_ADDED:
            trackpriv = vlc_player_track_priv_New(ev->id, ev->title, ev->fmt);
            if (!trackpriv)
                break;

            if (!vlc_vector_push(vec, trackpriv))
            {
                vlc_player_track_priv_Delete(trackpriv);
                break;
            }
            vlc_player_SendEvent(player, on_track_list_changed,
                                 VLC_PLAYER_LIST_ADDED, &trackpriv->t);
            break;
        case VLC_INPUT_ES_DELETED:
        {
            size_t idx;
            trackpriv = vlc_player_track_vector_FindById(vec, ev->id, &idx);
            if (trackpriv)
            {
                vlc_player_SendEvent(player, on_track_list_changed,
                                     VLC_PLAYER_LIST_REMOVED, &trackpriv->t);
                vlc_vector_remove(vec, idx);
                vlc_player_track_priv_Delete(trackpriv);
            }
            break;
        }
        case VLC_INPUT_ES_UPDATED:
            trackpriv = vlc_player_track_vector_FindById(vec, ev->id, NULL);
            if (!trackpriv)
                break;
            if (vlc_player_track_priv_Update(trackpriv, ev->title, ev->fmt) != 0)
                break;
            vlc_player_SendEvent(player, on_track_list_changed,
                                 VLC_PLAYER_LIST_UPDATED, &trackpriv->t);
            break;
        case VLC_INPUT_ES_SELECTED:
            trackpriv = vlc_player_track_vector_FindById(vec, ev->id, NULL);
            if (trackpriv)
            {
                trackpriv->t.selected = true;
                vlc_player_SendEvent(player, on_track_selection_changed,
                                     NULL, trackpriv->t.es_id);
            }
            break;
        case VLC_INPUT_ES_UNSELECTED:
            trackpriv = vlc_player_track_vector_FindById(vec, ev->id, NULL);
            if (trackpriv)
            {
                trackpriv->t.selected = false;
                vlc_player_SendEvent(player, on_track_selection_changed,
                                     trackpriv->t.es_id, NULL);
            }
            break;
        default:
            vlc_assert_unreachable();
    }
}

static void
vlc_player_input_HandleTitleEvent(struct vlc_player_input *input,
                                  const struct vlc_input_event_title *ev)
{
    vlc_player_t *player = input->player;
    switch (ev->action)
    {
        case VLC_INPUT_TITLE_NEW_LIST:
        {
            input_thread_private_t *input_th = input_priv(input->thread);
            const int title_offset = input_th->i_title_offset;
            const int chapter_offset = input_th->i_seekpoint_offset;

            if (input->titles)
                vlc_player_title_list_Release(input->titles);
            input->title_selected = input->chapter_selected = 0;
            input->titles =
                vlc_player_title_list_Create(ev->list.array, ev->list.count,
                                             title_offset, chapter_offset);
            vlc_player_SendEvent(player, on_titles_changed, input->titles);
            if (input->titles)
                vlc_player_SendEvent(player, on_title_selection_changed,
                                     &input->titles->array[0], 0);
            break;
        }
        case VLC_INPUT_TITLE_SELECTED:
            if (!input->titles)
                return; /* a previous VLC_INPUT_TITLE_NEW_LIST failed */
            assert(ev->selected_idx < input->titles->count);
            input->title_selected = ev->selected_idx;
            vlc_player_SendEvent(player, on_title_selection_changed,
                                 &input->titles->array[input->title_selected],
                                 input->title_selected);
            break;
        default:
            vlc_assert_unreachable();
    }
}

static void
vlc_player_input_HandleChapterEvent(struct vlc_player_input *input,
                                    const struct vlc_input_event_chapter *ev)
{
    vlc_player_t *player = input->player;
    if (!input->titles || ev->title < 0 || ev->seekpoint < 0)
        return; /* a previous VLC_INPUT_TITLE_NEW_LIST failed */

    assert((size_t)ev->title < input->titles->count);
    const struct vlc_player_title *title = &input->titles->array[ev->title];
    if (!title->chapter_count)
        return;

    assert(ev->seekpoint < (int)title->chapter_count);
    input->title_selected = ev->title;
    input->chapter_selected = ev->seekpoint;

    const struct vlc_player_chapter *chapter = &title->chapters[ev->seekpoint];
    vlc_player_SendEvent(player, on_chapter_selection_changed, title, ev->title,
                         chapter, ev->seekpoint);
}

static void
vlc_player_input_HandleVoutEvent(struct vlc_player_input *input,
                                 const struct vlc_input_event_vout *ev)
{
    assert(ev->vout);
    assert(ev->id);

    vlc_player_t *player = input->player;

    struct vlc_player_track_priv *trackpriv =
        vlc_player_input_FindTrackById(input, ev->id, NULL);
    if (!trackpriv)
        return;

    const bool is_video_es = trackpriv->t.fmt.i_cat == VIDEO_ES;

    switch (ev->action)
    {
        case VLC_INPUT_EVENT_VOUT_ADDED:
            trackpriv->vout = ev->vout;
            vlc_player_SendEvent(player, on_vout_changed,
                                 VLC_PLAYER_VOUT_STARTED, ev->vout,
                                 ev->order, ev->id);

            if (is_video_es)
            {
                /* Register vout callbacks after the vout list event */
                vlc_player_vout_AddCallbacks(player, ev->vout);
            }
            break;
        case VLC_INPUT_EVENT_VOUT_DELETED:
            if (is_video_es)
            {
                /* Un-register vout callbacks before the vout list event */
                vlc_player_vout_DelCallbacks(player, ev->vout);
            }

            trackpriv->vout = NULL;
            vlc_player_SendEvent(player, on_vout_changed,
                                 VLC_PLAYER_VOUT_STOPPED, ev->vout,
                                 VLC_VOUT_ORDER_NONE, ev->id);
            break;
        default:
            vlc_assert_unreachable();
    }
}

static void
input_thread_Events(input_thread_t *input_thread,
                    const struct vlc_input_event *event, void *user_data)
{
    struct vlc_player_input *input = user_data;
    vlc_player_t *player = input->player;

    assert(input_thread == input->thread);

    vlc_mutex_lock(&player->lock);

    switch (event->type)
    {
        case INPUT_EVENT_STATE:
            vlc_player_input_HandleStateEvent(input, event->state);
            break;
        case INPUT_EVENT_RATE:
            input->rate = event->rate;
            vlc_player_SendEvent(player, on_rate_changed, input->rate);
            break;
        case INPUT_EVENT_CAPABILITIES:
        {
            int old_caps = input->capabilities;
            input->capabilities = event->capabilities;
            vlc_player_SendEvent(player, on_capabilities_changed,
                                 old_caps, input->capabilities);
            break;
        }
        case INPUT_EVENT_TIMES:
            if (event->times.ms != VLC_TICK_INVALID
             && (input->time != event->times.ms
              || input->position != event->times.percentage))
            {
                input->time = event->times.ms;
                input->position = event->times.percentage;
                vlc_player_SendEvent(player, on_position_changed,
                                     input->time, input->position);

                vlc_player_input_UpdateTime(input);
            }
            if (input->length != event->times.length)
            {
                input->length = event->times.length;
                vlc_player_SendEvent(player, on_length_changed, input->length);
            }
            break;
        case INPUT_EVENT_PROGRAM:
            vlc_player_input_HandleProgramEvent(input, &event->program);
            break;
        case INPUT_EVENT_ES:
            vlc_player_input_HandleEsEvent(input, &event->es);
            break;
        case INPUT_EVENT_TITLE:
            vlc_player_input_HandleTitleEvent(input, &event->title);
            break;
        case INPUT_EVENT_CHAPTER:
            vlc_player_input_HandleChapterEvent(input, &event->chapter);
            break;
        case INPUT_EVENT_RECORD:
            input->recording = event->record;
            vlc_player_SendEvent(player, on_recording_changed, input->recording);
            break;
        case INPUT_EVENT_STATISTICS:
            input->stats = *event->stats;
            vlc_player_SendEvent(player, on_statistics_changed, &input->stats);
            break;
        case INPUT_EVENT_SIGNAL:
            input->signal_quality = event->signal.quality;
            input->signal_strength = event->signal.strength;
            vlc_player_SendEvent(player, on_signal_changed,
                                 input->signal_quality, input->signal_strength);
            break;
        case INPUT_EVENT_CACHE:
            input->cache = event->cache;
            vlc_player_SendEvent(player, on_buffering_changed, event->cache);
            break;
        case INPUT_EVENT_VOUT:
            vlc_player_input_HandleVoutEvent(input, &event->vout);
            break;
        case INPUT_EVENT_ITEM_META:
            vlc_player_SendEvent(player, on_media_meta_changed,
                                 input_GetItem(input->thread));
            break;
        case INPUT_EVENT_ITEM_EPG:
            vlc_player_SendEvent(player, on_media_epg_changed,
                                 input_GetItem(input->thread));
            break;
        case INPUT_EVENT_SUBITEMS:
            vlc_player_SendEvent(player, on_media_subitems_changed,
                                 input_GetItem(input->thread), event->subitems);
            break;
        case INPUT_EVENT_DEAD:
            if (input->started) /* Can happen with early input_thread fails */
                vlc_player_input_HandleState(input, VLC_PLAYER_STATE_STOPPING);
            vlc_player_destructor_AddJoinableInput(player, input);
            break;
        case INPUT_EVENT_VBI_PAGE:
            input->teletext_page = event->vbi_page < 999 ? event->vbi_page : 100;
            vlc_player_SendEvent(player, on_teletext_page_changed,
                                 input->teletext_page);
            break;
        case INPUT_EVENT_VBI_TRANSPARENCY:
            input->teletext_transparent = event->vbi_transparent;
            vlc_player_SendEvent(player, on_teletext_transparency_changed,
                                 input->teletext_transparent);
            break;
        default:
            break;
    }

    vlc_mutex_unlock(&player->lock);
}

struct vlc_player_input *
vlc_player_input_New(vlc_player_t *player, input_item_t *item)
{
    struct vlc_player_input *input = malloc(sizeof(*input));
    if (!input)
        return NULL;

    input->player = player;
    input->started = false;

    input->state = VLC_PLAYER_STATE_STOPPED;
    input->error = VLC_PLAYER_ERROR_NONE;
    input->rate = 1.f;
    input->capabilities = 0;
    input->length = input->time = VLC_TICK_INVALID;
    input->position = 0.f;

    input->recording = false;

    input->cache = 0.f;
    input->signal_quality = input->signal_strength = -1.f;

    memset(&input->stats, 0, sizeof(input->stats));

    vlc_vector_init(&input->program_vector);
    vlc_vector_init(&input->video_track_vector);
    vlc_vector_init(&input->audio_track_vector);
    vlc_vector_init(&input->spu_track_vector);
    input->teletext_menu = NULL;

    input->titles = NULL;
    input->title_selected = input->chapter_selected = 0;

    input->teletext_enabled = input->teletext_transparent = false;
    input->teletext_page = 0;

    input->abloop_state[0].set = input->abloop_state[1].set = false;

    input->thread = input_Create(player, input_thread_Events, input, item,
                                 player->resource, player->renderer);
    if (!input->thread)
    {
        free(input);
        return NULL;
    }

    /* Initial sub/audio delay */
    const vlc_tick_t cat_delays[DATA_ES] = {
        [AUDIO_ES] =
            VLC_TICK_FROM_MS(var_InheritInteger(player, "audio-desync")),
        [SPU_ES] =
            vlc_tick_from_samples(var_InheritInteger(player, "sub-delay"), 10),
    };

    for (enum es_format_category_e i = UNKNOWN_ES; i < DATA_ES; ++i)
    {
        input->cat_delays[i] = cat_delays[i];
        if (cat_delays[i] != 0)
        {
            const input_control_param_t param = {
                .cat_delay = { i, cat_delays[i] }
            };
            input_ControlPush(input->thread, INPUT_CONTROL_SET_CATEGORY_DELAY,
                              &param);
            vlc_player_SendEvent(player, on_category_delay_changed, i,
                                 cat_delays[i]);
        }
    }
    return input;
}

void
vlc_player_input_Delete(struct vlc_player_input *input)
{
    assert(input->titles == NULL);
    assert(input->program_vector.size == 0);
    assert(input->video_track_vector.size == 0);
    assert(input->audio_track_vector.size == 0);
    assert(input->spu_track_vector.size == 0);
    assert(input->teletext_menu == NULL);

    vlc_vector_destroy(&input->program_vector);
    vlc_vector_destroy(&input->video_track_vector);
    vlc_vector_destroy(&input->audio_track_vector);
    vlc_vector_destroy(&input->spu_track_vector);

    input_Close(input->thread);
    free(input);
}

