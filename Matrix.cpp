#include "Matrix.h"
#include <iostream>

Matrix::Matrix(size_t a, size_t b)
{
    if (a < 1 || b < 1)
        throw std::invalid_argument("Matrix width and height must be 1 or larger");

    matrix = new std::complex<double> *[a];
    for (size_t i = 0; i < a; i++)
        matrix[i] = new std::complex<double>[b];

    _height = a;
    _width = b;
}

Matrix::~Matrix()
{

    for (size_t i = 0; i < _height; i++)
        delete matrix[i];

    delete matrix;
}