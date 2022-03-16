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
    double sum = 0.0;
    double c = 0.0;
    for (int i = 0; i < size; i++)
    {
        double y = pdf[i] * psi[i] - c;
        double t = sum + y;             
        c = (t - sum) - y;             
        sum = t;                      
    }
    return sum * dv;
}
int main()
{
    unsigned n = 100000;
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