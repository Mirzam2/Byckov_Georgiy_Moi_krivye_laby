#include <iostream>

class Fraction
{
public:
    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

    Fraction(int numerator) : Fraction(numerator, 1) {} // Делигирующий конструктор
    Fraction() = delete;                                // Конструктор по умолчанию должен быть удален

    Fraction(const Fraction &other)
    {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
        fracSimplify();
    } // Конструктор копирования
    friend std::ostream &operator<<(std::ostream &out, const Fraction &obj)
    {
        out << obj.numerator << " / " << obj.denominator << '\n';
        return out;
    } // Оператор вывода << "числитель знаминатель"
    friend std::istream &operator>>(std::istream &in, Fraction &obj)
    {
        in >> obj.numerator >> obj.denominator;
        return in;
    } // Оператор ввода >> числитель >> знаминатель
    Fraction &operator+=(const Fraction &other)
    {
        numerator = numerator * other.denominator + denominator * other.numerator;
        denominator *= other.denominator;
        fracSimplify();
        return *this;
    }
    Fraction &operator-=(const Fraction &other)
    {
        numerator = numerator * other.denominator - denominator * other.numerator;
        denominator *= other.denominator;
        fracSimplify();
        return *this;
    }
    Fraction &operator*=(const Fraction &other)
    {
        numerator *= other.numerator;
        denominator *= other.denominator;
        fracSimplify();
        return *this;
    }
    Fraction operator+(const Fraction &other) const
    {
        Fraction temp = *this;
        temp += other;
        return temp;
    }
    Fraction operator-(const Fraction &other) const
    {
        Fraction temp = *this;
        temp -= other;
        return temp;
    }
    Fraction operator*(const Fraction &other) const
    {
        Fraction temp = *this;
        temp *= other;
        return temp;
    }
    Fraction &operator++()
    {
        return *this += 1;
    }
    Fraction operator++(int)
    {
        Fraction result = *this;
        ++(*this);
        return result;
    };
    Fraction &operator--()
    {
        return *this -= 1;
    }
    Fraction operator--(int)
    {
        Fraction result = *this;
        --(*this);
        return result;
    }
    void fracSimplify()
    { // Сокращает дробь по возможности
        int temp = NOD();
        denominator = denominator / temp;
        numerator = numerator / temp;
        if (denominator < 0)
        {
            denominator *= -1;
            numerator *= -1;
        }
    }
    double calc()
    { // Возвращает значение дроби в десятичном виде
        return (double(numerator) / double(denominator));
    }

    int getNumerator()
    { // Возвращает значение числителя
        return numerator;
    }

    int getDenominator()
    { // Возвращает знамечение знаменателя
        return denominator;
    }

private:
    int numerator;
    int denominator;
    int NOD()
    {
        int a = abs(numerator), b = abs(denominator);
        while (a != 0 and b != 0)
        {
            if (a > b)
            {
                a = a % b;
            }
            else
            {
                b = b % a;
            }
        }
        return (a + b);
    }
};
int main()
{
    Fraction a(5), b(1);
    std::cin >> a >> b;
    std::cout << " + " << a + b << " - " << a - b << " * " << a * b;
    a += b;
    std::cout << a;
}
