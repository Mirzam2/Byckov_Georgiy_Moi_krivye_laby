#include <iostream>
#include <string>
#include <string.h>
void min(int &a, int &b)
{

    if (b < a)
    {
        int temp = a;
        a = b;
        b = temp;
    }
}
struct Atom
{
    char name[20] = {0};
    int mass = 0;
    int charge = 0;
    Atom()
    {
    }
    Atom(const char a[20], int b, int c)
    {
        for (int i = 0; a[i] != '\0'; i++)
        {
            name[i] = a[i];
        }
        mass = b;
        charge = c;
    }
    Atom operator-=(const Atom other)
    {
        mass = mass - other.mass;
        charge = charge - other.charge;
        mass *= -1;
        charge *= -1;
    }
    bool operator==(const Atom other)
    {
        if ((other.mass == mass) and (charge == other.charge))
        {
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
    Atom beta_1("beta+", 0, 1);
    Atom beta_2("beta-", 0, -1);
    Atom alpha("alpha", 4, 2);
    std::cin >> n;
    Atom *array = new Atom[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> array[i].name >> array[i].mass >> array[i].charge;
    }
    int m = 0;
    std::cin >> m;
    char bag[20] = "NO DATA";
    char cout[m][20] = {0};
    for (int i = 0; i < m; i++)
    {
        Atom temp("temp", 0, 0);
        char a[20] = {0};
        char reac[20] = {0};
        std::cin >> a >> reac;
        if (strncmp(beta_1.name, reac, sizeof(a)) == 0)
        {
            temp = beta_1;
        }
        else if (strncmp(beta_2.name, reac, sizeof(a)) == 0)
        {
            temp = beta_2;
        }
        else if (strncmp(alpha.name, reac, sizeof(a)) == 0)
        {
            temp = alpha;
        }
        for (int j = 0; j < n; j++)
        {
            if (strncmp(array[j].name, a, sizeof(a)) == 0)
            {
                temp -= array[i];
                break;
            }
        }
        std::cout << temp.name << " " << temp.mass << " " << temp.charge;
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            if (temp == array[j])
            {
                memcpy(cout[i], array[j].name, sizeof(cout[i]));
                flag = false;
                break;
            }
        }
        if (flag)
        {
            memcpy(cout[i], bag, sizeof(cout[i]));
        }
    }
    for (int i = 0; i < m; i++)
        std::cout << cout[i] << '\n';
    return 0;
}