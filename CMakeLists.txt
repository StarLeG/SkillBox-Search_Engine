cmake_minimum_required(VERSION 3.26.0)
project(EngineSearch VERSION 0.0.1)



set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

set(CMAKE_PREFIX_PATH "..\\..\\..\\..\\..\\cmake")
set(MY_SRC_DIR ${CMAKE_SOURCE_DIR}/source)

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()

add_subdirectory(source)
add_subdirectory(tests)

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
