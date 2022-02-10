#include <iostream>
using namespace std;
int main()
{
    bool flag = false;
    int a, max;
    cin >> a;
    max = a;
    while (true)
    {
        if (a == 0)
        {
            flag = true;
            break;
        }
        if (a % 2 == 0)
        {
            max = a;
            break;
        }
        cin >> a;
    }
    if (flag)
        return 0;
    while (a != 0)
    {
        if ((a % 2 == 0) and (a > max))
            max = a;
        cin >> a;
    }
    cout << max;
    return 0;
}