# Поисковый движок

Поисковый движок  представляет из себя консольное приложение,
осуществляющее поиск среди набора документов и имеет возможность
настройки через файл формата JSON

## Принципы работы поискового движка

1. В конфигурационном файле формата JSON задаются названия
   файлов, по которым движок будет осуществлять поиск.
2. Поисковый движок  самостоятельно обходит все файлы и
   индексироват их, чтобы потом по любому поисковому запросу находить наиболее
   релевантные документы.
3. Пользователь задаёт запрос через JSON-файл requests.json. Запрос — это
   набор слов, по которым нужно найти документы.
4. Запрос трансформируется в список слов.
5. В индексе ищутся те документы, на которых встречаются все эти слова.
6. Результаты поиска ранжируются, сортируются и отдаются пользователю,
   максимальное количество возможных документов в ответе задаётся в
   конфигурационном файле.
7. В конце программа формирует файл answers.json, в который записывает
   результаты поиска.

## Поисковый движек использует нижеследующие технологии:

[C++17](https://en.cppreference.com/w/cpp/17)

[CMake 3.26](https://cmake.org/cmake/help/latest/release/3.26.html)

[Nlohmann JSON](https://github.com/nlohmann/json)

[GoogleTest](https://github.com/google/googletest)

[Mingw-w64](https://www.mingw-w64.org/)

## Описание файлов:

## Класс ConverterJSON:

```C++
#include <ConverterJSON.h>
```

### Конструктор

## ConverterJSON()

```c++
ConverterJSON::ConverterJSON()
```


Класс для работы с JSON-файлами

## **Методы:**

### GetNameProgramm()
```C++
std::string ConverterJSON::GetNameProgramm()const
```
Метод считывает поле, "name", с конфигурационного файла

**Возвращает**
строку с названием поискового движка

### GetRequests()

```C++
std::vector< std::string > ConverterJSON::GetRequests() const
```
Метод получения запросов из файла requests.json

**Возвращает**
возвращает список запросов из файла requests.json

### GetResponsesLimit()

```C++
int ConverterJSON::GetResponsesLimit() const
```
Метод считывает поле max_responses из конфигурационного файла

**Возвращает**
количества ответов на один запрос

### GetTextDocuments()

```C++
std::vector< std::string > ConverterJSON::GetTextDocuments() const
```
Метод получения содержимого файлов

**Возвращает**
Возвращает список с содержимым файлов перечисленных в config.json

### GetVersionFile()

```c++
std::string ConverterJSON::GetVersionFile()	const
```

Метод считывает поле, "version", с конфигурационного файла

**Возвращает**
строку с номером версии поискового движка

###  PutAnswers()

```c++
static void ConverterJSON::PutAnswers(const std::vector< std::vector< std::pair<int, float>>> &answers)	
```

Положить в файл answers.json результаты поисковых запросов


## Класс InvertedIndex

```c++
#include <InvertedIndex.h>
```

## Конструктор

### InvertedIndex()

```c++
nvertedIndex::InvertedIndex	()	
```

## **Методы:**

### GetWordCount()

```c++
std::vector< Entry > InvertedIndex::GetWordCount(const std::string &word)	
```

Метод определяет количество вхождений слова `word` в загруженной базе документов

**Аргументы**
`word`	слово, частоту вхождений которого необходимо определить
**Возвращает**
возвращает подготовленный список с частотой слов

### UpdateDocumentBase()

```c++
void InvertedIndex::UpdateDocumentBase(std::vector< std::string> &input_docs)	
```

Обновить или заполнить базу документов, по которой будем совершать поиск

**Аргументы**
`texts_input`	содержимое документов

## Класс SearchServer

```c++
#include <SearchServer.h>
```

## Конструктор

### SearchServer()

```c++
SearchServer::SearchServer(InvertedIndex &idx)
```

**Аргументы**
`idx`	в конструктор класса передаётся ссылка на класс `InvertedIndex`, чтобы `SearchServer` мог узнать частоту слов встречаемых в запросе


## **Методы:**

### search()

```c++
std::vector<std::vector<RelativeIndex>> SearchServer::search(const std::vector<std::string> &queries_input)
```
Метод обработки поисковых запросов

**Аргументы**
`queries_input`	поисковые запросы взятые из файла requests.json

**Возвращает**
возвращает отсортированный список релевантных ответов для заданных запросов