#include <iostream>
#include <cmath>
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
    }                           // Делигирующий конструктор
    Fraction() : Fraction(0) {} // Конструктор по умолчанию должен быть удален

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
        std::cout << numerator << " / " << denominator;
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
void print(Fraction **massive)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            massive[i][j].printFraction();
            std::cout << " ";
        }
        std::cout << '\n';
    }
}
class Matrix
{
public:
    Matrix(int arr[], size_t n_elements)
    {
        size = int(sqrt(n_elements));
        mat = new int *[size]; // Заполнение матрицы из массива
        for (int i = 0; i < size; i++)
        {
            mat[i] = new int[size];
            for (int j = 0; j < size; j++)
            {
                mat[i][j] = arr[i * size + j];
            }
        }
    }

    Matrix(int element, size_t n_elements)
    {
        size = int(sqrt(n_elements));
        mat = new int *[size];
        for (int i = 0; i < size; i++)
        {
            mat[i] = new int[size];
            for (int j = 0; j < size; j++)
            {
                mat[i][j] = element;
            }
        }
        // Заполнение матрицы элементом element; n_elements -- количество элементов
    }

    Matrix() : Matrix(1, 1)
    { // Определить конструктор по умолчанию, как матрицу размера 1 с элементом равным 1
    }

    Matrix(const Matrix &other)
    {
        size = other.size;
        mat = new int *[size];
        for (int i = 0; i < size; i++)
        {
            mat[i] = new int[size];
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                mat[i][j] = other.mat[i][j];
            }
        }
        // Определить копирующий конструктор
    }

    void printMatrix()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                std::cout << mat[i][j] << " ";
            }
            std::cout << '\n';
        }
        // Вывести матрицу: каждое значение в строке разделено пробелом, строки отделены \n
    }

    int calcDeterminant()
    {
        Fraction **L = new Fraction *[size];
        Fraction **Q = new Fraction *[size];
        Fraction ed(1);
        for (int i = 0; i < size; i++)
        {
            L[i] = new Fraction[size];
            Q[i] = new Fraction[size];
            L[i][i].sumFrac(ed);
        }
        /*std::cout << "Start" << '\n';
        std::cout << "Q" << '\n';
        print(Q);
        std::cout << "L" << '\n';
        print(L);*/
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (j < i)
                {
                    /*std::cout << "Element  j<i(" << i << "," << j << ")" << '\n';
                    std::cout << "Q" << '\n';
                    print(Q);
                    std::cout << "L" << '\n';
                    print(L);*/
                    Fraction temp(mat[i][j]);
                    L[i][j] = temp;
                    for (int k = 0; k < j; k++)
                    {
                        L[i][j].diffFrac((L[i][k]).multByFracReturn(Q[k][j]));
                    }
                    Q[j][j].fracReverse();
                    L[i][j].multByFrac(Q[j][j]);
                    Q[j][j].fracReverse();
                }
                else
                {
                    /*std::cout << "Element i<=j(" << i << "," << j << ")" << '\n';
                    std::cout << "Q" << '\n';
                    print(Q);
                    std::cout << "L" << '\n';
                    print(L);*/
                    Fraction temp(mat[i][j]);
                    Q[i][j] = temp;
                    /*temp.printFraction();
                    std::cout << "\n";*/
                    for (int k = 0; k < i; k++)
                    {
                        // Q[i][j].printFraction();
                        Q[i][j].diffFrac((L[i][k]).multByFracReturn(Q[k][j]));
                        // Q[i][j].printFraction();
                    }
                }
                // std::cout << "Element okay(" << i << "," << j << ")" << '\n';
            }
        }
        /*std::cout << "Q" << '\n';
        print(Q);
        std::cout << "L" << '\n';
        print(L);*/
        Fraction result(1);
        for (int i = 0; i < size; i++)
        {
            result.multByFrac(L[i][i]);
            result.multByFrac(Q[i][i]);
            delete[] L;
            delete[] Q;
        }
        delete L;
        delete Q;
        result.fracSimplify();
        return result.getNumerator();
        // Вычислить детерминант
    }

    void calcSquare()
    { // Вычислить квадрат матрицы, результат оставить в том же экземпляре класса
        int **temp = new int *[size];
        for (int i = 0; i < size; i++)
        {
            temp[i] = new int[size];
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                temp[i][j] = mat[i][j];
            }
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int element = 0;
                for (int k = 0; k < size; k++)
                {
                    element += temp[i][k] * temp[k][j];
                }
                mat[i][j] = element;
            }
        }
        for (int i = 0; i < size; i++)
        {
            delete temp[i];
        }
        delete temp;
    }

    void matTranspose()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }
        // Осуществляет транспонирование матрицы, результат сохраняется тут же
    }

    ~Matrix()
    {
        for (int i = 0; i < size; i++)
        {
            delete mat[i];
        }
        delete mat;
        // Определить деструктор
    }

private:
    int **mat; // массив для хранения значений матрицы
    int size;  // размер стороны матрицы
    int calcDetermateDiag()
    {
        int result = 1;
        for (int i = 0; i < size; i++)
        {
            result *= mat[i][i];
        }
    }
};
int main()
{
    Matrix Kogeva(2, 9);
    Kogeva.printMatrix();
    Kogeva.calcSquare();
    Kogeva.printMatrix();
    int massive[9] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    Matrix Ershov(massive, 9);
    std::cout << " det" << '\n';
    std::cout << Ershov.calcDeterminant();
    Ershov.printMatrix();
    Ershov.calcSquare();
    Ershov.printMatrix();
    Ershov.matTranspose();
    Ershov.printMatrix();
}