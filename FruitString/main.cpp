
#include <iostream>
#include <cstdlib>
#include <cassert>
#include "CaseDependentString.h"
#include "CaseIndependentString.h"
#include "IntegerString.h"
using namespace adolli;


int main()
{
	std::cout << "hello world!" << std::endl;

	int iarray[] = { 1, 2, 3, 4, 5, 6, 0 } ;
	i_string str0 = iarray;
	assert(str0 == iarray);
	str0.append(4, 2);
	std::cout<<str0.at(0)<<std::endl;
	if (str0[7] == 2)
	{
		std::cout<<str0<<std::endl;
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
