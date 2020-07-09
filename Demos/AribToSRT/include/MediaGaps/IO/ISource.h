#ifndef _MEDIAGAPS_IO_ISOURCE_H_
#define _MEDIAGAPS_IO_ISOURCE_H_

#include "MediaGaps/Types.h"
#include "MediaGaps/Exports.h"

namespace MediaGaps
{
	namespace IO
	{
		/** This is a base class for source.
		  */
		class MEDIAGAPS_EXPORTS_KEYWORD ISource
		{
		public:
			virtual ~ISource();

			/** Return the source absolute position.
			  */
			virtual UInt64 GetAbsoluteOffset() const = 0;

			/** Reads a data from the source.
			  * \param buffer location where data will be written.
			  * \param size return the actual read size.
			  */
			virtual UInt64 Read(unsigned char* buffer, UInt64 size) = 0;

			/** Skips a given amount of data in the source . 
			  * \param amountData the number of bytes to be discarded.
			  */
			virtual void SkipData (UInt64 amountData) = 0;

			virtual bool HasFinished() const = 0;

		};
	}
}

#endif // _MEDIAGAPS_IO_ISOURCE_H_
