#ifndef _MEDIAGAPS_TRANSPORTSTREAMENUMS_H_
#define _MEDIAGAPS_TRANSPORTSTREAMENUMS_H_

namespace MediaGaps
{
	enum
	{
		TS_PACKET_SIZE = 188
	};

	enum
	{
		MAX_PAT_PPS = 253
	};

	enum
	{
		TS_SYNC_VALUE = 0x47
	};

	enum PacketIds
	{
		PacketIds_NullPacket = 0x1FFF,
		PacketIds_PAT = 0x0,
		PacketIds_CAT = 0x01,
		PacketIds_TransportStreamDescriptionTable = 0x02,
		PacketIds_IPMP_ControlInformationTable = 0x03,
		PacketIds_Sdt_BAT_NIT = 0x11,
		PacketIds_EIT = 0x12,
		PacketIds_RST = 0x13,
		PacketIds_TDT_TOT = 0x14,
		PacketIds_ATSC_Tables = 0x1FFB,
	};
}

#endif // _MEDIAGAPS_TRANSPORTSTREAMENUMS_H_
