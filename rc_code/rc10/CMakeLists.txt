cmake_minimum_required(VERSION 3.5)
project(rc10)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES counterDV1.cpp)
set(COUNTER
        counterV1.cpp
        counterV2.cpp
        counterPro.cpp)

add_executable(rc10 ${SOURCE_FILES})

add_executable(abc abc.cpp)

add_executable(lifeSpan lifeSpan.cpp)

add_executable(file file.cpp)

add_executable(string string.cpp)

add_executable(counter_cstyle counter.c)
add_executable(counter_cpp counterDV1.cpp ${COUNTER})
add_executable(counterV2 counterDV2.cpp ${COUNTER})

add_executable(moo count.cpp ${COUNTER})