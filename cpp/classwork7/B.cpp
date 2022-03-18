#include <iostream>
struct Students
{
    char name[20];
    int m = 0;
    bool operator<(const Students &other) const
    {
        if (m < other.m) //сравнение по баллу
        {
            return true;
        }
        if (m == other.m)
        {//сравнение слов
            int i = 0;
            for (i = 0; name[i] != '\0' and other.name[i] != '\0'; i++)
            {
                if (name[i] < other.name[i])
                {
                    return false;
                }
                if (name[i] > other.name[i])
                {
                    return true;
                }
            }
            if (name[i] != '\0') // если слово короче
            {

                return true;
            }
            return false;
        }
        return false;
    }
};
void swap(Students &a, Students &b) // перемена мест
{
    Students temp = a;
    a = b;
    b = temp;
}
void sortic(Students *mas, int start, int end) // сортировка
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
        for (int i = end; i > start; i -= 2)
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
    const int N = 5;
    Students *team = new Students[N];
    for (int i = 0; i < N; i++)
    {
        std::cin >> team[i].name >> team[i].m;
    }
    int m_crit = 0;
    std::cin >> m_crit;
    sortic(team, 0, N - 1);
    for (int i = 0; i < N; i++)
    {
        if (team[i].m >= m_crit) std::cout << team[i].name << " " << team[i].m << "\n";
    }
    std::cout << "\n";
    return 0;
}