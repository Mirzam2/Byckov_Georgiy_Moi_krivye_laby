#include <iostream>
#include <cmath>
using namespace std;
int nod(int a, int b)
{
    while (a * b != 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    return a + b;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << nod(a, b);
    return 0;
}
