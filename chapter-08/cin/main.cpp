#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>


int main() {
  // int i{-1};
  // double d{-5.1};
  // std::cin >> i >> d;
  // std::cout << "double: " << d << "    int: " << i << std::endl;

  // std::string first;
  // std::string second;
  // std::cin >> first >> second;
  // std::cout << "first: " << first << "    second: " << second << std::endl;

  std::string line;
  getline(std::cin, line);
  std::cout << line << std::endl;
}