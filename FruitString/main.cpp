
#include <iostream>
#include <cstdlib>
#include <cassert>
#include "CaseDependentString.h"
#include "CaseIndependentString.h"
#include "IntegerString.h"
using namespace adolli;
using std::cout;
using std::endl;


int main()
{
	std::cout << "hello world!" << std::endl;

	int iarray[] = { 1, 2, 3, 4, 5, 6, 0 } ;
	i_string str0 = iarray;
	assert(str0 == iarray);
	str0.append(4, 2);
	cout << str0.at(0) <<endl;
	if (str0[7] == 2)
	{
		cout << str0 << endl;
	}

	cd_string test;
	test.append(1, 'c');
	

	cd_string str1 = "apple";
	cd_string str2 = "APPle";
	ci_string str3 = "aPple123";
	ci_string str4 = "APPLe123";
	cd_string str5 = str1;
	cout << str5 << endl;
	cout << str3 << endl;
	
	if (!(str1 == str2) && str3 == str4)
	{
		std::cout<<"ok\n";
	}
	system("pause");
	return 0;
}
