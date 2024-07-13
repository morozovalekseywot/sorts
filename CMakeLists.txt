cmake_minimum_required(VERSION 3.19)
project(sorts)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(sorts main.cpp Timsort.hpp MergeMachine.hpp InsertSort.h MergeSort.h Sorts.h generate.h ISorter.h
        HoarSort.hpp CountSort.hpp)