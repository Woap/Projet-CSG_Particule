cmake_minimum_required(VERSION 3.0)

project(test_image LANGUAGES CXX)


add_executable(test_image testImage.cpp)

target_include_directories(test_image PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/..)

target_link_libraries(test_image image )
