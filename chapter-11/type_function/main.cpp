#include <iostream>
#include <limits>
#include <type_traits>


int main() {
  constexpr double smallest = std::numeric_limits<double>::min();
  std::cerr << smallest << "\n";

  constexpr int size_int = sizeof(int);
  std::cerr << size_int << "\n";

  std::cerr << std::is_arithmetic<int>() << "\n";
}