#include <iostream>
int min(void *arr, int arr_size, int type_size, int (*compare)(void *, void *));
int comp_int(void *a, void *b)
{
    if ((*reinterpret_cast<int *>(a)) < (*reinterpret_cast<int *>(b)))
    {
        return 1;
    }

    return 0;
}
int min(void *arr, int arr_size, int type_size, int (*compare)(void *, void *))
{
    int index = 0;
    void *element = arr;
    for (int i = 0; i < arr_size; i++)
    {
        if (compare(arr + i * type_size, element))
        {
            index = i;
            element = &arr + i * type_size;
        }
        //std::cout << i << " " << element << " " << (arr + i * type_size) << "\n";
    }
    return index;
}
int max(void *arr, int arr_size, int type_size, int (*compare)(void *, void *))
{
    int index = 0;
    void *element = arr;
    for (int i = 0; i < arr_size; i++)
    {
        if (compare(element, arr + i * type_size))
        {
            index = i;
            element = &arr + i * type_size;
        }
        //std::cout << i << " " << element << " " << (arr + i * type_size) << "\n";
    }
    return index;
}
int main()
{

    int *massive = new int[3];
    massive[0] = 7;
    massive[1] = 5;
    massive[2] = 1;
    std::cout << min(massive, 3, sizeof(int), comp_int) << "\n";
        std::cout << max(massive, 3, sizeof(int), comp_int);
}
