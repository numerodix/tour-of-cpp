#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <istream>
#include <ostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>


struct Entry {
  std::string name;
  int number;
};


std::istream &operator>>(std::istream &is, Entry& entry) {
  char c, c2;
  // parse: {"
  if (is >> c && c == '{' && is >> c2 && c2 == '"') {
    std::string name;

    // read a char until the closing double quote
    while (is.get(c) && c != '"') {
      name += c;
    }

    if (is >> c && c == ',') {
      int number = 0;
      if (is >> number >> c && c == '}') {
        entry = {name, number};
        return is;
      }
    }
  }

  is.setstate(std::ios_base::failbit);
  return is;
}


std::ostream& operator<<(std::ostream& os, const Entry& entry) {
  return os << "{'" << entry.name << "', " << entry.number << "}";
}


int main() {
  Entry entry;

  std::cin >> entry;

  std::cout << entry << std::endl;
}