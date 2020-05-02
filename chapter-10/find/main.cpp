#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

int main() {
  std::string str{"abcabcabcabcabc"};

  auto it = std::find(str.begin(), str.end(), 'b');
  std::cout << *it << '\n';
}