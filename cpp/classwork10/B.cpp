#include <iostream>
int main()
{
    int n = 0;
    std::cin >> n;
    int *price = new int[n + 3];
    int mas[3] = {0};
    for (int i = 0; i < n; i++)
        std::cin >> price[i];
    mas[0] = price[0];
    mas[1] = price[1];
    mas[2] = price[2];
    for (int i = 3; i < n; i += 3)
    {
        for (int j = 0; j < 3; j++)
        {
            mas[j] = std::min(mas[0], std::min(mas[2], mas[1])) + price[i + j];
        }
        //std::cout << mas[0] << " " << mas[1] << " " << mas[2] << '\n';
    }
    //std::cout << mas[0] << " " << mas[1] << " " << mas[2] << '\n';
    std::cout << mas[(n - 1) % 3];
    delete[] price;
}