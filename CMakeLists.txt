cmake_minimum_required(VERSION 3.28)
project(AnagramsFinder)

set(CMAKE_CXX_STANDARD 17)

add_executable(AnagramsFinder main.cpp
        Dictionary.cpp
        Dictionary.h
        Word.h
        Solver.cpp
        Solver.h)
