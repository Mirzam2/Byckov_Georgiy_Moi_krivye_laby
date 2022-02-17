#include <iostream>
#include <random>
#include <ctime>
using namespace std;
//генерация случайностей
mt19937 generator(time(0));
uniform_int_distribution<int> distr(1, 4);

const int N = 10;               // размер локации
const int kol = 1;              //количество дислокаций
void dislok(short (&mas)[N][N]) // фунция генерации начальных положений дизлокаций
{
    mas[N / 2][N / 2] = 1;
    mas[4][5] = 1;
}
void print(short (&mas)[N][N]) // функция вывода массива
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }
}
void swap(int &a, int &b) // фунция обмена местами
{
    int temp = a;
    a = b;
    b = temp;
}
short clash(short (&mas)[N][N], int i_1, int j_1, int i, int j, bool &flag)
{
    short dk = 0;
    if (mas[i_1][j_1] > 0)
    {
        if (mas[i_1][j_1] != 2)
        {
            mas[i_1][j_1] = 2;
            dk++;
        }
        if (flag){
        mas[i][j] = 2;
        dk++;
        flag = false;
        }
    }
    return dk;
}
int exp(short (&mas)[N][N])
{
    int k = 2; // количество дизлокаций которые могут двигаться
    int s = 0; // счетчик шагов
    while (k > 0)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (mas[i][j] == 1)
                {
                    int a = distr(generator);
                    // cout << "a = " << a << " i = " << i << " j = " << j << endl;
                    int i_1 = i, j_1 = j; // координаты возможного перемещения
                    switch (a)
                    {
                    case 1:
                        i_1 = i + 1; // вверх
                        // cout << "sos1";
                        mas[i][j] = 3; // замена что бы за один цикл не двигалось несколько раз
                        break;
                    case 2:
                        // cout << "sos2";
                        j_1 = j + 1;   // вправо
                        mas[i][j] = 3; // замена что бы за один цикл не двигалось несколько раз
                        break;
                    case 3:
                        // cout << "sos3";
                        i_1 = i - 1; // вниз
                        break;
                    case 4:
                        // cout << "sos4";
                        j_1 = j - 1; // влево
                        break;
                    }
                    // cout << "i_1 = " << i_1 << " j_1 = " << j_1 << endl;
                    swap(mas[i][j], mas[i_1][j_1]);                           // движение
                    if (i_1 == 0 or i_1 == N - 1 or j_1 == 0 or j_1 == N - 1) // проверка на касание края
                    {
                        mas[i_1][j_1] = 2; // дизлокации которые остановились
                        k = k - 1;
                    }
                    else
                    {
                        bool flag = true;
                        k = k - clash(mas, i_1 + 1, j_1, i_1, j_1, flag);
                        k = k - clash(mas, i_1 - 1, j_1, i_1, j_1, flag);
                        k = k - clash(mas, i_1, j_1 + 1, i_1, j_1, flag);
                        k = k - clash(mas, i_1, j_1 + 1, i_1, j_1, flag);
                    }
                }
                if (mas[i][j] == 3)
                { //проверка не двигался ли он
                    mas[i][j] = 1;
                }
            }
        }
        // print(mas);

        s++;
    }
    return s;
}
int main()
{
    int seed = time(0);
    mt19937 generator(seed);
    uniform_int_distribution<int> distr(1, 4);
    for (int i = 0; i < 15; i++)
    {
        short massiv[N][N] = {0};
        dislok(massiv);
        cout << exp(massiv) << endl;
        print(massiv);
    }
    return 0;
}