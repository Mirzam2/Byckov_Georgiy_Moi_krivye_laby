#include <iostream>
#include <cmath>
#include <iomanip>
double mean(double psi[], double pdf[], double const dv, unsigned size)
{
    if (size == 1)
    {
        return fma(fma(psi[0], pdf[0], 0), dv, 0);
    }

    else
    {
        return fma(mean(psi, pdf, dv, size / 2), 1, mean(psi + size / 2, pdf + size / 2, dv, size - size / 2));
    }
}
int main()
{
    unsigned n = 1000000;
    double left = -1000;
    int T = 1;
    double right = 1000;
    double delta = (right - left) / n;
    double *psi = nullptr, *pdf = nullptr;
    psi = new double[n];
    pdf = new double[n];
    for (long long int i = 0; i < n; i++)
    {
        double x = left + i * delta;
        psi[i] = fabs(x);
        pdf[i] = exp(-x * x / T) / sqrt(M_PI * T);
    }
    std::cout << std::setprecision(10) << mean(psi, pdf, delta, n) << " " << std::setprecision(10) << sqrtf(T / M_PI);
    delete[] psi;
    delete[] pdf;
}