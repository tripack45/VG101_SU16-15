cmake_minimum_required(VERSION 3.5)
project(mid2rev)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(Scratch scratch.c)

add_executable(MidRvEx2 mid2.c)
add_executable(MidRvEx2_ans mid2_ans.c)

add_executable(Hw6_ex1 hw6_ex1.c)

add_executable(Hw6_mat hw6_matrix.c)

add_executable(ASCII ascii.c)