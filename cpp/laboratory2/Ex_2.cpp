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
    unsigned step = 1;
    for (unsigned i = 0; i < size; i++) //создаю массив где хранятся значения, которые потом надо интегрировать, без умножения на dv
    {
        psi[i] *= pdf[i] * dv;
    }
    while (step < size)
    {
        for (unsigned i = 0; i < size; i += 2 * step)
        {
            psi[i] += psi[i + step];
        }
        step *= 2;
    }
    return psi[0];
}
int main()
{
    unsigned n = 100000;
    float left = -100;
    int T = 300;
    float right = 100;
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
    delete[] psi;
    delete[] pdf;
}