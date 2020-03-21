#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>


const int X = 1;

const int& get() {
  return X;
}


int main() {
  int x = get();
  x = 2;

  assert(X == 1);
  assert(x == 1);
}