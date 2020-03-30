#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>


int main() {
  std::cout.precision(8);
  std::cout << 1234.5678901234 << " " << 123456789 << "\n";


  std::cout << 1234 << ", 0x" << std::hex << 1234 << ", 0o" << std::oct << 1234 << '\n';

  constexpr double d = 123.4567;

  std::cout << d << " "
    << std::scientific << d << " "
    << std::hexfloat << d << " "
    << std::fixed << d << " "
    << std::defaultfloat << d << "\n";
}