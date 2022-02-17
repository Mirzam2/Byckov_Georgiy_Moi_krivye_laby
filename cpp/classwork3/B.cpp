#include <iostream>
const int N = 5;
using namespace std;
int binar(int (&mas)[N], int ch)
{
    int l = 0, h = N;
    int i = 0;
    while (l <= h)
    {
        i = (l + h) / 2;
        if (mas[i] == ch)
        {
            return i;
        }
        if (ch < mas[i])
        {
            h = i;
        }
        else
        {
            l = i;
        }
    }
    return -1;
}
int main()
{
    int massiv[N] = {0};
    for (int i = 0; i < N; i++)
    {
        cin >> massiv[i];
    }
    int ch = 0;
    cin >> ch;
    int i = binar(massiv, ch);
    if (i == -1)
    {
        cout << endl;
    }
    else
    {
        cout << i << endl;
    }
    return 0;
}