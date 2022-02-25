#include <iostream>
#include <fstream>
#include <random>
#include <ctime>

using namespace std;

const int N_MAX = 100; //количество дислокаций
const long int K_MAX = N_MAX * N_MAX;
//генерация случайностей
mt19937 generator(time(0));
uniform_int_distribution<int> distr(1, 4);

void dislok(short (&mas)[N_MAX][N_MAX], int (&disl)[K_MAX][2], const int N, const int K) // фунция генерации начальных положений дизлокаций
{
    uniform_int_distribution<int> unit_generate(0, N - 1);
    if (K == 1) // что бы в опытах для 1 задания генерировалась в центре
    {
        mas[N / 2][N / 2] = 1;
        disl[0][0] = N / 2;
        disl[0][1] = N / 2;
    }
    else
    {
        for (int unit = 0; unit < K; unit++)
        {
            while (true)
            {
                // генерация случайных положений
                int unit_i = unit_generate(generator);
                int unit_j = unit_generate(generator);
                if (mas[unit_i][unit_j] == 0) // проверка что бы не было пересечений
                {
                    mas[unit_i][unit_j] = 1;
                    disl[unit][0] = unit_i;
                    disl[unit][1] = unit_j;
                    break;
                }
            }
        }
    }
}
void print(short (&mas)[N_MAX][N_MAX], const int N) // функция вывода массива
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
void swap(int &a, int &b) // функция обмена местами
{
    int temp = a;
    a = b;
    b = temp;
}
short clash(short int (&mas)[N_MAX][N_MAX], int i_1, int j_1, int i, int j, bool &flag, const int N) // проверка и действие на слипанием с другой дислокацией
{
    short dk = 0;
    if (mas[i_1][j_1] > 0)
    {
        if (mas[i_1][j_1] == 1)
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
    // cout << dk << endl;
    return dk;
}
void file_save(long long int(data)[], int size)
{
    ofstream file("results.json"); // Открываем файл для записи
    file << "[" << endl;
    for (int i = 0; i < size - 1; i++)
    {
        file << data[i] << ", "; // Запись в файл оператором <<
    }
    file << data[size - 1];
    file << "]";
    file.close(); // Закрывем файл!!!
}
long long int exp(short (&mas)[N_MAX][N_MAX], int (&disl)[K_MAX][2], const int N, const int K) // эксперимент
{
    int k = K;                              // счетчик дизлокаций которые могут двигаться
    long long int s = 0;                    // счетчик шагов
    long long int s_1 = 0;                  // счетчик что бы не переполнилось
    long long int stop = 100000000 / K - 1; // предел массива генерации
    for (int mem = 0; mem < K; mem++)
    {
        int i = disl[mem][0];
        int j = disl[mem][1];
        if (mas[i][j] == 1)
        {
            if (i == 0 or i == N - 1 or j == 0 or j == N - 1) // проверка на касание края
            {
                mas[i][j] = 2; // дизлокации которые остановились
                k = k - 1;
            }
            else
            {
                bool flag = true;
                k = k - clash(mas, i + 1, j, i, j, flag, N);
                k = k - clash(mas, i - 1, j, i, j, flag, N);
                k = k - clash(mas, i, j + 1, i, j, flag, N);
                k = k - clash(mas, i, j + 1, i, j, flag, N);
            }
        }
    }
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
                    break;
                case 2:
                    j_1 = j + 1; // вправо
                    break;
                case 3:
                    i_1 = i - 1; // вниз
                    break;
                case 4:
                    j_1 = j - 1; // влево
                    break;
                }
                if (mas[i_1][j_1] == 0) // проверка что бы не врезались
                {
                    swap(mas[i][j], mas[i_1][j_1]); // движение
                }
                else
                {
                    // не двигается
                    i_1 = i;
                    j_1 = j;
                }
                disl[mem][0] = i_1;
                disl[mem][1] = j_1;
            }
            // print(mas); cout << endl << k << endl;
            //  cout << disl[0][0] << " " << disl[0][1] << endl;
            s_1++;
            if (s_1 >= stop)
            {
                mt19937 generator(time(0));
                s_1 = 0;
            }
        }
        for (int mem = 0; mem < K; mem++)
        {
            int i = disl[mem][0];
            int j = disl[mem][1];
            if (mas[i][j] == 1)
            {
                if (i == 0 or i == N - 1 or j == 0 or j == N - 1) // проверка на касание края
                {
                    mas[i][j] = 2; // дизлокации которые остановились
                    k = k - 1;
                }
                else
                {
                    bool flag = true;
                    k = k - clash(mas, i + 1, j, i, j, flag, N);
                    k = k - clash(mas, i - 1, j, i, j, flag, N);
                    k = k - clash(mas, i, j + 1, i, j, flag, N);
                    k = k - clash(mas, i, j + 1, i, j, flag, N);
                }
            }
        }
        s++;
        // n rint(mas);
    }
    return s;
}
int main()
{
    const long long int number_generation = 1000;
    long long int summ = 0;
    ofstream file("results.json"); // Открываем файл для записи
    file << "[" << endl;
    int N = N_MAX;
    for (int K = 10; K <= K_MAX; K = K + 10)
    {
        summ = 0;
        for (int i = 0; i < number_generation; i++)
        {
            short int massiv[N_MAX][N_MAX] = {0};
            int disl[K_MAX][2] = {0};
            dislok(massiv, disl, N, K);
            // print(massiv);
            // cout << endl;
            // if (i != number_generation - 1){file << exp(massiv, disl) << ", ";}else{file << exp(massiv, disl);}
            summ = summ + exp(massiv, disl, N, K);
            // Запись в файл оператором <<
            // results[i] = exp(massiv, disl);
        }
        summ /= number_generation;
        file << summ;
        if (N != N_MAX)
        {
            file << ", ";
        }
        cout << summ << endl;
    }
    file << "]";
    file.close(); // Закрывем файл!!!
    return 0;
}