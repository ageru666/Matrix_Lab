#include <chrono>
#include "Matrix.h"
#include <cmath>
#include <vector>
#include <fstream>

using namespace std::chrono;

class Test
{
    template <class Inverser>
    std::pair<double, std::vector<double>> measure_exec_time_and_errors(
        const Matrix &A, Inverser Inv, bool use_threading = false)
    {
        auto start = high_resolution_clock::now();

        Matrix Ainv = Inv.inverse(A, use_threading);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        double mae = MAE(A, Ainv);

        std::vector<double> errors;
        errors.push_back(mae);

        return std::make_pair(((double)duration.count()), errors);
    }

    double MAE(const Matrix &A, const Matrix &Arev)
    {
        std::cout << A.width() << ' ' << Arev.width() << std::endl;
        Matrix res = A * Arev;
        size_t n = A.width();
        std::complex<double> mae(0, 0);

        std::complex<double> zer(0, 0);
        std::complex<double> one(1, 0);

        for (size_t i = 0; i < n; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                if (j == i)
                    mae += abs(one - res[i][j]);
                else
                    mae += abs(zer - res[i][j]);
            }
        }

        return sqrt(pow(mae.real(), 2) + pow(mae.imag(), 2));
    }

public:
    template <class Inverser>
    void test_and_write(Inverser Inv, std::string filename, bool use_threading = false)
    {
        std::vector<std::pair<double, std::vector<double>>> Results;
        std::ofstream file;
        file.open(filename);

        for (size_t sz = 2; sz < 1000; ++sz)
        {
            std::pair<double, std::vector<double>> res = measure_exec_time_and_errors(
                Matrix(sz, sz, true), Inv, use_threading);
            file << sz << ' ' << res.first / 1000 << ' ' << res.second[0] << std::endl;
        }
    }
};
