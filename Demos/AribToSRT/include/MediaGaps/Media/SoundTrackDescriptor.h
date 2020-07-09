#ifndef _MEDIAGAPS_MEDIA_SOUNDTRACKDESCRIPTOR_H_
#define _MEDIAGAPS_MEDIA_SOUNDTRACKDESCRIPTOR_H_

#include "MediaGaps/Media/TrackDescriptor.h"
#include "MediaGaps/Media/TrackDescriptorSharedPtr.h"

namespace MediaGaps
{
    namespace Media
    {
        class MEDIAGAPS_EXPORTS_KEYWORD SoundTrackDescriptor : public TrackDescriptor
        {
            struct Impl;
            Impl* _impl;

        public:
            SoundTrackDescriptor();

            ~SoundTrackDescriptor();

            /** Copy constructor. */
            SoundTrackDescriptor(const SoundTrackDescriptor&);

            /** Assignment operator */
            SoundTrackDescriptor& operator=(const SoundTrackDescriptor&);

            /** Returns the audio sampling rate (e.g. 48000 for 48kHz audio). */
            virtual UInt32* GetSamplingRate() const;

            /** Sets the audio sampling rate (e.g. 48000 for 48kHz audio). */
            virtual void SetSamplingRate(UInt32 samplingRate);

            /** Returns the audio sampling bits (e.g. 16 or 24 bits per sample). */
            virtual UInt32* GetSamplingBits() const;

            /** Sets the audio sampling bits (e.g. 16 or 24 bits per sample). */
            virtual void SetSamplingBits(UInt32 samplingBits);

            /** Returns the number of audio channels for the track.*/
            virtual UInt32* GetChannelCount() const;

            /** Sets the number of audio channels for the track.*/
            virtual void SetChannelCount(UInt32 channelCount);

			TrackDescriptorSharedPtr Clone() const;
        };
    }
}

#endif // _MEDIAGAPS_MEDIA_SOUNDTRACKDESCRIPTOR_H_
