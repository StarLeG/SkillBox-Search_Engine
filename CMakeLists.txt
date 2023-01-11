cmake_minimum_required(VERSION 3.25)
project(EngineSearch)


set(CMAKE_CXX_STANDARD 17)
set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_subdirectory(source)
add_subdirectory(tests)
add_subdirectory(lib/googletest)











