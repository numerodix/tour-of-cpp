#include <algorithm>
#include <cassert>
#include <deque>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>


int main() {
  std::deque<float> q;

  q.push_front(2.3);
  q.push_back(4.5);
  q.push_back(6.5);
  q.push_front(1.3);

  for (auto& el: q) {
    std::cout << el << "\n";
  }
}