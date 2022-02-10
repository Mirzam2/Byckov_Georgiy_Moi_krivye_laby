#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double d = 0.;
    for (int i = 1; i < n; i++)
    {
        d += 1.0 / (i * i);
    }
    cout << d << endl;
    return 0;
}