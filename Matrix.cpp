#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <random>

Matrix::Matrix(size_t height, size_t width, bool random_init)
{

    if (height < 1 || width < 1)
        throw std::invalid_argument("Matrix width and height must be 1 or larger");

    matrix = new std::complex<double> *[height];
    for (size_t i = 0; i < height; i++)
        matrix[i] = new std::complex<double>[width];

    _height = height;
    _width = width;
    if (random_init)
    {
        srand(time(NULL));
        for (size_t i = 0; i < height; ++i)
        {
            for (size_t j = 0; j < width; ++j)
            {
                matrix[i][j] = std::complex<double>(rand() % 100, rand() % 100);
            }
        }
    }
}

Matrix::Matrix(size_t height, size_t width, std::pair<double, double> **matrixOfPairs) : Matrix(height, width)
{
    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            matrix[i][j] = std::complex<double>(matrixOfPairs[i][j].first, matrixOfPairs[i][j].second);
        }
    }
}

Matrix::Matrix(std::string filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::invalid_argument("No file with such name exists: " + filename);

    size_t width, height;
    file >> height >> width;
    // Unfortuantely c++ doesn't allow to call a
    // constructor inside of another constructor

    if (height < 1 || width < 1)
        throw std::invalid_argument("Width or height of matrix is not correct, file may be corrupted");

    _height = height;
    _width = width;

    matrix = new std::complex<double> *[height];
    for (size_t i = 0; i < height; i++)
        matrix[i] = new std::complex<double>[width];

    double real, imagine;
    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            file >> matrix[i][j];
        }
    }
}

Matrix::~Matrix()
{

    for (size_t i = 0; i < _height; i++)
        delete matrix[i];

    delete matrix;
}

void Matrix::print()
{

    for (size_t i = 0; i < _height; ++i)
    {
        for (size_t j = 0; j < _width; ++j)
            std::cout << matrix[i][j] << ' ';
        std::cout << '\n';
    }
}

std::string Matrix::str()
{
    std::string s;
    s += std::to_string(_height) + ' ' + std::to_string(_width) + '\n';

    for (size_t i = 0; i < _height; ++i)
    {
        for (size_t j = 0; j < _width; ++j)
        {
            s += '(' + std::to_string(matrix[i][j].real()) + ',' + std::to_string(matrix[i][j].imag()) + ") ";
        }
        s += '\n';
    }

    return s;
}

void Matrix::to_file(std::string filename)
{
    std::ofstream file(filename);

    file << this->str();
}