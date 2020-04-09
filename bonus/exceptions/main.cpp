#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <list>
#include <regex>
#include <string>
#include <vector>


class Dummy {
 public:
  Dummy() {}
  ~Dummy() {
    std::cout << "dtor hereeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n";
  }
};


int main() {
  Dummy d{};

  // try {
    throw std::runtime_error("uaaaaa");
  // } catch (std::runtime_error& e) {
    // std::cout << "e was: " << e.what() << "\n";
  // }
}