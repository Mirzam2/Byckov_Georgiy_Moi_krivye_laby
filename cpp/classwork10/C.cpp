#include <iostream>
void input(int *mas, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cin >> mas[i];
    }
}
void print(int *mas, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << mas[i] << " ";
    }
    std::cout << '\n';
}
int l_max(int *mas, int n)
{
    int *mas_len = new int[n];
    for (int i = 0; i < n; i++)
        mas_len[i] = 0;

    for (int i = 0; i < n; i++)
    {
        int current_len = 0;

        for (int j = 0; j < i; j++)
        {
            if (mas[j] < mas[i])
            {
                current_len = std::max(mas_len[j], current_len);
            }
        }

        mas_len[i] = current_len + 1;
    }
    int max_l = 0;
    for (int i = 0; i < n; i++)
    {
        max_l = std::max(max_l, mas_len[i]);
    }
    delete[] mas_len;
    return max_l;
}
int main()
{
    int n = 0;
    std::cin >> n;
    if (n == 0)
    {
        std::cout << n;
        return 0;
    }
    int *mas = new int[n];
    input(mas, n);
    //print(mas, n);
    std::cout << l_max(mas, n);
    delete[] mas;
    return 0;
}