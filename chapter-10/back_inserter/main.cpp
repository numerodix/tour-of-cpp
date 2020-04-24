#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

int main() {
  std::vector<int> src{1, 2, 3};
  std::vector<int> dest{};

  // crashes
  // std::copy(src.begin(), src.end(), dest.begin());

  // works
  std::copy(src.begin(), src.end(), std::back_inserter(dest));

  for (auto el: dest) {
    std::cout << el << '\n';
  }
}