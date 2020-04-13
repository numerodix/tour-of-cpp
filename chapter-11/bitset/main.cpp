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
#include <vector>

int main() {
  std::bitset<16> bits{0xf0f0};

  std::cerr << bits << "\n";

  std::cerr << (bits << 5) << "\n";
}