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
			throw ConfigFileEmpty();
		}

		if (VERSION != config["config"]["version"])
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
	catch (ConfigFileMissing &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (ConfigFileEmpty &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return true;
}

bool ConverterJSON::readRequestsFile()
{

	std::ifstream RequestsFile("requests.json");
	if (!RequestsFile.is_open())
	{
		std::cerr << "Requests.json file was not found." << std::endl;
		return false;
	}
	else
	{
		RequestsFile >> this->requests;
		RequestsFile.close();
	}

	if(this->requests.empty())
	{
		std::cerr << "Requests.json File is empty." << std::endl;
		return false;
	}
	else if(this->requests["requests"].is_null())
	{
		return false;
	}
	else
	{
		for(auto it = requests["requests"].begin(); it != requests["requests"].end(); it++)
		{
			requestsJson.requests.emplace_back(*it);
		}
	}

	return true;
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
	std::vector<std::string> textDocuments;
	
	if(!configJson.files.empty())
	{
		for(int i = 0; i < configJson.files.size(); i++)
		{
			if(configJson.files[i].empty())
			{
				std::cerr << "There are no data" << std::endl;
			}
			else
			{
				std::ifstream path(configJson.files[i]);

				path.close();
			}
		}

	}
	else
	{
		std::cerr << "There are no data" << std::endl;
	}

	return textDocuments;
	
}