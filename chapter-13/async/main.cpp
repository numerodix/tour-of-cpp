#include <algorithm>
#include <cassert>
#include <chrono>
#include <condition_variable>
#include <deque>
#include <functional>
#include <future>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <mutex>
#include <numeric>
#include <queue>
#include <stdexcept>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>


int sum(int a, int b) {
  return a + b;
}

int main() {
  std::future<int> fut = std::async(sum, 1, 2);

  int result = fut.get();
  std::cerr << "result: " << result << "\n";
}