#include <iostream>
#include <fstream>
#include <random>
#include <ctime>

using namespace std;

const long int N = 10; // размер локации
const int K = 3;       //количество дислокаций

//генерация случайностей
mt19937 generator(time(0));
uniform_int_distribution<int> distr(1, 2);
uniform_int_distribution<int> unit_generate(0, N - 1);

void dislok(short (&mas)[N], int (&disl)[K]) // фунция генерации начальных положений дизлокаций
{
    if (K == 1) // что бы в опытах для 1 задания генерировалась в центре
    {
        mas[N / 2] = 1;
        disl[0] = N / 2;
    }
    else
    {
        for (int unit = 0; unit < K; unit++)
        {
            while (true)
            {
                // генерация случайных положений
                int unit_i = unit_generate(generator);
                if (mas[unit_i] == 0) // проверка что бы не было пересечений
                {
                    mas[unit_i] = 1;
                    disl[unit] = unit_i;
                    break;
                }
            }
        }
    }
}
void print(short (&mas)[N]) // функция вывода массива
{
    for (int i = 0; i < N; i++)
    {
        cout << mas[i] << " ";
    }
    cout << endl;
}
void swap(int &a, int &b) // функция обмена местами
{
    int temp = a;
    a = b;
    b = temp;
}
short clash(short int (&mas)[N], int i_1, int i, bool &flag) // проверка и действие на слипанием с другой дислокацией
{
    short dk = 0;
    if (mas[i_1] > 0)
    {
        if (mas[i_1] == 1)
        {
            mas[i_1] = 2;
            dk++;
        }
        if (flag)
        {
            mas[i] = 2;
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
long long int exp(short (&mas)[N], int (&disl)[K]) // эксперимент
{
    int k = K;                              // счетчик дизлокаций которые могут двигаться
    long long int s = 0;                    // счетчик шагов
    long long int s_1 = 0;                  // счетчик что бы не переполнилось
    long long int stop = 100000000 / K - 1; // предел массива генерации
    for (int mem = 0; mem < K; mem++)
    {
        int i = disl[mem];
        if (mas[i] == 1)
        {
            if (i == 0 or i == N - 1) // проверка на касание края
            {
                mas[i] = 2; // дизлокации которые остановились
                k = k - 1;
            }
            else
            {
                bool flag = true;
                k = k - clash(mas, i + 1, i, flag);
                k = k - clash(mas, i - 1, i, flag);
            }
        }
    }
    while (k > 0)
    {
        for (int mem = 0; mem < K; mem++)
        {
            int i = disl[mem];
            if (mas[i] == 1)
            {
                int a = distr(generator);
                // cout << "a = " << a << " i = " << i << " j = " << j << endl;
                int i_1 = i; // координат ы возможного перемещения
                switch (a)
                {
                case 1:
                    i_1 = i + 1; // вправо
                    break;
                case 2:
                    i_1 = i - 1; // влево
                    break;
                }
                if (mas[i_1] == 0) // проверка что бы не врезались
                {
                    swap(mas[i], mas[i_1]); // движение
                }
                else
                {
                    // не двигается
                    i_1 = i;
                }
                disl[mem] = i_1;
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
            int i = disl[mem];
            if (mas[i] == 1)
            {
                if (i == 0 or i == N - 1) // проверка на касание края
                {
                    mas[i] = 2; // дизлокации которые остановились
                    k = k - 1;
                }
                else
                {
                    bool flag = true;
                    k = k - clash(mas, i + 1, i, flag);
                    k = k - clash(mas, i - 1, i, flag);
                }
            }
        }
        s++;
        print(mas);
        cout << endl
             << "sosi " << k << endl;
    }
    return s;
}
int main()
{
    const long long int number_generation = 1;
    // long long int results[number_generation];
    ofstream file("results_3.json"); // Открываем файл для записи
    file << "[" << endl;
    for (int i = 0; i < number_generation; i++)
    {
        short int massiv[N] = {0};
        int disl[K] = {0};
        dislok(massiv, disl);
        print(massiv);
        cout << endl;
        if (i != number_generation - 1)
        {
            file << exp(massiv, disl) << ", ";
        }
        else
        {
            file << exp(massiv, disl);
        }
        // Запись в файл оператором <<
        // results[i] = exp(massiv, disl);
    }

    file << "]";
    file.close(); // Закрывем файл!!!

    // file_save(results, number_generation);
    return 0;
}