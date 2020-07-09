#ifndef _MEDIAGAPS_TS_DEMUX_TSPARSER_H_
#define _MEDIAGAPS_TS_DEMUX_TSPARSER_H_

#include "MediaGaps/IO/SourceSharedPtr.h"
#include "MediaGaps/Ts/Demux/ProgramListenerProvider.h"
#include "MediaGaps/Media/IActionWithState.h"

namespace MediaGaps
{
	namespace Ts
	{
		namespace Demux
		{
			class MEDIAGAPS_EXPORTS_KEYWORD TSParser : public Media::IActionWithState
			{
				struct Impl;
				Impl* _impl;

			public:
				TSParser(IO::SourceSharedPtr source, ProgramListenerProvider& programListenerProvider);

				~TSParser();

				void Start() override;

				void Abort() override;

				ExceptionCode GetErrorCode() const override;

				const char* GetErrorMsg() const override;

				void SetErrorListener(IErrorListener* listener) override;

				State GetState() const override;

				void SetStateListener(Media::IStateListener* listener) override;

				float GetLoadedPercentage();
			};
		}
	}
}

#endif //_MEDIAGAPS_TS_DEMUX_TSPARSER_H_
