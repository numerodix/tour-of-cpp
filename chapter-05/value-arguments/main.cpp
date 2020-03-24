#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <list>
#include <stdexcept>


template<typename T, int N>
struct Buffer {
  using value_type = T;
  constexpr int size() { return N; }  
  // T[N];
};


int main() {
  Buffer<int, 42> buf;

  assert(buf.size() == 42);
}