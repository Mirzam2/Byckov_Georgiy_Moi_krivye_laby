#include <iostream>
using namespace std;
int main()
{
    bool flag = false;
    int a, max, n = 0;
    cin >> a;
    max = a;
    while (a != 0)
    {
        if (a > max)
        {
            max = a;
            n = 0;
        }
        if (a == max)
            n++;
        cin >> a;
    }
    cout << n;
    return 0;
}