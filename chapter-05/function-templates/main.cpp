#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>


template<typename Container, typename Value>
Value sum(const Container& cont, Value acc) {
  for (auto el: cont) {
    acc += el;
  }
  return acc;
}


int main() {
  std::vector<double> nums{1.2, 2.4};

  // all arith on doubles
  assert(sum(nums, 3.0) == 6.6);

  // forced truncation to ints because `acc` is an int!
  assert(sum(nums, 3) == 6);
}