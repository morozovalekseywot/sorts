cmake_minimum_required(VERSION 3.19)
project(sorts)

set(CMAKE_CXX_STANDARD 20)

add_executable(sorts main.cpp Timsort.hpp MergeMachine.hpp MiniSort.h MergeSort.h Sorts.h)