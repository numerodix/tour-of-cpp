#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <list>
#include <regex>
#include <string>
#include <vector>


void cpy(int (*dst)[10], int (*src)[10]) {
  for (int i=0; i != 10; ++i) {
    (*dst)[i] = (*src)[i];
  }
}


template<typename T, size_t N>
void arr_copy(T (&dst)[N], T (&src)[N]) {
  for (size_t i=0; i != N; ++i) {
    dst[i] = src[i];
  }
}


int main() {
  int src[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int dst1[10];
  int dst2[10];

  cpy(&dst1, &src);
  arr_copy<int, 10>(dst2, src);

  std::cout << "src: " << std::endl;
  for (int i=0; i != 10; ++i) {
    std::cout << src[i] << std::endl;
  }

  std::cout << "dst1: " << std::endl;
  for (int i=0; i != 10; ++i) {
    std::cout << dst1[i] << std::endl;
  }

  std::cout << "dst2: " << std::endl;
  for (int i=0; i != 10; ++i) {
    std::cout << dst2[i] << std::endl;
  }
}