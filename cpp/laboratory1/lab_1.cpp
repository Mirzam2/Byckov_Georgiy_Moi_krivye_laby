#include <iostream>
#include <random>
#include <ctime>
using namespace std;
//генерация случайностей
mt19937 generator(time(0));
uniform_int_distribution<int> distr(1, 4);

const int N = 1000;                                // размер локации
const int K = 1;                                   //количество дислокаций
void dislok(short (&mas)[N][N], int (&disl)[K][2]) // фунция генерации начальных положений дизлокаций
{
    mas[N / 2][N / 2] = 1;
    disl[0][0] = N / 2;
    disl[0][1] = N / 2;
    //mas[4][5] = 1;disl[1][0] = 4;disl[1][1] = 5;
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
        if (flag)
        {
            mas[i][j] = 2;
            dk++;
            flag = false;
        }
    }
    return dk;
}
long long int exp(short (&mas)[N][N], int (&disl)[K][2])
{
    int k = K;           // количество дизлокаций которые могут двигаться
    long long int s = 0; // счетчик шагов
    while (k > 0)
    {
        for (int mem = 0; mem < K; mem++)
        {
            int i = disl[mem][0];
            int j = disl[mem][1];
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
                    // mas[i][j] = 3; // замена что бы за один цикл не двигалось несколько раз
                    break;
                case 2:
                    // cout << "sos2";
                    j_1 = j + 1; // вправо
                    // mas[i][j] = 3; // замена что бы за один цикл не двигалось несколько раз
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
                swap(mas[i][j], mas[i_1][j_1]); // движение
                disl[mem][0] = i_1;
                disl[mem][1] = j_1;
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
            // print(mas);
            // cout << disl[0][0] << " " << disl[0][1] << endl;
            s++;
        }
    }
    return s;
}
int main()
{
    for (int i = 0; i < 10000; i++)
    {
        if (i % 20 == 0){
            mt19937 generator(time(0));
        } 
        short massiv[N][N] = {0};
        int disl[K][2] = {0};
        dislok(massiv, disl);
        cout << exp(massiv, disl) << endl;
        // rint(massiv);
    }
    return 0;
}