#include <iostream>

int main()
{
    long long int num;
    long long int g = 0;
    long long int parit = 2;
    std::cin >> num;
    int i = 0;
    while (i < 62)
    {
        g += ((num / parit) - (num / (2 * parit))) * (i + 1);
        parit = parit * 2;
        i++;
    }
    std::cout << g << '\n';

    return 0;
}