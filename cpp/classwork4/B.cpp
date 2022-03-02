#include <iostream>
int main()
{
    int n = 0;
    std::cin >> n;
    int mas[n] = {0};
    for (int i = 0; i < n; i++)
    {
        std::cin >> mas[i];
    }
    int *teg = &mas[0];
    for (int *teg = &mas[0]; teg <= &mas[n - 1]; teg++)
    {
        std::cout << *teg << " ";
    }
    std::cout << std::endl;
    for (int *teg = &mas[n - 1]; teg >= &mas[0]; teg--)
    {
        std::cout << *teg << " ";
    }
    return 0;
}