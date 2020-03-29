#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>


void ex1() {
  std::vector<int> nums;

  int num{0};
  while (std::cin >> num) {
    nums.push_back(num);
  }

  for (std::size_t i=0; i != nums.size(); ++i) {
    std::cout << nums[i] << std::endl;
  }
}


void ex2() {
  std::vector<int> nums;

  while(std::cin) {
    for (int i; std::cin >> i; ) {
      nums.push_back(i);
    }

    if (std::cin.eof()) {
      break;
    }

    else if (std::cin.fail()) {
      std::cin.clear();
      char ch;

      if (std::cin >> ch) {
        switch(ch) {
          case '{':
            break;
          case '}':
            break;
          default:
            std::cin.setstate(std::ios_base::failbit);
        }
      }
    }
  }

  std::cout << "got: ";
  for (auto i: nums) {
    std::cout << i << ' ';
  }
}


int main() {
  ex2();
}