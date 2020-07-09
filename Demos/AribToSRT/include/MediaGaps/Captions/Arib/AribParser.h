#ifndef _MEDIAGAPS_CAPTIONS_ARIB_ARIBPARSER_
#define _MEDIAGAPS_CAPTIONS_ARIB_ARIBPARSER_

#include "MediaGaps/Captions/SubtitleListenerSharedPtr.h"

namespace MediaGaps
{
	namespace Captions
	{
		namespace Arib
		{
			class MEDIAGAPS_EXPORTS_KEYWORD AribParser :  public TimestampListener
			{
				struct Impl;
				Impl* _impl;

			public:
				explicit AribParser(SubtitleListenerSharedPtr listener, UInt16 packetId);

				~AribParser();

				UInt64 ProcessCaption(const unsigned char* data, int size);

				void SetInitialTimestamp(UInt64 timestamp) override;
			};
		}
	}
}

#endif //_MEDIAGAPS_CAPTIONS_ARIB_ARIBPARSER_
