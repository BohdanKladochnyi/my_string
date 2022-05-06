#include <iostream>
#include <string>
#include "my_string.h"

int main()
{

	containers::String str1;
	containers::String str2("Hello, world!");
	for (size_t i = 0; i != str2.size(); ++i)
		std::cout << str2[i];
	std::cout << std::endl;

	containers::String str3 = str2;
	for (size_t i = 0; i != str3.size(); ++i)
		std::cout << str3[i];
	std::cout << std::endl;

	str1 = str3;
	for (size_t i = 0; i != str1.size(); ++i)
		std::cout << str1[i];
	std::cout << std::endl;
}