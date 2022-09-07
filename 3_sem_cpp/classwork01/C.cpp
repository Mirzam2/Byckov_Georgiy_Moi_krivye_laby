#include <iostream>
#include <cstring>

void swap(void *a, void *b, int size)
{
    void *tmp = malloc(size);
    std::memcpy(tmp, a, size);
    std::memcpy(a, b, size);
    std::memcpy(b, tmp, size);
    free(tmp);
}
void print(int *mas, int n) //вывод массива
{
    for (int i = 0; i < n; i++)
    {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
}
int comp_int(void *a, void *b)
{
    if ((*reinterpret_cast<int *>(a)) < (*reinterpret_cast<int *>(b)))
    {
        return 1;
    }

    return 0;
}
int comp_double(void *a, void *b)
{
    if ((*reinterpret_cast<double *>(a)) < (*reinterpret_cast<double *>(b)))
    {
        return 1;
    }

    return 0;
}
// void sortic(int *mas, int left, int right);
void qsort(void *arr, int type_size, int left, int right, int (*compare)(void *, void *)) // сортировка
{
    if (left < right)
    {
        int pos = (left + right) / 2;
        void *opor = arr + (left + right) / 2 * type_size;
        int i = left, j = right;
        while (true)
        {
            while (compare(arr + i * type_size, opor))
            {
                i++;
            }
            while (opor, compare(opor,arr + j * type_size))
            {
                j--;
            }
            if (i >= j)
            {
                pos = j;
                break;
            }

            swap(arr + i * type_size, arr + j * type_size, type_size);
            i++;
            j--;
        }
        qsort(arr, type_size, left, pos, compare);
        qsort(arr, type_size, pos + 1, right, compare);
    }
}
int main()
{
    int (*compare[]) (void*, void*) = {comp_int, comp_double}; 
    int *massive = new int[3];
    massive[0] = 7;
    massive[1] = 5;
    massive[2] = 3;
    qsort(massive, sizeof(int), 0, 2, compare[0]);
    print(massive, 3);
    delete[] massive;
    return 0;
}