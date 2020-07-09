#ifndef _MEDIAGAPS_CAPTIONS_ARIB_ARIBPARSERSHAREDPTR_H_
#define _MEDIAGAPS_CAPTIONS_ARIB_ARIBPARSERSHAREDPTR_H_

#include "MediaGaps/Captions/Arib/AribParser.h"
#include "MediaGaps/ISharedPtr.h"

namespace MediaGaps
{
	namespace Captions
	{
		namespace Arib
		{
			class MEDIAGAPS_EXPORTS_KEYWORD AribParserSharedPtr : public ISharedPtr<AribParser, AribParserSharedPtr>
			{
				struct Impl;
				Impl* _impl;

			public:
				AribParserSharedPtr();

				explicit AribParserSharedPtr(AribParser* sample);

				AribParserSharedPtr(const AribParserSharedPtr& other);

				AribParserSharedPtr& operator=(const AribParserSharedPtr& other) override;

				virtual bool operator==(const AribParserSharedPtr& other);

				~AribParserSharedPtr();

				AribParser* Get() const override;

				AribParser* operator->() const override;

				AribParser& operator*() const override;

				void Reset() override;

				void Reset(AribParser* sample) override;
			};
		}
	}
}

#endif // _MEDIAGAPS_CAPTIONS_ARIB_ARIBPARSERSHAREDPTR_H_
