#include "invertedIndex.h"

void InvertedIndex::UpdateDocumentBase(std::vector<std::string> input_docs)
{
	std::string buffer;
	unsigned int cnt = 0;
	std::vector<Entry> entry;

	if (input_docs.empty())
	{
		std::cerr << "Warring!!! Indexing: no content in docs content base." << std::endl;
		return;
	}

	for (auto& it: input_docs)
	{
		for (int i = 0; i < it.length(); i++)
		{
			buffer += std::tolower(it[i]);
		}
		this->docs.emplace_back(buffer);
		buffer.clear();
	}


	freq_dictionary.clear();

	for (auto& it: this->docs)
	{
		std::string buffer = it;
		std::stringstream ss{ buffer };
		buffer.clear();
		while (ss >> buffer)
		{
			freq_dictionary.insert(std::make_pair(buffer, GetWordCount(buffer)));
		}
	}
}

std::vector<Entry> InvertedIndex::GetWordCount(const std::string& word)
{
	auto iterator = freq_dictionary.find(word);
	if (iterator != freq_dictionary.end())
	{

	}
}