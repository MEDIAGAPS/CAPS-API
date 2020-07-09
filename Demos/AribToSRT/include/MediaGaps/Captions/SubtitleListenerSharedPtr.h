#ifndef _MEDIAGAPS_CAPTIONS_SUBTITLELISTENERSHAREDPTR_H_
#define _MEDIAGAPS_CAPTIONS_SUBTITLELISTENERSHAREDPTR_H_

#include "MediaGaps/Captions/ISubtitleListener.h"
#include "MediaGaps/ISharedPtr.h"

namespace MediaGaps
{
	namespace Captions
	{
		class MEDIAGAPS_EXPORTS_KEYWORD SubtitleListenerSharedPtr : public ISharedPtr<ISubtitleListener, SubtitleListenerSharedPtr>
		{
			struct Impl;
			Impl* _impl;

		public:
			SubtitleListenerSharedPtr();

			explicit SubtitleListenerSharedPtr(ISubtitleListener* sample);

			SubtitleListenerSharedPtr(const SubtitleListenerSharedPtr& other);

			virtual SubtitleListenerSharedPtr& operator=(const SubtitleListenerSharedPtr& other);

			virtual bool operator==(const SubtitleListenerSharedPtr& other);

			~SubtitleListenerSharedPtr();

			virtual ISubtitleListener* Get() const;

			virtual ISubtitleListener* operator->() const;

			virtual ISubtitleListener& operator*() const;

			virtual void Reset();

			virtual void Reset(ISubtitleListener* sample);
		};
	}
}

#endif // _MEDIAGAPS_CAPTIONS_SUBTITLELISTENERSHAREDPTR_H_
