#include <iostream>
int main()
{
    int array[30] = {0};
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a = 0;
        int b = 0;
        std::cin >> a >> b;
        for (int j = a; j < a + b; j++)
        {
            array[j] = 1;
        }
    }
    int m = 0;
    std::cin >> m;
    bool global_flag = false;
    int k = 0;
    for (int i = 0; i < 30; i++)
    {
        bool flag = true;
        for (int j = 0; j < m; j++)
        {
            if (array[i + j] == 1)
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            k = i;
            global_flag = true;
            break;
        }
    }
    if (global_flag)
    {
        std::cout << k;
    }
    else
    {
        std::cout << -1;
    }
}