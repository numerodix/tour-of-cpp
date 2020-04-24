#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

int main() {
  assert(true == std::numeric_limits<int>::is_integer);

  std::cout << std::numeric_limits<unsigned int>::max() << "\n";
  std::cout << std::numeric_limits<unsigned long>::max() << "\n";

  std::cout << ((1UL << 32) - 1) << "\n";
}