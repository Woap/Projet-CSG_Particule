cmake_minimum_required(VERSION 3.0)
project(image LANGUAGES CXX)

file ( GLOB HEADERS *.h *.hpp)

file ( GLOB SOURCES *.cpp)

add_library(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../vectorMatrix )


target_link_libraries(${PROJECT_NAME} vector_matrix)

cmake_minimum_required(VERSION 3.0)

project(test_vec_mat LANGUAGES CXX)

add_executable(test_image testImage.cpp)

target_include_directories(test_image PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}//image)

target_link_libraries(test_image image )

