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
		std::cerr << "Configfile is missing." << std::endl;
		return false;
	}

	configFile >> this->config;
	configFile.close();

	if(config["config"].is_null())
	{
		std::cerr << "Config file is empty." << std::endl;
		return false;
	}

	if(!config["config"]["name"].is_null()){
		configJson.config.name = config["config"]["name"];
	}else{
		configJson.config.name = "Undefined";
	}

	if(!config["config"]["version"].is_null()) {
		configJson.config.version = config["config"]["version"];
	}else{
		configJson.config.version = "0.1";
	}

	if(!config["config"]["max_responses"].is_null()){
		configJson.config.max_responses = config["config"]["max_responses"];
	}else{
		configJson.config.max_responses = 5;
	}

	for (auto it =config["files"].begin(); it != config["files"].end(); it++) {
		configJson.files.emplace_back(*it);
	}

	return true;
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