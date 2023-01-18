#include <iostream>
#include "ConverterJSON.h"



int main()
{
	ConverterJSON cj;

	std::cout << cj.configJson.config.name << std::endl;
	std::cout << cj.configJson.config.version << std::endl;
	std::cout << cj.configJson.config.max_responses << std::endl;

	for(int i = 0; i < cj.configJson.files.size(); i++)
	{
		std::cout << cj.configJson.files[i] << std::endl;
	}


	return 0;
}
