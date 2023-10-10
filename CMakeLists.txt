cmake_minimum_required(VERSION 3.26)
project(sorts C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
add_executable(sorts main.c
        bubblesort.c
        bubblesort.h
        picksort.c
        picksort.h
        sorts.c
        sorts.h)
