#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>


int main() {
  std::list<char> chars{'a', 'b', 'c'};
  
  auto it = chars.begin();
  auto it2 = chars.end();
  it++;
  it2--;

  chars.insert(it, 'r');
  chars.erase(it2);

  for (const char& ch: chars) {
    std::cout << ch << "\n";
  }
}