#include <cassert>
#include <iostream>
#include <random>
#include <vector>

int main() {
  std::random_device dev{};
  std::default_random_engine eng{dev()};
  std::uniform_int_distribution<int> dist{1, 6};

  for (int i=0; i < 10; ++i) {
    int val = dist(eng);
    std::cout << val << ", ";
  }
}