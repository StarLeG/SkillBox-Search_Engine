cmake_minimum_required(VERSION 3.24)



configure_file(
        ${MY_INCLUDE_DIR}/config.h.in
        ${CMAKE_CURRENT_BINARY_DIR}/config.h
)

file(GLOB
        CPP_SOURCES "*.cpp")

add_executable(${PROJECT_NAME} ${CPP_SOURCES}
                                ${MY_INCLUDE_DIR}/ConverterJSON.h
                                ${MY_INCLUDE_DIR}/config.h.in
                                ${MY_INCLUDE_DIR}/version.h  
                                ${MY_INCLUDE_DIR}/invertedIndex.h
                                ${MY_INCLUDE_DIR}/SearchServer.h)


target_include_directories(${PROJECT_NAME} PUBLIC ${MY_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR} )
