#include <iostream>

struct Para;

void swap(Para &, Para &);
void sortic(Para *, int, int);

struct Para
{
    int start = 0;
    int end = 0;
    Para()
    {
    }
    friend std::istream &operator>>(std::istream &in, Para &ne_ydary)
    {
        in >> ne_ydary.start >> ne_ydary.end;
        return in;
    }
    bool operator<(const Para &other)
    {
        if (end < other.end)
            return true;
        else
            return false;
    }
    friend std::ostream &operator<<(std::ostream &in, Para &ne_ydary)
    {
        in << ne_ydary.start << " " << ne_ydary.end << '\n';
        return in;
    }
};
void swap(Para &a, Para &b) // перемена мест
{
    Para temp = a;
    a = b;
    b = temp;
}
void sortic(Para *mas, int start, int end) // сортировка
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
    int n = 0;
    std::cin >> n;
    Para *timetable = new Para[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> timetable[i];
    }
    sortic(timetable, 0, n - 1);
    /*for (int i = 0; i < n; i++)
    {
        std::cout << timetable[i];
    }*/
    int s = 0;    // счетчик пар
    int time = 0; // время окончания последней уже взятой пары
    for (int i = 0; i < n; i++)
    {
        if (timetable[i].start >= time)
        {
            time = timetable[i].end;
            s++;
        }
    }
    std::cout << s;
    delete[] timetable;
}