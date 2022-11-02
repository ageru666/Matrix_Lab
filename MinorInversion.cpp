#include "MinorInversion.hpp"
#include <iostream>
#include <boost/asio/thread_pool.hpp>
#include <boost/asio/post.hpp>

using std::cout;
using std::endl;

Matrix MinorInversion::inverse_no_threading(const Matrix &MatrixToinverse)
{

    size_t matrix_size;
    matrix_size = MatrixToinverse.width();

    std::complex<double> D = MatrixToinverse.D();

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
void calc_minor(const Matrix &M, size_t x_skip, size_t y_skip, const std::complex<double> &D, std::complex<double> *res)
{

    *res = M.Dminor(x_skip, y_skip) / D;

    if ((x_skip + y_skip) % 2 == 1)
        *res = -(*res);
}

class MatrixThreading : Matrix
{
    MatrixThreading(const Matrix &res)
    {
        matrix = res.matrix;
    }
    ~MatrixThreading()
    {
    }
};
#ifdef _MINOR_INVERSION_USE_THREADING
#include <boost/asio/thread_pool.hpp>
#include <boost/asio/post.hpp>

Matrix MinorInversion::inverse_with_threading(const Matrix &MatrixToinverse)
{

    boost::asio::thread_pool pool(4);

    size_t matrix_size;
    matrix_size = MatrixToinverse.width();

    std::complex<double> D = MatrixToinverse.D();

    Matrix Inversed(MatrixToinverse.height(), MatrixToinverse.width());

    // ioService.post(boost::bind(myTask, "Hello World!"));
    // ioService.post(boost::bind(clearCache, "./cache"));
    // ioService.post(boost::bind(getSocialUpdates, "twitter,gmail,facebook,tumblr,reddit"));
    for (size_t y = 0; y < matrix_size; ++y)
    {
        for (size_t x = 0; x < matrix_size; ++x)
        {

            boost::asio::post(pool, std::bind(calc_minor, MatrixToinverse, x, y, D, &Inversed[x][y]));
        }
    }
    /*
     * This will stop the ioService processing loop. Any tasks
     * you add behind this point will not execute.
     */

    /*
     * Will wait till all the threads in the thread pool are finished with
     * their assigned tasks and 'join' them. Just assume the threads inside
     * the threadpool will be destroyed by this method.
     */
    pool.join();

    return Inversed;
}
#endif

#ifndef _MINOR_INVERSION_USE_THREADING

class threading_exception : public std::exception
{
public:
    char *what()
    {
        return "No threading available, please use \"#define _USE_THREADING \" to use it";
    }
};

Matrix MinorInversion::inverse_with_threading(const Matrix &MatrixToinverse)
{
    throw threading_exception();

    return Matrix(1, 1, true);
}

#endif

Matrix MinorInversion::inverse(const Matrix &ToInverse, bool use_threading)
{
    std::cout << "START HERE " << ToInverse.width() << ' ' << ToInverse.height() << std::endl;

    if (use_threading)
        return inverse_with_threading(ToInverse);
    else
        return inverse_no_threading(ToInverse);
}
