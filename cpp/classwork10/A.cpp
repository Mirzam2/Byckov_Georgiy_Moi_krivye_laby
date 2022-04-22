#include <iostream>
int main()
{
    int n = 0;
    std::cin >> n;
    int i = 0;
    int mas[3] = {1, 2, 4};
    for (int i = 3; i < n; i += 3)
    {
        mas[0] = mas[1] + mas[0] + mas[2];
        mas[1] = mas[1] + mas[0] + mas[2];
        mas[2] = mas[1] + mas[0] + mas[2];
    }
    //std::cout << mas[0] << " " << mas[1] << " " << mas[2] << '\n';
    std::cout << mas[(n - 1) % 3];
}