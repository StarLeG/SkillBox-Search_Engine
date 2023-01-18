#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <exception>

#include <nlohmann/json.hpp>


/**
* Структура для хранения параметров из файла config.json
*/
struct ConfigJson{
	struct {
		std::string name;
		std::string version;
		int max_responses;
	} config;
	std::vector<std::string> files;
};


/**
* Класс для работы с JSON-файлами
*/
class ConverterJSON
{
public:
	ConfigJson configJson;
	ConverterJSON();

/**
* Метод получения содержимого файлов
* @return Возвращает список с содержимым файлов перечисленных
* в config.json
*/
	std::vector<std::string> GetTextDocuments() const;

/**
* Метод считывает поле, "version", с названием поискового движка
* @return
*/
	std::string GetNameProgramm() const;

/**
* Метод считывает поле, "name",  с номером версии поискового движка
* @return
*/
	std::string GetVersionProgramm() const;

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

struct ConfigFileMissing : public std::exception {
	const char * what () const throw () {
		return "Config file is missing";
	}
};

struct ConfigFileEmpty : public std::exception {
	const char * what () const throw () {
		return "Config file is empty";
	}
};

struct IncorrectFileVersion : public std::exception {
	const char * what () const throw () {
		return "Incorrect file version";
	}
};
