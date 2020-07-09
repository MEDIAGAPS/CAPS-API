#ifndef _MEDIAGAPS_MEDIA_IMEDIASAMPLE_H_
#define _MEDIAGAPS_MEDIA_IMEDIASAMPLE_H_

#include "MediaGaps/Memory/BufferDataList.h"

namespace MediaGaps
{
	namespace Media
	{
		/** Class that represents a media sample.
		  */
		class MediaSampleSharedPtr;

		class MEDIAGAPS_EXPORTS_KEYWORD IMediaSample : public Memory::BufferDataList
		{
		public:
			virtual ~IMediaSample();

			/** Indicates if this is just a reference frame and should not be played.
			  * A typical case for this are the first frames in a MPEG GOP that're returned after a seek are just for decoding purpose.
			  */
			virtual bool GetIsReferenceFrameOnly() const = 0;

			/** Creates a copy of the current MediaSample
			 */
			virtual MediaSampleSharedPtr Clone() = 0;

			virtual UInt64 GetTimestamp() const = 0;

			virtual UInt64 GetDurationTimestamp() const = 0;

            virtual bool GetIsSingleBufferData () const = 0;
		};
	}
}

#endif // _MEDIAGAPS_MEDIA_IMEDIASAMPLE_H_
