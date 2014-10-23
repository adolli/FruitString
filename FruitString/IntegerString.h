
#ifndef _ADOLLI_INTEGERSTRING_
#define _ADOLLI_INTEGERSTRING_

#include "FruitString.hpp"
#include "BasicStringStorage.h"

namespace adolli
{

	template<>
	class CharTraits<int>
	{
	public:

		static const int TERMINATOR = 0;
		static const int UNIT_LENGTH = 1; 

		static bool lt(const int i1, const int i2)
		{
			return i1 < i2;
		}

		static bool eq(const int i1, const int i2)
		{
			return i1 == i2;
		}

		static int GetLenth(const int* s)
		{
			int n = 0;
			while (*s++ != TERMINATOR)
			{
				++n;
			}
			return n;
		}

	};

	typedef string<int, CharTraits<int>, StringStoragePolicy> i_string;

}

#endif  /*_ADOLLI_INTEGERSTRING_*/
