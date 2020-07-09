#ifndef _MEDIAGAPS_TS_DEMUX_PROGRAMLISTENERSHAREDPTR_H_
#define _MEDIAGAPS_TS_DEMUX_PROGRAMLISTENERSHAREDPTR_H_

#include "MediaGaps/Ts/Demux/ProgramListener.h"
#include "MediaGaps/ISharedPtr.h"

namespace MediaGaps
{
	namespace Ts
	{
		namespace Demux
		{
			class MEDIAGAPS_EXPORTS_KEYWORD
					ProgramListenerSharedPtr : public ISharedPtr<ProgramListener, ProgramListenerSharedPtr>
			{
				struct Impl;
				Impl* _impl;

			public:
				ProgramListenerSharedPtr();

				explicit ProgramListenerSharedPtr(ProgramListener* sample);

				ProgramListenerSharedPtr(const ProgramListenerSharedPtr& other);

				ProgramListenerSharedPtr& operator=(const ProgramListenerSharedPtr& other) override;

				virtual bool operator==(const ProgramListenerSharedPtr& other);

				~ProgramListenerSharedPtr();

				ProgramListener* Get() const override;

				ProgramListener* operator->() const override;

				ProgramListener& operator*() const override;

				void Reset() override;

				void Reset(ProgramListener* sample) override;
			};
		}
	}
}

#endif // _MEDIAGAPS_TS_DEMUX_PROGRAMLISTENERSHAREDPTR_H_
