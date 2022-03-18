#include <iostream>
struct Students
{
    char name[20];
    int m = 0;
};
int main()
{
    Students *team = new Students[10];
    for (int i = 0; i < 10; i++)
    {
        std::cin >> team[i].name >> team[i].m;
    }
    int m_crit = 0;
    std::cin >> m_crit;
    for (int i = 0; i < 10; i++)
    {
        if (team[i].m >= m_crit)
            std::cout << team[i].name << " ";
    }
    delete[] team;
    return 0;
}