#ifndef _MEDIAGAPS_MEDIA_PICTURETRACKDESCRIPTOR_H_
#define _MEDIAGAPS_MEDIA_PICTURETRACKDESCRIPTOR_H_

#include "MediaGaps/Media/TrackDescriptor.h"
#include "MediaGaps/Media/Colorspaces.h"
#include "MediaGaps/Media/TrackDescriptorSharedPtr.h"

namespace MediaGaps
{
	namespace Media
	{
		class MEDIAGAPS_EXPORTS_KEYWORD PictureTrackDescriptor : public TrackDescriptor
		{
			struct Impl;
			Impl* _impl;

		public:
			/** Constructor.*/
			PictureTrackDescriptor();

			/** Destructor */
			virtual ~PictureTrackDescriptor();

			/** Copy constructor. */
			PictureTrackDescriptor(const PictureTrackDescriptor&);

			/** Assignement operator */
			PictureTrackDescriptor& operator=(const PictureTrackDescriptor&);

			/** Returns the video width. */
			virtual UInt32* GetWidth() const;

			/** Sets the video width. */
			virtual void SetWidth(UInt32 width);

			/** Returns the video height. */
			virtual UInt32* GetHeight() const;

			/** Sets the video height. */
			virtual void SetHeight(UInt32 height);

			/** Returns the field height for progressive frame it'll be the same as height. */
			virtual UInt32* GetFieldHeight() const;

			/** Returns true if the video is interlace, false otherwise.*/
			virtual bool* GetInterlaced() const;

			/** Sets true if the video is interlace, false otherwise.*/
			virtual void SetInterlaced(bool interlaced);

			/** Returns the video aspect ratio. */
			virtual Rational32* GetAspectRatio() const;

			/** Sets the video aspect ratio. */
			virtual void SetAspectRatio(Rational32 aspectRatio);

			/** Returns the stream bit rate */
			virtual UInt32* GetBitRate() const;

			/** Sets the stream bit rate */
			virtual void SetBitRate(UInt32 bitRate) const;

			/** Returns the component depth */
			virtual UInt32* GetComponentDepth() const;

			/** Sets  the component_depth */
			virtual void SetComponentDepth(UInt32 componentDepth) const;

			/** Return the colorspace */
			virtual Colorspaces GetColorspace() const;

			/** Sets the colorspace */
			virtual void SetColorspace(Colorspaces colorspace) const;

			TrackDescriptorSharedPtr Clone() const;
		};
	}
}

#endif // _MEDIAGAPS_MEDIA_PICTURETRACKDESCRIPTOR_H_
