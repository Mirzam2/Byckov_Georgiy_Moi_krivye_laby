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
    int a;
    bool b = false;
    cin >> a;
    if (a % 4 == 0)
    {
        b = true;
        if (a % 100 == 0)
        {
            b = false;
            if (a % 400 == 0)
            {
                b = true;
            }
        }
    }
    c0ut(b);
    return 0;
}