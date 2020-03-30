#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <ostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>


struct Entry {
  std::string name;
  int number;
};


std::ostream& operator<<(std::ostream& os, const Entry& entry) {
  return os << "{'" << entry.name << "', " << entry.number << "}";
}


int main() {
  Entry entry{.name = "hank", .number = 42};

  std::cout << entry << std::endl;
}