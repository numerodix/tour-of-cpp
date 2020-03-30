#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>


template<typename Target =std::string, typename Source =std::string>
Target convert(Source arg) {
  std::stringstream converter;
  Target result;

  if (!(converter << arg) || !(converter >> result) || !(converter >> std::ws).eof()) {
    throw std::runtime_error{"convert<>() failed!"};
  }

  return result;
}



int main() {
  std::stringstream ss;

  ss << "hi, " << "I " << "have " << "a " << "message " << "for " << "you!";
  std::cout << ss.str() << "\n";


  auto x = convert<std::string, double>(4.5);
  std::cout << x << "\n";

  // Source and Target both implied!!
  auto x2 = convert(4.5);
  std::cout << x2 << "\n";
}