#include "Matrix.h"
#include <iostream>

Matrix::Matrix(size_t a, size_t b)
{
    matrix = new std::complex<double> *[a];
    for (size_t i = 0; i < a; i++)
        matrix[i] = new std::complex<double>[b];

    height = a;
    width = b;
}

Matrix::~Matrix()
{

    for (size_t i = 0; i < height; i++)
        delete matrix[i];

    delete matrix;
}