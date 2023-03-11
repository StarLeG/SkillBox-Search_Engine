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


	ii.UpdateDocumentBase(cj.GetTextDocuments());


	SearchServer srv(ii);

	auto Requests = cj.GetRequests();

	auto Answer = srv.search(Requests);

	cj.putAnswers(Answer);


	return 0;
}
