cmake_minimum_required(VERSION 3.15)
project(IA)

set(CMAKE_CXX_STANDARD 14)

include_directories(header)

add_executable(IA
        header/DEA.h
        src/DEA.cpp
        main.cpp)
