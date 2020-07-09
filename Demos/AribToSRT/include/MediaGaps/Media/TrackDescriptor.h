#ifndef _MEDIAGAPS_MEDIA_TRACKDESCRIPTOR_H_
#define _MEDIAGAPS_MEDIA_TRACKDESCRIPTOR_H_

#include "MediaGaps/Exports.h"
#include "MediaGaps/Types.h"

namespace MediaGaps
{
	namespace Media
	{
		enum TrackDescriptorEssenceKind
		{
			TrackDescriptorEssenceKind_Unknown = 0,
			TrackDescriptorEssenceKind_AAC,
			TrackDescriptorEssenceKind_DNxHD,
			TrackDescriptorEssenceKind_H264,
			TrackDescriptorEssenceKind_MPEG2,
			TrackDescriptorEssenceKind_DVCPRO,
			TrackDescriptorEssenceKind_MPEGAudio,
			TrackDescriptorEssenceKind_PCM,
			TrackDescriptorEssenceKind_AIFF,
			TrackDescriptorEssenceKind_PCM_BLUERAY,
			TrackDescriptorEssenceKind_Uncompressed,
			TrackDescriptorEssenceKind_JFIF_15_1,
			TrackDescriptorEssenceKind_JFIF_10_1,
			TrackDescriptorEssenceKind_JFIF_10_1M,
			TrackDescriptorEssenceKind_AVCIntra,
			TrackDescriptorEssenceKind_ProRes_422Proxy,
			TrackDescriptorEssenceKind_ProRes_422LT,
			TrackDescriptorEssenceKind_ProRes_422,
			TrackDescriptorEssenceKind_ProRes_422HQ,
			TrackDescriptorEssenceKind_JFIF_20_1,
			TrackDescriptorEssenceKind_MP3,
            TrackDescriptorEssenceKind_ANC,
            TrackDescriptorEssenceKind_VBI,
			TrackDescriptorEssenceKind_DNxHR_444,
			TrackDescriptorEssenceKind_DNxHR_HQX,
			TrackDescriptorEssenceKind_DNxHR_HQ,
			TrackDescriptorEssenceKind_DNxHR_SQ,
			TrackDescriptorEssenceKind_DNxHR_LB,
			TrackDescriptorEssenceKind_XAVCLGOP,
			TrackDescriptorEssenceKind_XAVCIntra_300_CBG,
			TrackDescriptorEssenceKind_XAVCIntra_300_VBR,
			TrackDescriptorEssenceKind_XAVCIntra_480_CBG,
			TrackDescriptorEssenceKind_XAVCIntra_480_VBR,
			TrackDescriptorEssenceKind_ProRes_4444,
            TrackDescriptorEssenceKind_ProRes_4444XQ,
			TrackDescriptorEssenceKind_IMX
		};

		class TrackDescriptorSharedPtr;

		/** Base class for describing the essence returned in a given track.
		  */
		class MEDIAGAPS_EXPORTS_KEYWORD TrackDescriptor
		{
			struct Impl;
			Impl* _impl;

		protected:
			/** Constructor.*/
			TrackDescriptor();

			/** Copy constructor. */
			TrackDescriptor(const TrackDescriptor&);

			/** Assignment operator */
			TrackDescriptor& operator=(const TrackDescriptor&);

			bool operator==(const TrackDescriptor& other) const;

		public:
			/** Destructor */
			virtual ~TrackDescriptor();

			/** Identifies the essence contained in a track. */
			virtual TrackDescriptorEssenceKind GetEssenceKind() const;

			/** Sets the essence contained in a track. */
			virtual void SetEssenceKind(TrackDescriptorEssenceKind essenceKind);

			/** Returns an unique identifier for a track. */
			virtual UInt32* GetTrackId() const;

			/** Sets an unique identifier for a track. */
			virtual void SetTrackId(UInt32 trackId);

			/** Returns the sample rate. */
			virtual Rational32* GetSampleRate() const;

			/** Sets the sample rate. */
			virtual void SetSampleRate(Rational32 sampleRate);

			/** Returns the precharge value for this track. */
			virtual UInt32* GetPreCharge() const;

			/** Sets the precharge value. */
			virtual void SetPreCharge(UInt32 preCharge);

			/** Creates a new entity of the class */
			virtual TrackDescriptorSharedPtr Clone() const = 0;

			/* Add a new generic key value to Track Descriptor*/
			virtual void AddKeyValue(const char* key, const char* value);

			/* Returns value associated with key using add_key_value function or nullptr if no key is found*/
			virtual const char* GetKeyValue(const char* key) const;
		};
	}
}

#endif // _MEDIAGAPS_MEDIA_TRACKDESCRIPTOR_H_
