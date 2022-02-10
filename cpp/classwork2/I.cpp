#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int p = 2;
    while (n > 1)
    {
        if (n % p == 0)
        {
            cout << p << " ";
            while (n % p == 0)
                n = n / p;
        }
        p++;
    }
    return 0;
}