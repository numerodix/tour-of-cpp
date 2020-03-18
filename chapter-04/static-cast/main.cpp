#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>


int main() {
  uint8_t num1 = 7;
  uint8_t num2 = 7;

  uint64_t bigger = 1UL << 63;

  num1 = static_cast<uint8_t>(bigger);  // can't possibly fit!
  num2 = (uint8_t) bigger;

  assert(num1 == 0);  // super weird!
  assert(num2 == 0);
}