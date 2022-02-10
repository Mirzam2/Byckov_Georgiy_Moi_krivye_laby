#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int p = int(n / 2) + 1;
    bool flag = true;
    while (p > 1)
    {
        if (n % p == 0)
        {
            cout << p << " ";
            flag = false;
        }
        p = p - 1;
    }
    if (flag)
        cout << endl;
    return 0;
}