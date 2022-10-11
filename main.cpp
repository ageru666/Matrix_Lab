#include <iostream>
#include "Matrix.h"

std::complex<double> determinant(int size, std::complex<double> **matrix)
{

    if (size == 1)
        return matrix[0][0];
    if (size == 2)
        return (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]);

    std::complex<double> ans = 0;

    std::complex<double> **submatrix = new std::complex<double> *[size - 1];
    for (int i = 0; i < size - 1; i++)
        submatrix[i] = new std::complex<double>[size - 1];

    for (int x = 0; x < size; x++)
    {
        int subi = 0, subj = 0;
        for (int i = 0; i < size; i++)
        {
            if (i == x)
                continue;
            for (int j = 1; j < size; j++)
            {
                submatrix[subi][subj] = matrix[i][j];
                subj++;
            }
            subi++;
            subj = 0;
        }
        ans += pow(-1, x) * matrix[x][0] * determinant(size - 1, submatrix);
    }

    return ans;
}

int main()
{

    Matrix m(8, 3);

    std::complex<double> a(1, 1);

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 3; j++)
        {
            m[i][j] = std::complex<double>((i + 1), (j + 1));
        }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 3; j++)
            std::cout << m[i][j] << ' ';
        std::cout << '\n';
    }
}
