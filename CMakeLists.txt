cmake_minimum_required(VERSION 3.5)
project(my_push_swap)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    checker.c
    header.h)

add_executable(my_push_swap ${SOURCE_FILES})