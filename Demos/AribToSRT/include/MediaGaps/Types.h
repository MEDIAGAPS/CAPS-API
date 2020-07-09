#ifndef _MEDIAGAPS_TYPES_H_
#define _MEDIAGAPS_TYPES_H_

#include "MediaGaps/Compiler.h"

namespace MediaGaps
{
    enum ExceptionCode
    {
        ExceptionCode_None = 0,
        ExceptionCode_Unknown = 1,
        ExceptionCode_UnableToLoadAAFCOAPI = 2,
        ExceptionCode_UnableToLoadInputFile = 3,
        ExceptionCode_UnableToCreateAAFTemporaryFile = 4,
        ExceptionCode_UnableToLoadAAFTemporaryFile = 5,
        ExceptionCode_UnableToSaveDataInTemporaryFile = 6,
        ExceptionCode_ErrorClosingAAF = 7,
        ExceptionCode_UnableToCopyAAFToFinalDestination = 8,
        ExceptionCode_UnableToLoadMetadataFromFile = 9,
        ExceptionCode_InvalidMasterMobCountFoundInFile = 10,
        ExceptionCode_TryingToAddMetadataToClosedFile = 11,
        ExceptionCode_UpdatingDictionary = 12,
        ExceptionCode_AddingDataToFile = 13,
        ExceptionCode_SystemResource = 14,
        ExceptionCode_InvalidParameters = 15,
        ExceptionCode_ErrorUpdatingMetadata = 16,
        ExceptionCode_TryingToAddSubClipTwice = 17,
        ExceptionCode_ProductIdNotRegistered = 18,
        ExceptionCode_IO_Error = 19,
        ExceptionCode_UnexpectedFileStructure = 20,
        ExceptionCode_UnsupportedFormat = 21,
        ExceptionCode_NotImplemented = 22,
        ExceptionCode_ParseError = 23,
        ExceptionCode_InvalidState = 24,
        ExceptionCode_SignalError = 25,
        ExceptionCode_InvalidLicense = 26,
		ExceptionCode_InvalidMxfFile = 27,

    };

#if defined MEDIAGAPS_COMPILER_WIN

    /** Unsigned 64-bit integer */
    typedef unsigned __int64 UInt64;

    /** Signed 64-bit integer */
    typedef __int64 Int64;

#elif defined MEDIAGAPS_COMPILER_GCC

    /** Unsigned 64-bit integer */
    typedef unsigned long long UInt64;

    /** Signed 64-bit integer */
    typedef long long Int64;

#endif

    /** Signed 64-bit integer */

    /** Unsigned 32-bit integer */
    typedef unsigned int UInt32;

    /** Signed 32-bit integer */
    typedef int Int32;

    /** Unsigned 16-bit integer */
    typedef unsigned short int UInt16;

    /** Signed 16-bit integer */
    typedef short int Int16;

    /** Unsigned 8-bit integer */
    typedef unsigned char UInt8;

    /** Signed 8-bit integer */
    typedef char Int8;

    /** WChar character. */
    typedef wchar_t WChar;

	typedef UInt32 Net_UInt32;

	typedef UInt16 Net_UInt16;

    /** Defines a rational number.
    */
    struct Rational32
    {
        Rational32()
            : Numerator(0),
              Denominator(1) { }

        Rational32(Int32 num, Int32 den)
            : Numerator(num),
              Denominator(den) { }

        /** Numerator of the rational number. */
        Int32 Numerator;

        /** Denominator of the rational number.*/
        Int32 Denominator;

        Int32 Round() const
        {
            if (Denominator == 0) return 0;

            return (Numerator + Denominator - 1) / Denominator;
        }
    };

    inline bool operator==(const Rational32& lhs, const Rational32& rhs)
    {
        if (lhs.Numerator != rhs.Numerator) return false;
        if (lhs.Denominator != rhs.Denominator) return false;

        return true;
    }
}

#endif // _MEDIAGAPS_TYPES_H_
