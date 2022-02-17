#include <iostream>
const int N = 5;
using namespace std;
void sort_gnom(int (&mas)[N])
{
    int i = 1, j = 2;
    while (i < N)
    {
        if (mas[i - 1] < mas[i])
        {
            i = j;
            j++;
        }
        else
        {
            int temp = mas[i];
            mas[i] = mas[i - 1];
            mas[i - 1] = temp;
            i = i-1;
            if (i == 0)
            {
                i = j;
                j++;
            }
        }
    }
}
int main()
{
    int massiv[N] = {0};
    for (int i = 0; i < N; i++)
    {
        cin >> massiv[i];
    }
    sort_gnom(massiv);
    for (int i = 0; i < N; i++)
    {
        cout << massiv[i] << " ";
    }
    return 0;
}