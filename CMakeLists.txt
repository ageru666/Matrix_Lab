cmake_minimum_required(VERSION 3.23)
project(Matrix_Lab)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

set(Boost_INCLUDE_DIR C:/Program Files/CodeBlocks/MinGW/include)
set(Boost_LIBRARY_DIR C:/Program Files/CodeBlocks/MinGW/lib)
find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(Matrix_Lab
        main.cpp
        Matrix.cpp
        Matrix.h
        Inversion.hpp
        MinorInversion.hpp
        MinorInversion.cpp GaussianInversion.cpp GaussianInversion.h
        test.hpp)
