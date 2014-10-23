
#ifndef _ADOLLI_CASEDEPENDENTSTRING_
#define _ADOLLI_CASEDEPENDENTSTRING_

#include "FruitString.hpp"
#include "BasicStringStorage.h"
#include "CharTraits.h"

namespace adolli
{


	template<>
	class CharTraits<char>
	{
	public:

		static const char TERMINATOR = '\0';
		static const int UNIT_LENGTH = 1; 

		static bool lt(const char c1, const char c2)
		{
			return c1 < c2;
		}

		static bool eq(const char c1, const char c2)
		{
			return c1 == c2;
		}

		static int GetLenth(const char* s)
		{
			int n = 0;
			while (*s++ != TERMINATOR)
			{
				++n;
			}
			return n;
		}

	};

	typedef string<char, CharTraits<char>, StringStoragePolicy> cd_string;
}

#endif  /*_ADOLLI_CASEDEPENDENTSTRING_*/
