#include <iostream>

class Fraction
{
public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
        fracSimplify();
    }

    Fraction(int numerator)
    {
        this->numerator = numerator;
        denominator = 1;
    }                    // Делигирующий конструктор
    Fraction() = delete; // Конструктор по умолчанию должен быть удален

    Fraction(const Fraction &other)
    {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
        fracSimplify();
    } // Конструктор копирования

    void fracReverse()
    {
        int temp = numerator;
        numerator = denominator;
        denominator = temp;
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
    void multByNumber(int value)
    { // Умножить дробь на число
        numerator *= value;
        fracSimplify();
    }

    void printFraction()
    { // Выводит дробь в формате 'numerator / denominator'
        std::cout << numerator << " / " << denominator << '\n';
    }
    void multByFrac(const Fraction &other)
    {
        numerator *= other.numerator;
        denominator *= other.denominator;
        fracSimplify();
        // Умножить дробь на другую дробь, результат оставить в вызывающей (в this)
    }
    Fraction multByFracReturn(const Fraction &other) const
    {
        int a = numerator * other.numerator;
        int b = denominator * other.denominator;
        Fraction drob(a, b);
        drob.fracSimplify();
        return drob; // умножает дроби и возвращает результат в третью
    }
    void sumFrac(const Fraction &other)
    {
        numerator = numerator * other.denominator + other.numerator * denominator;
        denominator *= other.denominator;
        fracSimplify(); // Просуммировать дробь на другую дробь, результат оставить в вызывающей (в this)
    }
    Fraction sumFracReturn(const Fraction &other) const
    {
        int a = numerator * other.denominator + other.numerator * denominator;
        int b = denominator * other.denominator;
        Fraction drob(a, b);
        drob.fracSimplify();
        return drob; // просуммировать дроби и вернуть результат в третью
    }
    void diffFrac(const Fraction &other)
    {
        numerator = numerator * other.denominator - other.numerator * denominator;
        denominator *= other.denominator; // Взять разность дробей, результат оставить в вызывающей (в this)
        fracSimplify();
    }
    Fraction diffFracReturn(const Fraction &other) const
    {
        int a = numerator * other.denominator - other.numerator * denominator;
        int b = denominator * other.denominator;
        Fraction drob(a, b);
        drob.fracSimplify();
        return drob; // просуммировать дроби и вернуть результат в третью
                     // Взять разность дробей, результат в третью
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
    Fraction drob_1(4, 3);
    drob_1.printFraction();
    std::cout << drob_1.calc() << '\n';
    std::cout << drob_1.getNumerator() << " " << drob_1.getDenominator() << '\n';
    Fraction drob_2(25, 15);
    Fraction drob_3(drob_1);
    drob_2.fracSimplify();
    drob_2.printFraction();
    drob_3.printFraction();
    drob_2.multByFrac(drob_1);
    drob_2.printFraction();
    drob_3.sumFrac(drob_1);
    drob_3.fracSimplify();
    drob_3.printFraction();
}