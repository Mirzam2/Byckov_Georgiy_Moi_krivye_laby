#include <iostream>
#include <cmath>
#include <iomanip>
double mean(double psi[], double pdf[], double const dv, unsigned size)
{
    if (size == 1)
    {
        return psi[0] * pdf[0] * dv;
    }

    else
    {
        return mean(psi, pdf, dv, size / 2) + mean(psi + size / 2, pdf + size / 2, dv, size - size / 2);
    }
}
int main()
{
    unsigned n = 1000000;
    double left = -100000.0;
    int T = 300;
    double right = 100000.0;
    double delta = (right - left) / n;
    double *psi = 0, *pdf = 0;
    psi = new double[n];
    pdf = new double[n];
    for (long long int i = 0; i < n; i++)
    {
        double x = left + i * delta;
        psi[i] = abs(x);
        pdf[i] = exp(-x * x / T) / sqrt(M_PI * T);
    }
    std::cout << std::setprecision(10) << mean(psi, pdf, delta, n);
    delete[] psi;
    delete[] pdf;
}