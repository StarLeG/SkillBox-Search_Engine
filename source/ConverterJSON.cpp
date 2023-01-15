#include "ConverterJSON.h"



ConverterJSON::ConverterJSON()
{
	this->readConfigFile();
}

std::vector<std::string> ConverterJSON::GetTextDocuments() const
{


}

bool ConverterJSON::readConfigFile()
{
	std::ifstream configFile("config.json");
	if(!configFile.is_open())
	{
		std::cerr << "Error open config file" << std::endl;
		return 0;
	}
	configFile >> this->config;
	configFile.close();
	return 1;
}

std::string ConverterJSON::GetNameProgramm() const
{
	return config["config"]["name"].get<std::string>();
}

std::string ConverterJSON::GetVersionProgramm() const
{
	return config["config"]["version"].get<std::string>();
}

int ConverterJSON::GetResponsesLimit() const
{

	const int defaultResponsesLimit = 5;
	if(config["config"]["max_responses"].is_null())
	{
		return defaultResponsesLimit;
	}
	else
	{
		return config["config"]["max_responses"].get<int>();
	}
}