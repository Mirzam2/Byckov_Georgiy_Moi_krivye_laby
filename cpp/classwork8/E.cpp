#include <iostream>
int main()
{
    int s = 0;
    char a = 0;
    a = std ::cin.get();
    while (a != '\n')
    {
        if (a == '(')
            s++;
        if (a == ')')
            s--;
        if (s < 0)
        {
            break;
        }
        a = std ::cin.get();
    }
    if (s != 0)
        std::cout << 1;
    else
        std::cout << 0;
}