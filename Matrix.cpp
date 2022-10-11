#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int a, int b)
{
    matrix = new std::complex<double> *[a];
    for (int i = 0; i < a; i++)
        matrix[i] = new std::complex<double>[b];

    height = a;
    width = b;
}

Matrix::~Matrix()
{

    for (int i = 0; i < height; i++)
        delete matrix[i];

    delete matrix;
}