#include <iostream>
#include "ConverterJSON.h"
#include "invertedIndex.h"



int main()
{
	ConverterJSON cj;
	InvertedIndex ii;


	std::cout << cj.GetNameProgramm() << std::endl;
	std::cout << "Program version: " << cj.GetVersionFile() << std::endl;


	ii.UpdateDocumentBase(cj.GetTextDocuments());



	return 0;
}
