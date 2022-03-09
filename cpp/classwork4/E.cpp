#include <iostream>
void swap(int &a, int &b) // перемена мест
{
    int temp = a;
    a = b;
    b = temp;
}
void print(int *mas, int n) //вывод массива
{
    for (int i = 0; i < n; i++)
    {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
}
void sortic(int *mas, int start, int end) // сортировка
{
    int sign = 1;
    if ((end - start) % 2 == 0)
    {
        sign = -1;
    }
    for (end; end > 0; end--)
    {
        if ((end - start) % 2 == 0)
        {
            sign = -1;
        }
        for (int i = end; i > start; i += -2)
        {
            if ((sign == 1) and (i == end))
            {
                if (mas[(i - 1) / 2] < mas[i])
                {
                    swap(mas[(i - 1) / 2], mas[i]);
                }
            }
            else
            {
                if (mas[(i - 1) / 2] < mas[i])
                {
                    swap(mas[(i - 1) / 2], mas[i]);
                }
                if (mas[(i - 1) / 2] < mas[i + sign])
                {
                    swap(mas[(i - 1) / 2], mas[(i + sign)]);
                }
            }
        }
        swap(mas[end], mas[0]);
    }
}
int main()
{
    int n = 0;
    std::cin >> n;
    int *mas = 0;
    mas = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> mas[i];
    }
    print(mas, n);
    sortic(mas, 0, n - 1);
    print(mas, n);
    delete[] mas;
    return 0;
}