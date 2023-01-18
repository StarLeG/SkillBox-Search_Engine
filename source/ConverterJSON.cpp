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
		else
		{
			configJson.config.version = "0.1";
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
	return config["config"]["max_responses"].get<int>();
}