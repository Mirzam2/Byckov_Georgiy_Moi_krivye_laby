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
    bool flag = true;
    long long a;
    cin >> a;
    while (true)
    {
        if (a == 1)
        {
            flag = true;
            break;
        }
        if (a % 2 == 0)
        {
            a = a / 2;
        }
        else
        {
            flag = false;
            break;
        }
    }
    c0ut(flag);
    return 0;
}