#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <fstream>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>


int main() {
  std::fstream ofs{"dummy"};

  std::cout.precision(8);
  ofs << 1234.5678901234 << " " << 123456789 << "\n";


  ofs << 1234 << ", 0x" << std::hex << 1234 << ", 0o" << std::oct << 1234 << '\n';

  constexpr double d = 123.4567;

  ofs << d << " "
    << std::scientific << d << " "
    << std::hexfloat << d << " "
    << std::fixed << d << " "
    << std::defaultfloat << d << "\n";
}