
#include <iostream>
#include <cstdlib>
#include "FruitString.hpp"
using adolli::string;
using adolli::NormalCharTraits;
using adolli::CICharTraits;
using adolli::IntCharTraits;



int main()
{
	std::cout << "hello world!" << std::endl;

	typedef string<char, NormalCharTraits> cd_string;
	typedef string<char, CICharTraits> ci_string;
	typedef string<int, IntCharTraits> ii_string;

	ii_string str0;
	str0.append(1, 1);
	std::cout<<str0.at(0)<<std::endl;
	if (str0[0] == 1)
	{
		std::cout<<"yes\n";
	}

	cd_string test;
	test.append(1, 'c');
	

	cd_string str1 = "apple";
	cd_string str2 = "APPle";
	ci_string str3 = "apple123";
	ci_string str4 = "APPLe123";

	
	if (!(str1 == str2) && str3 == str4)
	{
		std::cout<<"ok\n";
	}
	system("pause");
	return 0;
}
