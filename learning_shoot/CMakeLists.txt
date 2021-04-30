cmake_minimum_required(VERSION 3.0)
project(SOLIDERFIRE)
include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(main_cmake main.cpp src/Gun.cpp src/Solider.cpp)