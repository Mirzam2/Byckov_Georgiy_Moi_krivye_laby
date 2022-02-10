#include <iostream>
using namespace std;
int main()
{
    int temp, n = 0;
    cin >> temp;
    while (temp)
    {
        if (temp % 2 == 0)
            n++;
        cin >> temp;
    }
    cout << n << endl;
    return 0;
}