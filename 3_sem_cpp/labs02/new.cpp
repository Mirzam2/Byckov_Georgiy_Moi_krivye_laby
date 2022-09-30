#include <iostream>
#include <set>
#include <random>

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
    SetState operator+= (const SetState &rha){
        
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
    ProbabilityTest pt(10, 0, 100, 100000);
    std::cout << pt(d) << std::endl;
    std::cout << pt(s) << std::endl;
    std::cout << pt(ss) << std::endl;
    return 0;
}
