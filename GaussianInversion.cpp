#include "GaussianInversion.h"

Matrix GaussianInversion::inverse(const Matrix &mat, bool)
{

    if (mat.height() != mat.width())
        throw std::invalid_argument("The matrix in not square");

    if (abs(mat.D()) == 0)
        throw std::invalid_argument("Inverse matrix doesn't exist");

    size_t _size = mat.height();
    Matrix inverse(_size, _size);
    Matrix src (mat);

   /* for (int i=0; i<src.height() ; i++) {
        for (int j = 0; j < src.width(); j++)
            std::cout << src[i][j] << ' ';
        std::cout<<std::endl;
    }*/

    for (int i = 0; i < _size; i++)
        inverse[i][i] = 1;


    for (int k=0; k<_size; k++)
    {
       /* if (!abs(src[k][k]))
        {
            bool br = false;
            for (int i=0; i<_size; i++)
            {
                if (abs(src[i][k]))
                {
                    for (int j=0; j<_size; j++)
                    {
                        swap(src[k][j], src[i][j]);
                        swap(inverse[k][j], inverse[i][j]);
                    }
                    br = true;
                    break;
                }
            }
            if (!br)
                throw std::invalid_argument("Inverse matrix doesn't exist");
        }*/

        std::complex<double> diag = src[k][k];
        for (int i=0; i<_size; i++)
        {
            inverse[k][i] /=diag;
            src[k][i] /= diag;
        }
        src[k][k] = {1,0};
        for (int i=0; i<_size; i++)
        {
            if (k == i)
                continue;
            else
            if (abs(src[i][k]) == 0)
                continue;
            else {
                std::complex<double> div = src[i][k] / src[k][k];
                for (int j = 0; j < _size; j++) {
                    src[i][j] -= div * src[k][j];
                    inverse[i][j] -= div * inverse[k][j];
                }
            }
        }
    }

   /* for (int i=0; i<src.height() ; i++) {
        for (int j = 0; j < src.width(); j++)
            std::cout << src[i][j] << ' ';
        std::cout<<std::endl;
    }

    std::cout<<std::endl;
    for (int i=0; i<inverse.height() ; i++) {
        for (int j = 0; j < inverse.width(); j++)
            std::cout << inverse[i][j] << ' ';
        std::cout<<std::endl;
    }*/

    return inverse;
}
