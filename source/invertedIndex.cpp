#include "invertedIndex.h"

void InvertedIndex::UpdateDocumentBase(std::vector<std::string> input_docs)
{
	std::string buffer;
	size_t doc_id = 0;
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
			auto iterator = freq_dictionary.find(buffer);
			if (iterator == freq_dictionary.end())
			{
				entry.resize(1);
				entry[0].doc_id = doc_id;
				entry[0].count = 1;
				freq_dictionary.emplace(buffer,entry);
			}
			else
			{

			}

		}
		doc_id++;

	}


}

std::vector<Entry> InvertedIndex::GetWordCount(const std::string& word)
{
	auto iterator = freq_dictionary.find(word);
	if (iterator != freq_dictionary.end())
	{

	}
}