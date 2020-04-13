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

int main() {
  auto t0 = std::chrono::high_resolution_clock::now();

  int sum = 0;
  for (int i=0; i < 1000000000; ++i) {
    sum += i;
  }

  auto t1 = std::chrono::high_resolution_clock::now();

  std::cerr << (t1 - t0).count() << "\n";
  std::cerr << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count() << "\n";
}