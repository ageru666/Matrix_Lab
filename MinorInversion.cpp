#include "MinorInversion.hpp"
#include <iostream>

using std::cout;
using std::endl;

Matrix MinorInversion::inverse_no_threading(const Matrix &MatrixToinverse)
{

    std::cout << "START Inverse " << MatrixToinverse.width() << ' ' << MatrixToinverse.height() << std::endl;
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
void calc_minor(const Matrix &M, size_t x_skip, size_t y_skip, const std::complex<double> &D, std::complex<double> &res)
{
    res = M.Dminor(x_skip, y_skip);
}
#ifdef _USE_THREADING

#include <boost/asio/thread_pool.hpp>
#include <boost/asio/post.hpp>

Matrix MinorInversion::inverse_with_threading(const Matrix &MatrixToinverse)
{
    boost::asio::thread_pool pool(4);

    // Submit a function to the pool.

    // Submit a lambda object to the pool

    // Wait for all tasks in the pool to complete.
    pool.join();
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
            boost::asio::post(pool, std::bind(calc_minor, MatrixToinverse, x, y, D, Inversed[x][y]));
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
#ifndef _USE_THREADING

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

Matrix MinorInversion::inverse(const Matrix &ToInverse)
{
    return inverse_no_threading(ToInverse);
}

/*
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
*/