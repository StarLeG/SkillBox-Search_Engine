cmake_minimum_required(VERSION 3.25)
project(EngineSearch)

set(CMAKE_CXX_STANDARD 17)

set(Boost_INCLUDE_DIR "C:\\boost_1_81_0")
set(Boost_LIBRARY_DIR "C:\\boost_1_81_0\\stage\\lib")
set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)


find_package(Boost 1.81.0 COMPONENTS  REQUIRED )
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})
add_subdirectory(source)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARY_DIR})








