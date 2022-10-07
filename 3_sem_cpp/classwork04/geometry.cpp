#include <iostream>
#include <vector>
#include <cmath>

struct Point
{
    double x = 0.;
    double y = 0.;

    Point(double x, double y) : x(x), y(y) {}
    Point() : Point(0, 0) {}
    Point operator+=(const Point &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }
    Point operator+(const Point &other) const
    {
        Point temp = *this;
        temp += other;
        return temp;
    }
    Point operator-=(const Point &other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    Point operator-(const Point &other) const
    {
        Point temp = *this;
        temp -= other;
        return temp;
    }
    Point operator/=(double m)
    {
        x /= m;
        y /= m;
        return *this;
    }
    Point operator/(double m) const
    {
        Point temp = *this;
        temp.x /= m;
        temp.y /= m;
        return temp;
    }
    Point operator=(const Point &other)
    {
        x = other.x;
        y = other.y;
        return *this;
    }
    // friend std::istream &operator>>(std::istream &in, const Point &time)
    // {
    //     in >> time.x >> time.y;
    //     return in;
    // }
    // friend std::ostream &operator<<(std::ostream &in, const Point &time)
    // {
    //     in << time.x << ":" << time.y;
    //     return in;
    // }
};

double length(Point &a, Point &b)
{
    Point temp;
    temp = a - b;
    return sqrt(temp.x * temp.x + temp.y * temp.y);
}

class Shape
{
protected:
    std::vector<Point> storage;

public:
    Shape(std::vector<Point> storage) : storage(storage) {}
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual Point center() = 0;
};

class Triangle : public Shape
{
protected:
    double a = 0.;
    double b = 0.;
    double c = 0.;

public:
    Triangle(std::vector<Point> storage) : Shape(storage), a(length(storage[0], storage[1])), b(length(storage[0], storage[2])), c(length(storage[1], storage[2]))
    {
    }

    double area() override
    {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    double perimeter() override
    {
        return (a + b + c);
    }

    Point center() override
    {
        return ((storage[0] + storage[1] + storage[2]) / 3);
    }
};

class Square : public Shape
{
protected:
    double a = 0.0;

public:
    Square(std::vector<Point> storage) : Shape(storage), a(length(storage[0], storage[1])) {}

    double area() override
    {
        return (a * a);
    }

    double perimeter() override
    {
        return a * 4;
    }

    Point center() override
    {
        return ((storage[0] + storage[1] + storage[3] + storage[4]) / 4);
    }
};

class Line : public Shape
{
protected:
    double a = 0.;

public:
    Line(std::vector<Point> storage) : Shape(storage), a(length(storage[0], storage[1])) {}

    double area() override
    {
        return 0;
    }

    double perimeter() override
    {
        return a;
    }

    Point center() override
    {
        return ((storage[0] + storage[1]) / 2);
    }
};

int main()
{
    Point a(0,0), b(0,2), c(2,2), d(2,0);
    //std::cout << "Введите 4 точки:(желательно что бы проходили сразу и линии и треугольнику и квадрату)  "

    std::vector<Point> points = {a, b};
    Line l(points);
    std::cout << "Line test: \n";
    std::cout << l.area() << '\n';
    std::cout << l.perimeter() << '\n';
    Point center=l.center();
    std::cout << '('<<center.x << " " << center.y << ")\n";
    points.push_back(c);
    std::cout << "Triangle test: \n";
    Triangle t(points);
    std::cout << t.area() << '\n';
    std::cout << t.perimeter() << '\n';
    center=t.center();
    std::cout << '('<<center.x << " " << center.y << ")\n";
    points.push_back(d);
    std::cout << "Square test: \n";
    Square s(points);
    std::cout << s.area() << '\n';
    std::cout << s.perimeter() << '\n';
    center=s.center();
    std::cout << '('<<center.x << " " << center.y << ")\n";

    return 0;
}