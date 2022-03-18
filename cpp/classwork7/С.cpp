#include <iostream>
struct Time
{
    int hour;
    int minute;
    int second;
    Time operator+(const Time &other)
    {
        int dt = hour * 3600 + minute * 60 + second + other.hour * 3600 + other.minute * 60 + other.second;
        if (dt > 24 * 3600)
        {
            dt -= 24 * 3600;
        }
        Time delita;
        delita.hour = dt / 3600;
        dt %= 3600;
        delita.minute = dt / 60;
        dt %= 60;
        delita.second = dt;
        return delita;
    }
    friend std::istream &operator>>(std::istream &in, Time &time)
    {
        in >> time.hour >> time.minute >> time.second;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &in, Time &time)
    {
        in << time.hour << ":" << time.minute << ":" << time.second;
        return in;
    }
};

int main()
{
    Time start, gap, end;
    std::cin >> start >> gap;
    end = start + gap;
    std::cout << end;
    return 0;
}