#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>


struct Record {
  int id;
  std::string name;

  bool operator==(const Record& other) const {
    return (name == other.name) && (id == other.id);
  }
};


struct RecordHasher {
  size_t operator()(const Record& rec) const {
    return std::hash<int>()(rec.id) ^ std::hash<std::string>()(rec.name);
  }
};


int main() {
  Record r1{1, "joe"};
  Record r2{2, "mike"};

  std::unordered_map<Record, long, RecordHasher> entries{
    {r1, 0x2342},
    {r2, 0x092451},
  };

  std::cout << entries[r1] << "\n";
}