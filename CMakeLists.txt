cmake_minimum_required(VERSION 3.6)
project(algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp merge_sort.cpp basic.cpp basic.h quick_sort.cpp)
add_executable(algorithm ${SOURCE_FILES})