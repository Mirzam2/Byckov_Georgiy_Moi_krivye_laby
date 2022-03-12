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
void sortic(int *mas, int left, int right) // сортировка
{
    if (left < right)
    {
        int pos = (left + right) / 2;
        int opor = mas[(left + right) / 2];
        int i = left, j = right;
        while (true)
        {
            while (mas[i] < opor)
            {
                i++;
            }
            while (mas[j] > opor)
            {
                j--;
            }
            if (i >= j)
            {
                pos = j;
                break;
            }

            swap(mas[i++], mas[j--]);
        }
        sortic(mas, left, pos);
        sortic(mas, pos + 1, right);
    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    int *mas = nullptr;
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