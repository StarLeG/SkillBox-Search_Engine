#include "invertedIndex.h"

void InvertedIndex::UpdateDocumentBase(std::vector<std::string>& input_docs)
{
	std::map<std::string, Entry> fileFreqDictionary;
	size_t docId = 0;

	if (input_docs.empty())
	{
		std::cerr << "Warring!!! Indexing: no content in docs content base." << std::endl;
		return;
	}

	for (auto& it: input_docs)
	{

		std::transform(it.begin(), it.end(), it.begin(), [](char const& c)
		{
			return std::tolower(c);
		});
		docs.emplace_back(it);
	}

	freq_dictionary.clear();


	for (auto& str: docs)
	{
		entry.doc_id = docId;
		entry.count = 1;

		std::istringstream ist(str);
		for (std::string word; ist >> word;)
		{
			std::pair<std::string, Entry> file_word_frequency{ word, entry };
			if (!fileFreqDictionary.emplace(file_word_frequency).second)
			{
				fileFreqDictionary.find(word)->second.count += 1;
			}

		}


		for (const auto& wordIterator: fileFreqDictionary)
		{
			std::pair<std::string, std::vector<Entry>> wordFrequency;
			wordFrequency.first = wordIterator.first;
			std::vector<Entry> entryVector{ wordIterator.second };
			wordFrequency.second = entryVector;
			if (!freq_dictionary.emplace(wordFrequency).second)
			{
				freq_dictionary.find(wordFrequency.first)->second.push_back(wordIterator.second);
			}
		}
		docId++;
		fileFreqDictionary.clear();

	}
}

std::vector<Entry> InvertedIndex::GetWordCount(const std::string& word)
{

	auto iterator = freq_dictionary.find(word);
	if (iterator != freq_dictionary.end())
	{

		return iterator->second;
	}
	else
	{
		return {};
	}

}
