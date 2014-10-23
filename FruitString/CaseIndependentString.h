
#ifndef _ADOLLI_CASEINDEPENDENTSTRING_
#define _ADOLLI_CASEINDEPENDENTSTRING_

#include "CaseDependentString.h"

namespace adolli
{


	class CICharTraits
		: public CharTraits<char>
	{
	public:


		// override
		static bool lt(const char c1, const char c2)
		{
			return toupper(c1) < toupper(c2);
		}

		// override
		static bool eq(const char c1, const char c2)
		{
			return toupper(c1) == toupper(c2);
		}

	};

	typedef string<char, CICharTraits, StringStoragePolicy> ci_string;
}

#endif  /*_ADOLLI_CASEINDEPENDENTSTRING_*/
