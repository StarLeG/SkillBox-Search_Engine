cmake_minimum_required(VERSION 3.25)
project(EngineSearch)


set(CMAKE_CXX_STANDARD 17)
set(JSON_BuildTests OFF CACHE INTERNAL "")
set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)


add_subdirectory(source)
add_subdirectory(tests)
add_subdirectory(lib/googletest)
add_subdirectory(lib/nlohmann_json)


target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/config.json    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/source)









