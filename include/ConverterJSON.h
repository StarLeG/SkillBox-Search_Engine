#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <exception>
#include "version.h"

#include <nlohmann/json.hpp>

/**
 * Структура для хранения параметров из файла config.json
 */
struct ConfigJson
{
	struct
	{
		std::string name;
		std::string version;
		int max_responses;
	} config;
	std::vector<std::string> files;
};

/**
 * Структура для хранения параметров для файла request.json
 */
struct RequestsJson
{
	std::vector<std::string> requests;
};

/**
 * Класс для работы с JSON-файлами
 */
class ConverterJSON
{
public:


	ConverterJSON();

	/**
	 * Метод получения содержимого файлов
	 * @return Возвращает список с содержимым файлов перечисленных
	 * в config.json
	 */
	std::vector<std::string> GetTextDocuments() const;

	/**
	 * Метод считывает поле, "name", с названием поискового движка
	 * @return
	 */
	std::string GetNameProgramm() const;

	/**
	 * Метод считывает поле, "version",  с номером версии поискового движка
	 * @return
	 */
	std::string GetVersionFile() const;

	/**
	 * Метод считывает поле max_responses для определения предельного
	 * количества ответов на один запрос
	 * @return
	 */
	int GetResponsesLimit() const;

	/**
	 * Метод получения запросов из файла requests.json
	 * @return возвращает список запросов из файла requests.json
	 */
	std::vector<std::string> GetRequests() const;

	/**
	 * Положить в файл answers.json результаты поисковых запросов
	 */
	void putAnswers(std::vector<std::vector<std::pair<int, float>>>
						answers);

private:
	nlohmann::json config;
	nlohmann::json requests;
	ConfigJson configJson;
	RequestsJson requestsJson;

	/**
	 * Метод получения запросов из файла requests.json
	 * @return
	 */
	bool readConfigFile();

	/**
	 * Метод получения запросов из файла requests.json
	 * @return 
	 */
	bool readRequestsFile();
};

struct ConfigFileMissing : public std::exception
{
	const char *what() const throw()
	{
		return "Config file is missing";
	}
};

struct ConfigFileEmpty : public std::exception
{
	const char *what() const throw()
	{
		return "Config file is empty";
	}
};

struct IncorrectFileVersion : public std::exception
{
	const char *what() const throw()
	{
		return "Incorrect file version";
	}
};
