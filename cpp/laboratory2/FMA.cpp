#include <iostream>
#include <cmath>
float mean(float psi[], float pdf[], float const dv, unsigned size);
void print(float *mas, int n) //вывод массива
{
    for (int i = 0; i < n; i++)
    {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
}
float mean(float psi[], float pdf[], float const dv, unsigned size)
{
    float sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum = fma(psi[i], pdf[i], sum);
    }
    return fma(sum, dv, 0);
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
        psi[i] = fabs(x);
        pdf[i] = exp(-x * x / T) / sqrt(M_PI * T);
    }
    std::cout << mean(psi, pdf, delta, n);
    delete[] psi;
    delete[] pdf;
}