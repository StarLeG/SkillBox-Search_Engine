#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <exception>

#include <nlohmann/json.hpp>

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
* Метод считывает поле max_responses для определения предельного
* количества ответов на один запрос
* @return
*/
	int GetResponsesLimit() const;

/**
* Метод получения запросов из файла requests.json
* @return возвращает список запросов из файла requests.json
*/
	std::vector<std::string> GetRequests();

/**
* Положить в файл answers.json результаты поисковых запросов
*/
	void putAnswers(std::vector<std::vector<std::pair<int, float>>>
	answers);

private:

	nlohmann::json config;

	bool readConfigFile();
};
