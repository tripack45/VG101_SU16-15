cmake_minimum_required(VERSION 3.5)
project(clion_example)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c)

add_executable(clion_example ${SOURCE_FILES})