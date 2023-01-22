#include "invertedIndex.h"

void InvertedIndex::UpdateDocumentBase(std::vector<std::string> input_docs)
{
	std::string buffer;
	if(input_docs.empty())
	{
		std::cerr << "Warring!!! Indexing: no content in docs content base." << std::endl;
		return;
	}
		for(auto &it: input_docs)
		{
			for(int i = 0; i < it.length(); i++)
			{
				buffer += std::tolower(it[i]);
			}
			this->docs.emplace_back(buffer);
			buffer.clear();
		}

		for(auto &it : this->docs)
		{
			std::string buffer = it;
			std::stringstream ss{ buffer};
			buffer.clear();
			while(ss >> buffer)
			{
				auto iterator = freq_dictionary.find(buffer);

			}

		}


}

std::vector<Entry> InvertedIndex::GetWordCount(const std::string &word)
{

}