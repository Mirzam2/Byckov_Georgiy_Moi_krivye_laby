#include <iostream>
int main()
{
    int n = 100;
    std::cin >> n;
    int m = 50;
    std::cin >> m;
    int k = 1;
    std::cin >> k;
    int *mas = new int[k];
    for (int i = 0; i < k; i++)
    {
        std::cin >> mas[i];
    }
    int s = 0;
    int pump = 0;
    while (pump < k)
    {
        if (mas[pump] + m >= n)
            break;
        if (mas[pump + 1] - mas[pump] > m)
        {
            pump = -1;
            break;
        }
        else
        {
            for (int i = pump; i < k; i++)
            {
                if (mas[i] - mas[pump] > m)
                {
                    pump = i - 1;
                    s++;
                    break;
                }
            }
        }
    }
    if (pump == -1)
        s = -1;
    std::cout << s;
    delete[] mas;
    return 0;
}