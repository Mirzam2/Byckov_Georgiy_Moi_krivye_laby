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
int nok(int a, int b)
{
    int c = nod(a, b);
    return a * b / c;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << nok(a, b);
    return 0;
}
