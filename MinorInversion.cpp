#include "MinorInversion.hpp"
#include <iostream>

using std::cout;
using std::endl;

Matrix MinorInversion::inverse(const Matrix &MatrixToinverse)
{

    size_t matrix_size;
    matrix_size = MatrixToinverse.width();

    std::complex<double> D = MatrixToinverse.D();

    std::cout << "D div: " << D << endl;

    Matrix Inversed(MatrixToinverse.height(), MatrixToinverse.width());

    for (size_t y = 0; y < matrix_size; ++y)
    {
        for (size_t x = 0; x < matrix_size; ++x)
        {

            Inversed[x][y] = MatrixToinverse.Dminor(x, y);
            if ((x + y) % 2 == 1)
                Inversed[x][y] = -Inversed[x][y];

            Inversed[x][y] /= D;
        }
    }

    return Inversed;
}

