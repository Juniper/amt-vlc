/*
 * SegmentTracker.hpp
 *****************************************************************************
 * Copyright (C) 2014 - VideoLAN and VLC authors
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2.1 of the License, or
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
#ifndef SEGMENTTRACKER_HPP
#define SEGMENTTRACKER_HPP

#include "StreamFormat.hpp"
#include "playlist/Role.hpp"

#include <vlc_common.h>
#include <list>

namespace adaptive
{
    class ID;
    class SharedResources;

    namespace http
    {
        class AbstractConnectionManager;
    }

    namespace logic
    {
        class AbstractAdaptationLogic;
    }

    namespace playlist
    {
        class BaseAdaptationSet;
        class BaseRepresentation;
        class SegmentChunk;
    }

    using namespace playlist;
    using namespace logic;
    using namespace http;

    class SegmentTrackerEvent
    {
        public:
            SegmentTrackerEvent(SegmentChunk *);
            SegmentTrackerEvent(BaseRepresentation *, BaseRepresentation *);
            SegmentTrackerEvent(const StreamFormat *);
            SegmentTrackerEvent(const ID &, bool);
            SegmentTrackerEvent(const ID &, vlc_tick_t, vlc_tick_t, vlc_tick_t);
            SegmentTrackerEvent(const ID &, vlc_tick_t);
            enum
            {
                DISCONTINUITY,
                SWITCHING,
                FORMATCHANGE,
                BUFFERING_STATE,
                BUFFERING_LEVEL_CHANGE,
                SEGMENT_CHANGE,
            } type;
            union
            {
               struct
               {
                    SegmentChunk *sc;
               } discontinuity;
               struct
               {
                    BaseRepresentation *prev;
                    BaseRepresentation *next;
               } switching;
               struct
               {
                    const StreamFormat *f;
               } format;
               struct
               {
                   const ID *id;
                   bool enabled;
               } buffering;
               struct
               {
                   const ID *id;
                   vlc_tick_t minimum;
                   vlc_tick_t current;
                   vlc_tick_t target;
               } buffering_level;
               struct
               {
                    const ID *id;
                   vlc_tick_t duration;
               } segment;
            } u;
    };

    class SegmentTrackerListenerInterface
    {
        public:
            virtual void trackerEvent(const SegmentTrackerEvent &) = 0;
    };

    class SegmentTracker
    {
        public:
            SegmentTracker(SharedResources *,
                           AbstractAdaptationLogic *, BaseAdaptationSet *);
            ~SegmentTracker();

            StreamFormat getCurrentFormat() const;
            std::list<std::string> getCurrentCodecs() const;
            const std::string & getStreamDescription() const;
            const std::string & getStreamLanguage() const;
            const Role & getStreamRole() const;
            bool segmentsListReady() const;
            void reset();
            SegmentChunk* getNextChunk(bool, AbstractConnectionManager *);
            bool setPositionByTime(vlc_tick_t, bool, bool);
            void setPositionByNumber(uint64_t, bool);
            vlc_tick_t getPlaybackTime() const; /* Current segment start time if selected */
            bool getMediaPlaybackRange(vlc_tick_t *, vlc_tick_t *, vlc_tick_t *) const;
            vlc_tick_t getMinAheadTime() const;
            void notifyBufferingState(bool) const;
            void notifyBufferingLevel(vlc_tick_t, vlc_tick_t, vlc_tick_t) const;
            void registerListener(SegmentTrackerListenerInterface *);
            void updateSelected();

        private:
            void setAdaptationLogic(AbstractAdaptationLogic *);
            void notify(const SegmentTrackerEvent &) const;
            bool first;
            bool initializing;
            bool index_sent;
            bool init_sent;
            uint64_t next;
            uint64_t curNumber;
            StreamFormat format;
            SharedResources *resources;
            AbstractAdaptationLogic *logic;
            BaseAdaptationSet *adaptationSet;
            BaseRepresentation *curRepresentation;
            std::list<SegmentTrackerListenerInterface *> listeners;
    };
}

#endif // SEGMENTTRACKER_HPP
