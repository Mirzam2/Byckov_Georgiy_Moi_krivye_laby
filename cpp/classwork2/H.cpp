#include <iostream>
using namespace std;
int main()
{
    int n, a;
    cin >> n;
    cin >> a;
    int b = 0;
    int c = a;
    for (int i = 1; i <= n; i++)
    {
        b = b * 10 + c % 10;
        c = c / 10;
    }
    if (b == a)
    {
        cout << 1;
    }
    else
    {
        cout << b;
    }
    return 0;
}