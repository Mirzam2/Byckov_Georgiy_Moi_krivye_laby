#include <iostream>
#include <cmath>
void print(double *mas, int n) //вывод массива
{
    for (int i = 0; i < n; i++)
    {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
}
double mean(double psi[], double pdf[], double const dv, unsigned size)
{
    unsigned step = 1;
    for (unsigned i = 0; i < size; i++) //создаю массив где хранятся значения, которые потом надо интегрировать, без умножения на dv
    {
        psi[i] *= pdf[i];
    }
    while (step < size)
    {
        for (unsigned i = 0; i < size; i += 2 * step)
        {
            psi[i] += psi[i + step];
        }
        step *= 2;
    }
    return psi[0] * dv;
}
int main()
{
    unsigned n = 10000;
    double left = -1000;
    int T = 300;
    double right = 1000;
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
    std::cout << mean(psi, pdf, delta, n);
}