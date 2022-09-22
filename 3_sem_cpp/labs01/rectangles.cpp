#include <iostream>
#include <string>
struct Point
{
    unsigned long long x, y;
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
    Point operator=(Point const &other)
    {
        x = other.x;
        y = other.y;
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
        Rectangle result_x = Rectangle(point.maxx(rha.point));
        Rectangle result_y = Rectangle(result_x.point.maxy(rha.point));
        return result_y;
    }
    Rectangle operator*(Rectangle const &rha) const
    {
        Rectangle result_x = Rectangle((point.minx(rha.point)));
        Rectangle result_y = Rectangle((result_x.point.miny(rha.point)));
        return result_y;
    }
    Rectangle &operator+=(Rectangle const &rha)
    {
        Rectangle result_x = Rectangle(point.maxx(rha.point));
        // Rectangle result_y = Rectangle(result_x.point.maxy(rha.point));
        Rectangle result_y = Rectangle((result_x.point.maxy(rha.point)));
        point = result_y.point;
        return *this;
    }
    Rectangle &operator*=(Rectangle const &rha)
    {
        Rectangle result_x = Rectangle(point.minx(rha.point));
        // Rectangle result_y = Rectangle(result_x.point.maxy(rha.point));
        Rectangle result_y = Rectangle((result_x.point.miny(rha.point)));
        point = result_y.point;
        return *this;
    }

    void print()
    {
        std::cout << point.x << " " << point.y << '\n';
    }

private:
    Point point;
};
Rectangle get_Rectangle(int &i, std::string s)
{
    int x = 0;
    i++;
    while (s[i] != ',')
    {
        x = 10 * x + int(s[i] - '0');
        i++;
    }
    ++i;
    int y = 0;
    while (s[i] != ')')
    {
        y = 10 * y + int(s[i] - '0');
        i++;
    }
    Rectangle result(Point(x, y));
    return result;
}
Rectangle calk(std::string s)
{
    int number = 0;
    int number_mult = 0;
    for (char c : s)
    {
        if (c == '*')
            number_mult++;
        if (c == '(')
            number++;
    }
    Rectangle *massiv = new Rectangle[number - number_mult];
    int i = 0;
    int i_sum = 0;
    while (i < s.length())
    {
        Rectangle a(Point(0, 0));
        if (s[i] == '(')
        {
            Rectangle temp = get_Rectangle(i, s);
            a += temp;
        }
        if (not(++i == s.length()))
        {

            while (s[i] == '*')
            {
                i++;
                Rectangle temp = get_Rectangle(i, s);
                ++i;
                a *= temp;
            }
        }
        ++i;
        massiv[i_sum] = a;
        ++i_sum;
    }
    Rectangle result;
    for (i = 0; i < number - number_mult; ++i)
    {
        result += massiv[i];
        //massiv[i].print();
    }
    return result;
}
int main()
{
    std ::string expression;
    std ::getline(std ::cin, expression);
    std::string temp;
    for (char c : expression)
        if (c != ' ')
            temp += c;
    expression = temp;
    Rectangle a = calk(expression);
    a.print();
    return 0;
}