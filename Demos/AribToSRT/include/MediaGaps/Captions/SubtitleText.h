#ifndef _MEDIAGAPS_CAPTIONS_SUBTITLETEXT_H_
#define _MEDIAGAPS_CAPTIONS_SUBTITLETEXT_H_

#include "MediaGaps/Exports.h"
#include "MediaGaps/Types.h"

namespace MediaGaps
{
	namespace Captions
	{
		class MEDIAGAPS_EXPORTS_KEYWORD SubtitleText
		{
			struct Impl;
			Impl* _impl;
		public:
			SubtitleText();
			
			SubtitleText(const unsigned char* text, size_t size);

			SubtitleText(const SubtitleText& other);

			SubtitleText& operator=(const SubtitleText& other);

			~SubtitleText();

			const unsigned char* GetValue() const;

			void SetValue(const unsigned char* text, size_t size);

			size_t GetSize() const;
		};

	}
}
#endif // _MEDIAGAPS_CAPTIONS_SUBTITLETEXT_H_