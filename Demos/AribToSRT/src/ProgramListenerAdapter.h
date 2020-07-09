#ifndef _PROGRAMLISTENERADAPTER_H_
#define _PROGRAMLISTENERADAPTER_H_

#include "MediaGaps/Ts/Demux/ProgramListener.h"

namespace MediaGaps
{
	class ProgramListenerAdapter : public Ts::Demux::ProgramListener
	{
		ProgramListener& _programListener;
	public:
		explicit ProgramListenerAdapter(ProgramListener& programListener);
		
		void HandlePMT(const Ts::PmtData& data) override;

		void HandlePESPacket(UInt16 packetId, const unsigned char* data, UInt64 size) override;
		
	};
}
#endif // _PROGRAMLISTENERADAPTER_H_