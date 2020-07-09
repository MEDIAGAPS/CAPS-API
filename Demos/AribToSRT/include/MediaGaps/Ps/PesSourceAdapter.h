#ifndef _MEDIAGAPS_PS_PESSOURCEADAPTER_H_
#define _MEDIAGAPS_PS_PESSOURCEADAPTER_H_

#include "MediaGaps/Exports.h"
#include "MediaGaps/IO/ISource.h"
#include "MediaGaps/Ts/PtsListener.h"
#include "MediaGaps/Memory/BufferDataSharedPtr.h"

namespace MediaGaps
{
	namespace Ps
	{
		class MEDIAGAPS_EXPORTS_KEYWORD PesSourceAdapter : public IO::ISource, public Ts::PtsListener
		{
			struct Impl;
			Impl* _impl;

		public:
			PesSourceAdapter(Memory::BufferDataSharedPtr value, UInt64 initialPts);

			virtual ~PesSourceAdapter();

			UInt64 Read(unsigned char* buffer, UInt64 size) override;

			UInt64 GetAbsoluteOffset() const override;

			bool HasFinished() const override;

			void NewPts(UInt64 pts) override;

			void SkipData(UInt64 amountData) override;

			bool IsHeaderStart() const;
		};
	}
}

#endif //_MEDIAGAPS_PS_PESSOURCEADAPTER_H_
