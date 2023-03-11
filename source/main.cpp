#include <iostream>
#include "ConverterJSON.h"
#include "invertedIndex.h"
#include "SearchServer.h"



int main()
{
	ConverterJSON cj;
	InvertedIndex ii;


	std::cout << cj.GetNameProgramm() << std::endl;
	std::cout << "Program version: " << cj.GetVersionFile() << std::endl;

	auto text = cj.GetTextDocuments();
	ii.UpdateDocumentBase(text);



	return 0;
}
