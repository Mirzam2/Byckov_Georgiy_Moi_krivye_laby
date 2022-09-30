#include <iostream>
#include <set>
#include <random>
#include <cmath>
#include <fstream>
int Max_Size = 1000;
class SetState
{
protected:
    std::set<int> state;

public:
    SetState(std::set<int> const &src) : state(src) {} //базовый, имеенно для списка
    SetState()
    {
        state.clear();
    }

    bool contains(int s) const
    {
        return state.count(s) > 0;
    }
    SetState operator+=(const SetState &rha)
    {
        for (std::set<int>::iterator i = rha.state.begin(); i != rha.state.end(); ++i)
        {
            for (std::set<int>::iterator j = state.begin(); j != state.end(); ++j)
            {
                if (*i == *j)
                {
                    state.emplace(*i);
                }
            }
        }
        return *this;
    }
    SetState operator+(const SetState &rha) const
    {
        SetState result(state);
        result += rha;
        return result;
    }
    SetState operator*=(const SetState &rha)
    {
        for (std::set<int>::iterator i = rha.state.begin(); i != rha.state.end(); ++i)
        {
            for (std::set<int>::iterator j = state.begin(); j != state.end(); ++j)
            {
                if (*i == *j)
                {
                    state.emplace(*i);
                }
            }
        }
        return *this;
    }
    SetState operator*(const SetState &rha) const
    {
        SetState result(state);
        result *= rha;
        return result;
    }
    SetState operator!() const
    {
        SetState Res;

        for (int i = -Max_Size; i <= Max_Size; ++i)
        {
            if (this->state.count(i) == 0)
            {
                Res.state.emplace(i);
            }
        }

        return Res;
    }
};

class DiscreteState : public SetState
{
public:
    DiscreteState(int element)
    {
        state.insert(element);
    }
    DiscreteState() : DiscreteState(0) {}
};

class SegmentState : public SetState
{
public:
    SegmentState(int start, int end)
    {
        for (int i = start; i <= end; ++i)
        {
            state.insert(i);
        }
    }
    SegmentState() : SegmentState(0, 0){};
};

class ProbabilityTest
{
private:
    unsigned seed;
    int test_min, test_max;
    unsigned test_count;

public:
    ProbabilityTest(unsigned seed, int test_min, int test_max, unsigned test_count) : seed(seed), test_min(test_min), test_max(test_max), test_count(test_count) {}
    float operator()(SetState const &s) const
    {
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<int> dstr(test_min, test_max);
        unsigned good = 0;
        for (unsigned cnt = 0; cnt != test_count; ++cnt)
            if (s.contains(dstr(rng)))
                ++good;

        return static_cast<float>(good) / static_cast<float>(test_count);
    }
};

int main(int argc, const char *argv[])
{
    DiscreteState d(1);
    SegmentState s(0, 10);
    SetState ss({1, 3, 5, 7, 23, 48, 57, 60, 90, 99});
    std::ofstream file("results.json"); // Открываем файл для записи
    file << "[" << '\n';
    for (int N = 100; N <= 1000; ++N)
    {
        //std::default_random_engine rng(time_t());
        //std::uniform_int_distribution<int> dstr(0, 2000000);
        float result = 0.0;
        for (int i = 0; i < 1000; ++i)
        {
            ProbabilityTest pt(time_t(), 0, 100, N);
            result +=pt(ss) / N;
        }
        file << result;
        if (N != 1000)
        {
            file << ", ";
        }
        //std::cout << result << '\n';
    }
    file << "]";
    file.close();
    ProbabilityTest pt(10, 0, 100, 100000);
    std::cout << pt(d) << std::endl;
    std::cout << pt(s) << std::endl;
    std::cout << pt(ss) << std::endl;
    return 0;
}
