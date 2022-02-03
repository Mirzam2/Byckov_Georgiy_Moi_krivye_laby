#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    long int m = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        m = m * i;
    }
    cout << m;
    return 0;
}
