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

int main()
{
    char a = 0, b = 0;
    std::cin >> a >> b;
    swap(&a, &b, sizeof(char));
    std::cout << a << " " << b;
    return 0;
}
