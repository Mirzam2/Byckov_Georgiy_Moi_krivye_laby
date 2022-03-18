#include <iostream>
#include <cmath>

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
    float c = 0.0;
    for (int i = 0; i < size; i++)
    {
        float y = pdf[i] * psi[i] - c;
        float t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }
    return sum * dv;
}
int main()
{
    unsigned n = 100000;
    float left = -1000;
    int T = 300;
    float right = 1000;
    float delta = (right - left) / n;
    float *psi = nullptr, *pdf = nullptr;
    psi = new float[n];
    pdf = new float[n];
    for (long long int i = 0; i < n; i++)
    {
        float x = left + i * delta;
        psi[i] = abs(x);
        pdf[i] = exp(-x * x / T) / sqrt(M_PI * T);
    }
    std::cout << mean(psi, pdf, delta, n);
    delete[] psi;
    delete[] pdf;
}