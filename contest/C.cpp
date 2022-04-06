#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int *compress(int **matrix, int n, int m)
{
    int *ptr = new int[m * 3];
    int *temp = &ptr[0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int s = 0;
            if (matrix[i][j] != 0)
            {
                s++;
                *temp = matrix[i][j];
                temp++;
            }
            if (s > 3)
            {
                for(int i_1 = n - 1; 0 <= i_1; i_1--)
                    delete[] matrix[i_1];
                    delete matrix[i_1];
                delete temp;
                return nullptr;
            }
        }
    }
    for(int i_1 = n - 1; 0 <= i_1; i_1--)
                    delete[] matrix[i_1];
    delete temp;
    return ptr;
};
// Здесь ваша реализация функции.

int main()
{
    int n, m;
    cin >> n >> m;
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int *compressed = compress(a, n, m);

    if (!compressed)
        return 0;

    for (int i = 0; i < n * 3; i++)
        cout << compressed[i] << " ";
    cout << endl;

    delete[] compressed;
    return 0;
}