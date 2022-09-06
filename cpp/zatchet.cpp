#include <iostream>

struct Pram;
struct Vect;
Vect vect_prois(Vect a, Vect b);
int smesh_prois(Vect a, Vect b, Vect c);
bool check(Vect a, Vect b);

struct Vect
{
    int x = 0;
    int y = 0;
    int z = 0;
    Vect(){};

    Vect(int x1, int y1, int z1, int x2, int y2, int z2)
    {
        x = x1 - x2;
        y = y1 - y2;
        z = z1 - z2;
    }
};
Vect vect_prois(Vect a, Vect b)
{
    Vect temp;
    temp.x = a.y * b.z - a.z * b.y;
    temp.y = -(a.x * b.z - a.z * b.x);
    temp.z = a.x * b.y - a.y * b.x;
    return temp;
}
int smesh_prois(Vect a, Vect b, Vect c)
{
    return a.x * (b.y * c.z - b.z * c.y) - a.y * (b.x * c.z - b.z * c.x) + a.z * (b.x * c.y - b.y * c.x);
}
int main()
{
    int n = 0;
    std::cin >> n;
    int A, B, C, D = 0;
    int x1, y1, z1, x2, y2, z2;
    int x3, y3, z3, x4, y4, z4;
    std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    std::cin >> x3 >> y3 >> z3 >> x4 >> y4 >> z4;
    Vect a(x1, y1, z1, x2, y2, z2);
    Vect b(x3, y3, z3, x4, y4, z4);
    Vect c(x1, y1, z1, x3, y3, z3);
    if (smesh_prois(a, b, c) != 0)
    {
        std::cout << "NO";
        return 0;
    }
    Vect t = vect_prois(a, b);
    A = t.x;
    B = t.y;
    C = t.z;
    D = -(x1 * A + y1 * B + z1 * C);
    for (int i = 2; i < n; i++)
    {
        int x5, y5, z5;
        std::cin >> x5 >> y5 >> z5;
        if (A * x5 + y5 * B + z5 * C + D != 0)
        {
            std::cout << "NO";
            return 0;
        }
        std::cin >> x5 >> y5 >> z5;
        if (A * x5 + y5 * B + z5 * C + D != 0)
        {
            std::cout << "NO";
            return 0;
        }
    }
    std::cout << "YES";
}
