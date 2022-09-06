// ProblemC.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

struct Platform {
    int height;
    int min;
    Platform()
        : height(0), min(-1) {
    }
};

int d(const Platform& a, const Platform& b) {
    return abs(a.height - b.height);
}

int main() {
    int n;
    std::cin >> n;
    if (n == 1) {
        std::cout << 0;
        return 0;
    }
    Platform prev, current;
    std::cin >> prev.height >> current.height;
    prev.min = 0;
    current.min = d(prev, current);
    for (int i = 2; i < n; ++i) {
        Platform nextPlanftorm;
        std::cin >> nextPlanftorm.height;
        int simple_step = d(nextPlanftorm, current) + current.min;
        int super_step = d(nextPlanftorm, prev) * 3 + prev.min;
        nextPlanftorm.min = std::min(simple_step, super_step);
        prev = current;
        current = nextPlanftorm;
    }
    std::cout << current.min;
    return 0;
}