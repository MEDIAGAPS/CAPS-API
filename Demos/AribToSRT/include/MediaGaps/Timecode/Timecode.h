#ifndef _MEDIAGAPS_TIMECODE_TIMECODE_H_
#define _MEDIAGAPS_TIMECODE_TIMECODE_H_

#include "MediaGaps/Types.h"
#include "MediaGaps/Exports.h"
#include "MediaGaps/Time.h"

namespace MediaGaps
{
    class MEDIAGAPS_EXPORTS_KEYWORD Timecode
    {
        struct Impl;
        Impl* _impl;

    public:
        /** Creates a timecode just setting the rounded frame rate and drop_frame.
          * \param frame_rate the timecode frame rate, this is the equivalent to number of frames per second 
          * \param drop_frame indicates if timecode should take in account drop frames
          */
        Timecode(UInt16 frameRate, bool dropFrame);

        /** Creates a timecode from a 12m representation (without binary groups).
          * \param frame_rate the timecode frame rate, this is the equivalent to number of frames per second 
          * \param timecode_12m 12m representation of the timecode
          */
        Timecode(UInt16 frameRate, UInt32 timecode12M);

        /** Creates a timecode from the time components.
          * \param frame_rate the rounded frame rate, e.g.: 25, 30, etc
          * \param hours the hours component
          * \param minutes the minutes component
          * \param seconds the seconds component
          * \param frames the frames component
          * \param field_mark identifies the frame of pair when existent, false for first frame, true for second frame of pair. This is used for rates of 50 or 60.
          * \param drop_frame indicates if timecode should take in account drop frames
          */
        Timecode(UInt16 frameRate, UInt8 hours, UInt8 minutes, UInt8 seconds, UInt8 frames, bool dropFrame, bool fieldMark = false);

        /** Creates a timecode from the time components excepting the frame filed.
          * \param frame_rate the rounded frame rate, e.g.: 25, 30, etc
          * \param hours the hours component
          * \param minutes the minutes component
          * \param seconds the seconds component
          * \param drop_frame indicates if timecode should take in account drop frames
          */
        Timecode(UInt16 frameRate, UInt8 hours, UInt8 minutes, UInt8 seconds, bool dropFrame);

        /** Creates a timecode from frame count.
          * \param frame_rate the rounded frame rate, e.g.: 25, 30, etc
          * \param frame_count the frame to used in timecode
          * \param drop_frame indicates if timecode should take in account drop frames
          */
        Timecode(UInt16 frameRate, Int64 frameCount, bool dropFrame);

        /** Creates a timecode from a time struct.
          * \param frame_rate the rounded frame rate, e.g.: 25, 30, etc
          * \param time the time to be used to calculate the timecode
          * \param drop_frame indicates if timecode should take in account drop frames
          */
        Timecode(UInt16 frameRate, TimeData time, bool dropFrame);

        /** Copy constructor.
          */
        Timecode(const Timecode&);

        /** Assignement operator
          */
        Timecode& operator=(const Timecode&);

        /** Destructor
          */
        virtual ~Timecode();

        /** Returns the rounded frame rate.
          */
        UInt16 GetFrameRate() const;

        /** Returns the hours value.
          */
        UInt8 GetHours() const;

        /** Returns the minutes value.
          */
        UInt8 GetMinutes() const;

        /** Returns the seconds value.
          */
        UInt8 GetSeconds() const;

        /** Returns the frames value.
          */
        UInt8 GetFrames() const;

        /** Indicates if this is the first or second frame of the pair if existent.
          */
        bool GetFieldMark() const;

        /** Returns the number of frames of the timecode, this value may be negative or exceed the 24h period
         */
        Int64 GetFrameCount() const;

        /** Returns the absolute timecode, this will always be between 0 and 24h
         */
        Int64 GetAbsoluteFrameCount() const;

        /** Returns the drop frame indication.
          */
        bool GetDropFrame() const;

        /** Returns the timecode in a 12M representation.
          * Currently binary groups are not represented.
          */
        UInt32 Get12M() const;

        /** Increment operator.
          */
        void operator++();

        /** Decrement operator.
          */
        void operator--();

        /** Comparison operators. 
        */
        bool operator==(const Timecode& other);
        bool operator!=(const Timecode& other);

        /** Add a given number of frames to the current timecode, if the value the frame count will be decremented.
          */
        void Add(Int64 value);

        enum DropFrameIndication
        {
            DropFrameIndication_Semicolon = 0,
        };

        enum FieldMarkIndication
        {
            FieldMarkIndication_SMPTE = 0,
            FieldMarkIndication_DoubleFrameCount
        };

        const wchar_t* text(DropFrameIndication dropFrameIndication = DropFrameIndication_Semicolon, FieldMarkIndication fieldMarkIndication = FieldMarkIndication_SMPTE) const;

        const char* c_str(DropFrameIndication dropFrameIndication = DropFrameIndication_Semicolon, FieldMarkIndication fieldMarkIndication = FieldMarkIndication_SMPTE) const;
    };
}

#endif // _MEDIAGAPS_TIMECODE_TIMECODE_H_
