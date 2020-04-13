#include <algorithm>
#include <bitset>
#include <cassert>
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
  auto t = std::make_tuple(1, 1.1);

  std::cerr << std::get<0>(t) << "\n";
  std::cerr << std::get<1>(t) << "\n";
}