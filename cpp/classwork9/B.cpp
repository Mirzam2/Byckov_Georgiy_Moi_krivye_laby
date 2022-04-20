#include <iostream>
int main()
{
    const int n = 4;
    const int money[n] = {98, 49, 7, 1};
    int m = 0;
    std::cin >> m;
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += m / money[i];
        // std::cout << money[i] << " " << m / money[i] << '\n';
        m = m % money[i];
    }
    std::cout << s;
}