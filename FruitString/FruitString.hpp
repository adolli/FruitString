
#ifndef _ADOLLI_STRING_
#define _ADOLLI_STRING_
#include<ostream>
namespace adolli
{


	template< 
		class _CharT, 
		class _CharTraits, 
		template <class> class StoragePolicy > 
	class string
		: protected StoragePolicy<_CharT>
	{
	public:

		typedef _CharT CharT;
		typedef _CharTraits CharTraits;

		typedef typename StoragePolicy<CharT>::size_type size_type;
		typedef typename StoragePolicy<CharT>::pos_type pos_type;

		typedef string& RefType;
		typedef const string& ConstRefType;
		typedef CharT* RawArrayType;
		typedef const CharT* ConstRawArrayType;
		typedef CharT& CharRefType;
		typedef const CharT& ConstCharRefType;


		string()
			: StoragePolicy<CharT>()
		{}

		string(const CharT* str)
			: StoragePolicy<CharT>(str, CharTraits::GetLenth(str))
		{}

		string(const CharT* str, int len)
			: StoragePolicy<CharT>(str, len)
		{}

		string(const CharT c)
			: StoragePolicy<CharT>(c)
		{}

		string(const string& rhs)
			: StoragePolicy<CharT>(rhs)
		{}

		using StoragePolicy<CharT>::operator=;


		size_type Length() const
		{
			return Size() * CharTraits::UNIT_LENGTH;
		}

		

		RefType append(size_type n, const CharT c)
		{
			size_type oriSize = Length();
			Reserve(n);
			CharT* pc = data_ + oriSize;
			while (n--)
			{
				*pc++ = c;
			}
			*pc = CharTraits::TERMINATOR;
			return *this;
		}
		RefType append(ConstRefType str)
		{
			size_type oriSize = Length();
			size_type appendSize = str.Length();
			Reserve(appendSize);
			memcpy(data_ + oriSize, str.data_, appendSize + 1);
			return *this;
		}
		RefType append(ConstRawArrayType str)
		{
			size_type oriSize = Length();
			size_type appendSize = CharTraits::GetLenth(str);
			Reserve(appendSize);
			memcpy(data_ + oriSize, str, appendSize + 1);
			return *this;
		}
		RefType operator+=(ConstRefType str)
		{
			return append(str);
		}
		RefType operator+=(ConstRawArrayType str)
		{
			return append(str);
		}

		CharRefType at(pos_type n)
		{
			return Get(n);
		}
		const CharRefType at(pos_type n) const
		{
			return Get(n);
		}
		CharRefType operator[](pos_type n) const
		{
			return Get(n);
		}


		


		template< class StringType_OrRawStringType >
		int Compare(const StringType_OrRawStringType& str)
		{
			pos_type i = 0;
			while ((at(i) != CharTraits::TERMINATOR || str[i] != CharTraits::TERMINATOR) 
				&& CharTraits::eq(at(i), str[i]))
			{
				++i;
			}
			if (CharTraits::eq(this->at(i), str[i]))
			{
				return 0;
			}
			else if (CharTraits::lt(this->at(i), str[i]))
			{
				return -1;
			}
			else
			{
				return 1;
			}
		}


		using StoragePolicy<CharT>::Clear;


		string Substr(pos_type p);
		string Substr(pos_type p, size_type n);

	protected:

		using StoragePolicy<CharT>::Get;
		using StoragePolicy<CharT>::Reserve;
		using StoragePolicy<CharT>::Size;

		using StoragePolicy<CharT>::data_;

	};




	template< class StringType >
	bool operator==(const StringType& s1, const StringType& s2)
	{
		if (s1.Length() != s2.Length())
		{
			return false;
		}

		for (StringType::size_type i = 0; i < s1.Length(); ++i)
		{
			if (!StringType::CharTraits::eq(s1[i], s2[i]))
			{
				return false;
			}
		}
		return true;
	}

	template< class StringType >
	bool operator==(typename StringType::ConstRawArrayType s1, const StringType& s2)
	{
		typedef typename StringType::CharTraits CharTraits;
		StringType::size_type i = 0;
		for ( ; 
			i < s2.Length() && *s1 != StringType::CharTraits::TERMINATOR; 
			++i, ++s1)
		{
			if (!CharTraits::eq(*s1, s2[i]))
			{
				return false;
			}
		}
		if (*s1 != CharTraits::TERMINATOR || s2[i] != CharTraits::TERMINATOR)
		{
			return false;
		}
		return true;
	}

	template< class StringType >
	bool operator==(const StringType& s1, typename StringType::ConstRawArrayType s2)
	{
		return operator==<StringType>(s2, s1);
	}


	template< class StringType >
	bool operator!=(const StringType& s1, const StringType& s2)
	{
		return !operator==(s1, s2);
	}

	template< class StringType >
	bool operator!=(typename StringType::ConstRawArrayType s1, const StringType& s2)
	{
		return !operator==(s1, s2);
	}

	template< class StringType >
	bool operator!=(const StringType& s1, typename StringType::ConstRawArrayType s2)
	{
		return !operator==(s1, s2);
	}

	
	template< 
		class _CharT, 
		class _CharTraits, 
		template <class> class StoragePolicy > 
	std::ostream & operator<<(std::ostream & os, string<_CharT, _CharTraits, StoragePolicy> s)
	{
		for (int i=0;i<s.Length();i++)
		{
			os<<s[i];
		}
		return os;
	}
}

#endif  /*_ADOLLI_STRING_*/
