#ifndef _MEDIAGAPS_MEDIA_ISTATE_PROVIDER_H_
#define _MEDIAGAPS_MEDIA_ISTATE_PROVIDER_H_

#include "MediaGaps/Media/IStateListener.h"

namespace MediaGaps
{
	namespace Media
	{
		/** Base interface for returning state and error information.
		*/
		class MEDIAGAPS_EXPORTS_KEYWORD IStateProvider : public IErrorInfoProvider
		{
		public:
			enum State
			{
				State_Starting = 0,
				State_Running,
				State_Failed,
				State_Finished,
				State_Aborted,
				State_Stopping,
			};

			virtual ~IStateProvider();

			/** Returns the current state.
			*/
			virtual State GetState() const = 0;

			/** Sets class for listining to updates in state.
			*/
			virtual void SetStateListener(IStateListener* listener) = 0;
		};
	}
}

#endif // _MEDIAGAPS_MEDIA_ISTATE_PROVIDER_H_
