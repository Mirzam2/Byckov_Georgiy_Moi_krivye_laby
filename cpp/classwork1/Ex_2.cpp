#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    double d;
    d = pow(b, 2) - 4 * a * c;
    if (a == 0)
    {
        double x = -c * 1.0 / b;
        cout << x;
    }
    else if (a == 0 and b == 0)
    {
        if (c != 0)
            cout << "\n";
    }
    else if (d > 0)
    {
        cout << (-b - sqrt(d)) / a / 2 << " " << (-b + sqrt(d)) / a / 2;
    }
    else if (d == 0)
    {
        cout << -b * 1.0 / 2 / a;
    }
    else
    {
        cout << "\n";
    }

    return 0;
}
