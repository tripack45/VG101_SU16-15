cmake_minimum_required(VERSION 3.5)
project(ctemplate)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.c
        assignment.h
        ex1.c
        ex2.c
        ex3.c
        ex4.c)

add_executable(ctemplate ${SOURCE_FILES})