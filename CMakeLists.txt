cmake_minimum_required(VERSION 3.25)
project(EngineSearch VERSION 0.0.1)


set(CMAKE_CXX_STANDARD 17)
set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

set(CMAKE_PREFIX_PATH "\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.25.1")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_subdirectory(source)
add_subdirectory(lib/nlohmann_json)
add_subdirectory(tests)
add_subdirectory(lib/googletest)


target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(${PROJECT_NAME}  PRIVATE Qt5::Widgets)



file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/config.json    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/source)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/requests.json    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/source)






