#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>


template<typename T>
class LessThan {
    const T val;

    public:
        LessThan(const T& v) : val{v} {}
        // call syntax operator!
        bool operator()(const T& x) const { return x < val; }
};


template<typename C, typename P>
int count(const C& cont, P pred) {
  int cnt = 0;
  for (const auto& elem: cont) {
    if (pred(elem)) {
      ++cnt;
    }
  }
  return cnt;
}


int main() {
  std::vector<double> nums{1.2, 2.4, 3.2};
  auto predicate = LessThan<double>{3.0};

  assert(count(nums, predicate) == 2);
  
  // lambda version!!
  double threshold = 3.0;
  auto predicate_lambda = [&](double other) { return other < threshold; };
  assert(count(nums, predicate_lambda) == 2);
}