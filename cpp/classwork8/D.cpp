#include <iostream>
int main()
{
    int n = 0;
    std::cin >> n;
    int *mas = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> mas[i];
    }
    int result = 0;
    for (int i = 0; i < n; i += 2)
    {
        if (mas[i] == 1)
        {
            if (i != 0)
            {
                if (mas[i - 1] == 1)
                    result = i - 1;
                else
                    result = i;
            }
            else
                result = 0;
            break;
        }
    }
    if (result == 0 and mas[0] != 1)
        result = n;

    std::cout << result;
}