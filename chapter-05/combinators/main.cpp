#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>


template<typename C, typename Oper>
void for_all(C& cont, Oper op) {
  for (auto& elem: cont) {
    op(elem);
  }
}


int main() {
  std::vector<double> nums{1.2, 2.4, 3.0};

  double sum{0};
  auto adder = [&](double val) { sum += val; };

  for_all(nums, adder);

  assert(sum == 6.6);
}