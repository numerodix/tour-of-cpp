#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>


using MyString = std::basic_string<double>;


int main() {
  std::string name{"lex"};

  name[0] = 'j';
  name.replace(0, 2, "hello, ");

  std::cout << name << std::endl;
  std::cout << name.at(7) << std::endl;

  for (char c: name) {
    std::cout << c << std::endl;
  }

  // my goofy custom string
  MyString my{1.1, 2.2};
  // can't print it out because it doesn't support streams
  // std::cout << my << std::endl;
}