#ifndef _MEDIAGAPS_CAPTIONS_SRT_SRTLISTENER_H_
#define _MEDIAGAPS_CAPTIONS_SRT_SRTLISTENER_H_

#include "MediaGaps/Captions/ISubtitleListener.h"

namespace MediaGaps
{
	namespace Captions
	{
		namespace SRT
		{
			class MEDIAGAPS_EXPORTS_KEYWORD SRTListener : public ISubtitleListener
			{
				struct Impl;
				Impl* _impl;

			public:
				explicit SRTListener(const wchar_t* filename);

				~SRTListener();

				void HandleNewSubtitle(const Subtitle& subtitle) override;

				void SetInitialTimestamp(UInt64 timestamp) override;
			};
		}
	}
}
#endif // _MEDIAGAPS_CAPTIONS_SRT_SRTLISTENER_H_
