#include <iostream>
#include <cmath>

struct base_exception
{
    virtual std::string what() = 0;
    // smth here
};

struct math_exception final : base_exception
{
    std::string what() override
    {
        return "AAAAAAAAAAAAAAAAA ERROR, You stupid man, you cannot divide by zero";
    }
    // smth here
};

struct invalid_argument final : base_exception
{
    std::string what() override
    {
        return "AAAAAAAAAAAAAAAAA ERROR, You stupid man, you cannot take the root out of the negative number";
    }
    // smth here
};

double inverse(double x)
{
    if (x == 0)
        throw math_exception();
    return 1. / x;
}

double root(double x)
{
    if (x < 0)
        throw invalid_argument();
    return std::sqrt(x);
}
int main()
{
    float g = 0;
    try
    {
        std::cout << root(g) << std::endl;
        std::cout << inverse(g) << std::endl;
    }
    catch (invalid_argument invarg)
    {
        std::cout << invarg.what() << std::endl;
    }
    catch (math_exception mexc)
    {
        std::cout << mexc.what() << std::endl;
    }
}