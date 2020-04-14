#include <algorithm>
#include <bitset>
#include <chrono>
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

using namespace std::placeholders;

int sum(int a, int b) {
  return a + b;
}

int main() {
  auto add_1 = std::bind(sum, 1, _1);
  int res = add_1(2);
  std::cerr << res << "\n";
}