#include "ProgramListenerAdapter.h"

using namespace MediaGaps::Ts;
using namespace MediaGaps;

ProgramListenerAdapter::
ProgramListenerAdapter(ProgramListener& programListener) : _programListener(programListener) { }

void ProgramListenerAdapter::HandlePMT(const PmtData& data)
{
	_programListener.HandlePMT(data);
}

void ProgramListenerAdapter::HandlePESPacket(UInt16 packetId, const unsigned char* data, UInt64 size)
{
	_programListener.HandlePESPacket(packetId, data, size);
}
