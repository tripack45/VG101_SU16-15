cmake_minimum_required(VERSION 3.5)
project(clion_example)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(S_DBG_MC debug_macro.c)

set(S_TEST random/test.c random/sum.c)

set(S_CTemplate
        CTemplate/main.c
        CTemplate/ex1.c
        CTemplate/ex2.c
        CTemplate/ex3.c
        CTemplate/ex4.c)

set (S_IO io/main.c)


add_executable(dbgMacro ${S_DBG_MC})

add_executable(ctemplate ${S_CTemplate})

add_executable(testcode ${S_TEST})

add_executable(io ${S_IO})