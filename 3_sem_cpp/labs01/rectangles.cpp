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
        std::cout << "one char x   " << int(s[i] - '0') << "   " << s[i] << '\n';
        i++;
    }
    ++i;
    int y = 0;
    while (s[i] != ')')
    {
        y = 10 * y + int(s[i] - '0');
        std::cout << "one char y   " << int(s[i] - '0') << '\n';
        i++;
    }
    Rectangle result(Point(x, y));
    std::cout << "print get_Rectangle: ";
    result.print();
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
    std::cout << "number: " << number << " mult: " << number_mult << '\n';
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
            std::cout << "a1: ";
            a.print();
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
        std::cout << "i " << i << " s[i] " << s[i] << '\n';
        massiv[i_sum] = a;
        ++i_sum;
    }
    Rectangle result;
    std::cout << "\n result: \n";
    for (i = 0; i < number - number_mult; ++i)
    {
        result += massiv[i];
        massiv[i].print();
    }
    return result;
}
int main()
{
    Rectangle a(Point(1, 5));
    Rectangle b(Point(2, 3));
    a += b;
    a.print();
    (a + b).print();
    std ::string expression;
    std ::getline(std ::cin, expression);
    std::string temp;
    for (char c : expression)
        if (c != ' ')
            temp += c;
    expression = temp;
    std::cout << expression << '\n';
    a = calk(expression);
    a.print();
    return 0;
}