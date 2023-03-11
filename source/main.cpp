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


	SearchServer srv(ii);

	auto Requests = cj.GetRequests();

	auto Answer = srv.search(Requests);




	return 0;
}
