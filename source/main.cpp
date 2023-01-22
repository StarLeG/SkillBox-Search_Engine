#include <iostream>
#include "ConverterJSON.h"



int main()
{
	ConverterJSON cj;

	std::cout << cj.configJson.config.name << std::endl;
	std::cout << "Program version: " << cj.configJson.config.version << std::endl;


	return 0;
}
