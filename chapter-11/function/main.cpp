#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <deque>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <string>
#include <thread>
#include <unordered_map>
#include <utility>
#include <vector>

int sum(int a, int b) {
  return a + b;
}

int round_it(double x) {
  return static_cast<int>(std::floor(x + 0.5));
}

enum class RoundStyle {
  Truncate,
  Round,
};

struct Round {
  RoundStyle style;
  Round(RoundStyle st) : style{st} {}
  int operator()(double x) const {
    return static_cast<int>(style == RoundStyle::Round ? (x + 0.5) : x);
  }
};

int main() {
  std::function<int(int, int)> func {sum};
  auto res = func(1, 2);
  std::cerr << res << "\n";


  std::function<int(double)> fun;

  fun = round_it;
  std::cerr << fun(7.6) << "\n";

  fun = Round(RoundStyle::Truncate);
  std::cerr << fun(7.6) << "\n";

  RoundStyle style = RoundStyle::Round;
  fun = [style](double x) {
    return static_cast<int>(style == RoundStyle::Round ? (x + 0.5) : x);
  };
  std::cerr << fun(7.6) << "\n";

  std::vector<double> v{7.6};
  fun = Round(RoundStyle::Round);
  std::transform(v.begin(), v.end(), v.begin(), fun);
  std::cerr << v[0] << "\n";
}