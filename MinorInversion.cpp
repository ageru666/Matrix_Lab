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

TEST_CASE("name1")
{
    Matrix ToInverse("inverse_test_data/test1.txt"); // "inverse_test_data/test1.txt"
    MinorInversion m;
    Matrix CorrectAnswer("inverse_test_data/answer1.txt");

    Matrix Result = m.inverse(ToInverse);

    for (size_t i = 0; i < Result.height(); ++i)
    {
        for (size_t j = 0; j < Result.width(); ++j)
            CHECK(Result[i][j] == CorrectAnswer[i][j]);
    }

    Matrix ToInverse2("inverse_test_data/test2.txt"); // "inverse_test_data/test1.txt"
    Matrix Result2 = m.inverse(ToInverse2);

    Matrix minor(ToInverse2, 1, 1);

    Result2.to_file("inverse_test_data/amswer2.txt");

    for (size_t i = 0; i < Result.height(); ++i)
    {
        for (size_t j = 0; j < Result.width(); ++j)
            CHECK(Result[i][j] == CorrectAnswer[i][j]);
    }
}
