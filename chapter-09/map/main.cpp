#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>


int main() {
  std::map<std::string, int> boats{
    {"floaty", 4},
    {"sinky", 6},
  };

  std::cout << boats["sinky"] << "\n";

  assert(boats["wtf"] == 0);   // wtf key does not exist!!!

  // not found
  auto it = boats.find("fasty");
  assert(it == boats.end());

  // found
  auto it2 = boats.find("sinky");
  assert((*it2).second == 6);
}