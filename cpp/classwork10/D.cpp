#include <iostream>
#include <cmath>

void input(int *, int);
int bin_poick(int *, int, float);
void optimal(int, int, int *, int, int &);

void input(int *mas, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cin >> mas[i];
    }
}
void print(int *mas, int s, int n)
{
    for (int i = s; i < n; i++)
    {
        std::cout << mas[i] << " ";
    }
    std::cout << '\n';
}
int bin_poick(int *a, int N, float point) // бинарный поиск элемента который ближе всего к point
{
    int i = 0;
    int j = N - 1;
    int k = 0;
    while (i != j)
    {
        k = (i + j) / 2;
        if (a[k] < point)
        {
            i = k;
        }
        else if (a[k] == point)
        {
            return k;
        }
        else
        {
            j = k;
        }
        if (j - i <= 1)
        {
            if (fabs(a[i] - point) <= fabs(a[j] - point))
                return i;
            else
                return j;
        }
    }
    return -1;
}

void optimal(int start, int end, int *mas, int N, int &price) // рекурсивная фунция которая ищет минимальную цену для конкретного куска
{
    if (start == end)
        return;
    int id = bin_poick(mas, N, static_cast<float>(start + end) / 2); // находим такой разрез что бы пилить как можно ближе к напополам

    if (mas[id] == end || mas[id] == start) // проверка на том кончится ли
        return;
    price += end - start; // разрезали пополам и дальше ищем оптимальный там
    optimal(start, mas[id], mas, N, price);
    optimal(mas[id], end, mas, N, price);
    return;
}

int main()
{
    int L, N, price = 0;
    std::cin >> L >> N;
    int *mas = new int[N];
    input(mas, N);
    optimal(0, L, mas, N, price);
    std::cout << price;
}