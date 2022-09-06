#include <iostream>
#include <cmath>


double integrate(
    double left_bound,
    double right_bound,
    double step,
    double (*func) (double)
) {
  double res = 0.;
  for (double x = left_bound; x < right_bound; x += step) {
    res += func(x) * step;
  }
  return res;
}


int main() {
  double left_bound = 0., right_bound = 0., step = 0.;
  std::cin >> left_bound >> right_bound >> step;
  std::cout << integrate(left_bound, right_bound, step, std::log) << std::endl;
  std::cout << integrate(left_bound, right_bound, step, std::cos) << std::endl;
  return 0;
}