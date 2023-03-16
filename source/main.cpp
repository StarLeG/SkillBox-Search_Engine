#include <iostream>
#include "ConverterJSON.h"
#include "InvertedIndex.h"
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

	auto answer = std::vector<std::vector<std::pair<int, float>>>();

	answer.resize(Answer.size());

	int index = 0;

	for(const auto& it : Answer )
	{
		std::vector<std::pair<int, float>> ans;
		for(int i = 0; i < it.size();i++)
		{
			ans.resize(it.size());
			ans[i].first = it[i].doc_id;
			ans[i].second = it[i].rank;
		}

		answer[index] = ans ;
		index++;
	}

	cj.PutAnswers(answer);


	return 0;
}
