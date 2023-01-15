#include <iostream>
#include "ConverterJSON.h"



int main()
{
	ConverterJSON cj;

	std::cout << cj.GetNameProgramm() << std::endl;
	std::cout << cj.GetVersionProgramm() << std::endl;


	return 0;
}
