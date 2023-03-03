cmake_minimum_required(VERSION 3.24.2)
project(EngineSearch VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

set(CMAKE_PREFIX_PATH "..\\..\\..\\..\\..\\cmake")
set(MY_SRC_DIR ${CMAKE_SOURCE_DIR}/source)

enable_testing()

add_subdirectory(source)
add_subdirectory(lib/nlohmann_json)
add_subdirectory(tests)
add_subdirectory(lib/googletest)





target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)





file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/config.json           DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/source)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/requests.json         DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/source)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources/text01.txt  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/source/resources)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources/text02.txt  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/source/resources)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources/text03.txt  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/source/resources)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources/text04.txt  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/source/resources)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources/text05.txt  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/source/resources)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources/text06.txt  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/source/resources)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources/text07.txt  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/source/resources)
