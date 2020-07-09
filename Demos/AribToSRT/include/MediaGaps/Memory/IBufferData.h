#ifndef _MEDIAGAPS_MEMORY_IBUFFERDATA_H_
#define _MEDIAGAPS_MEMORY_IBUFFERDATA_H_

#include "MediaGaps/Types.h"
#include "MediaGaps/Exports.h"

namespace MediaGaps
{
    namespace Memory
    {
        class MEDIAGAPS_EXPORTS_KEYWORD IBufferData
        {
        public:

            /** Destructor.
            */
            virtual ~IBufferData();

            /** Pointer to the position where the sample is stored.
            */
            virtual const unsigned char* GetBuffer() const = 0;

            /** Returns the size of the sample
            */
            virtual UInt64 GetSize() const = 0;

			/** Returns the linesize of the sample. If the value is not know returns 0.
			*/
			virtual UInt64 GetLinesize() const = 0;
		};
    }
}
#endif //_MEDIAGAPS_MEMORY_IBUFFERDATA_H_
