#include <iostream>
#include <vector> // использую так как в обычных массивах я не знаю как сделать что бы работал конструктор, ему надо на вход данные, а как при этои их ввести??
void min(int &a, int &b)
{

    if (b < a)
    {
        int temp = a;
        a = b;
        b = temp;
    }
}
struct Segment
{
    int start;
    int end;
    Segment()
    {
        start = 0;
        end = 0;
    }
    Segment(int x_3, int x_4)
    {
        min(x_3, x_4);
        start = x_3;
        end = x_4;
    }
    bool operator==(const Segment &other) const
    {
        if ((end >= other.start) and (other.end >= end) or (start >= other.start) and (start <= other.end) or (other.start >= start) and (other.start <= end))
        {
            // std::cout << start << end << other.start << other.end;
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    int n = 0;
    std::cin >> n;
    Segment *array = new Segment[n];
    for (int i = 0; i < n; i++)
    {
        int a = 0;
        int b = 0;
        std::cin >> a >> b;
        array[i] = Segment(a, b);
    }
    bool flag = true;
    for (int i = 0; (i < n) and flag; i++)
    {
        for (int j = i + 1; (j < n) and flag; j++)
        {
            if (not(array[i] == array[j]))
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        std::cout << "YES"
                  << "\n";
    }
    else
    {
        std::cout << "NO"
                  << "\n";
    }
    return 0;
}