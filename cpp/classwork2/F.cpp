#include <iostream>
using namespace std;
void c0ut(bool flag)
{
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    int n;
    cin >> n;
    int p = 2;
    bool flag = true;
    while (p * p <= n)
    {
        if (n % p == 0)
        {
            flag = false;
            break;
        }
        p++;
    }
    c0ut(flag);
    return 0;
}