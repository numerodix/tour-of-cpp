#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>


struct Entry {
  std::string name;
  int number;
};


void f(const std::vector<Entry>& entries) {
  for (const Entry& entry: entries) {
    std::cout << entry.name << "\n";
  }
}


int main() {
  std::vector<Entry> entries{Entry{"bob", 4}};
  f(entries);

  // "default value" of Entry: emptry string and number 0
  Entry empty;
  std::cout << empty.name << ", " << empty.number << "\n";

  // initialized 
  std::vector<Entry> ents(20);
  std::cout << ents.size() << "\n";
  std::cout << ents.capacity() << "\n";
  for (auto en: ents) {
    std::cout << en.name << ", " << en.number << "\n";
  }
}