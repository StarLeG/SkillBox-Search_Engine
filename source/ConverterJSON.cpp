#include "ConverterJSON.h"


ConverterJSON::ConverterJSON()
{
	this->readConfigFile();
	this->readRequestsFile();
}

bool ConverterJSON::readConfigFile()
{
	try
	{
		std::ifstream configFile("config.json");
		if (!configFile.is_open())
		{
			throw ConfigFileMissing();
		}

		configFile >> this->config;
		configFile.close();

		if (config["config"].is_null() || config["config"].empty())
		{
			throw  ConfigFileEmpty();
		}

		if(VERSION != config["config"]["version"])
		{
			throw IncorrectFileVersion();
		}

		if (!config["config"]["name"].is_null())
		{
			configJson.config.name = config["config"]["name"];
		}
		else
		{
			configJson.config.name = "Undefined";
		}

		if (!config["config"]["version"].is_null())
		{
			configJson.config.version = config["config"]["version"];
		}

		if (!config["config"]["max_responses"].is_null())
		{
			configJson.config.max_responses = config["config"]["max_responses"];
		}
		else
		{
			configJson.config.max_responses = 5;
		}

		for (auto it = config["files"].begin(); it != config["files"].end(); it++)
		{
			configJson.files.emplace_back(*it);
		}
	}
	catch(ConfigFileMissing& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch(ConfigFileEmpty& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return true;
}

bool ConverterJSON::readRequestsFile()
{
	std::ifstream RequestsFile("requests.json");
	if(!RequestsFile.is_open())
	{
		std::ofstream RequestsFile("requests.json");
		if(!RequestsFile.is_open())
		{
			std::cerr << "Requests file is missing" << std::endl;
			return false;
		}
		RequestsFile.close();
	}

}

std::string ConverterJSON::GetNameProgramm() const
{
	return configJson.config.name;
}

std::string ConverterJSON::GetVersionFile() const
{
	return configJson.config.version;
}

int ConverterJSON::GetResponsesLimit() const
{
	return configJson.config.max_responses;
}

std::vector<std::string> ConverterJSON::GetTextDocuments() const
{


}