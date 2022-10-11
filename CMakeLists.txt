cmake_minimum_required(VERSION 3.23)
project(Matrix_Lab)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Matrix_Lab
        main.cpp
        Matrix.cpp
        Matrix.h)
