#include <iostream>
#include <cmath>
float mean(float psi[], float pdf[], float const dv, unsigned size)
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
    unsigned n = 100000;
    float left = -1000;
    int T = 300;
    float right = 1000;
    float delta = (right - left) / n;
    float *psi = 0, *pdf = 0;
    psi = new float[n];
    pdf = new float[n];
    for (long long int i = 0; i < n; i++)
    {
        float x = left + i * delta;
        psi[i] = abs(x);
        pdf[i] = exp(-x * x / T) / sqrt(M_PI * T);
    }
    std::cout << mean(psi, pdf, delta, n);
}