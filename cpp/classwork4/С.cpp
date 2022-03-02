#include <iostream>

void func1()
{
    static int func1_counter = 0;
    func1_counter++;
    std::cout << func1_counter << std::endl;
}

int main()
{
    for (int i = 0; i < 10; ++i)
    {
        func1();
    }
    return 0;
}