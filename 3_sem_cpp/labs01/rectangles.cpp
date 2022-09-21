#include <iostream>

struct Point
{
    unsigned long long const x, y;
    Point(unsigned long long x, unsigned long long y) : x(x), y(y)
    {
    }
    Point minx(Point const &rha) const
    {
        return Point(rha.x < x ? rha.x : x, y);
    }
    Point miny(Point const &rha) const
    {
        return Point(x, rha.y < y ? rha.y : y);
    }
    Point maxx(Point const &rha) const
    {
        return Point(rha.x > x ? rha.x : x, y);
    }
    Point maxy(Point const &rha) const
    {
        return Point(x, rha.y > y ? rha.y : y);
    }

    void print()
        const
    {

        std ::cout << " ( " << x << " , " << y << " ) ";
    }
};
class Rectangle
{
public:
    Rectangle(Point const &point) : point(point) {}
    Rectangle() : Rectangle(Point(0, 0)) {}
    Rectangle operator+(Rectangle const &rha) const
    {
        Rectangle result_x = Rectangle((point.maxx(rha.point)));
        Rectangle result_y = Rectangle((result_x.point.maxy(rha.point)));
        return result_y;
    }
    Rectangle operator*(Rectangle const &rha) const
    {
        Rectangle result_x = Rectangle((point.minx(rha.point)));
        Rectangle result_y = Rectangle((result_x.point.miny(rha.point)));
        return result_y;
    }
    void print()
    {
        std::cout << point.x << " " << point.y << '\n';
    }

private:
    Point point;
};