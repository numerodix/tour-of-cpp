#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>


template<typename T>
void show(T& t) {
  std::cout << t << std::endl; 
}


void traverse() {}   // the base case once recursion has bottomed out

template<typename T, typename... Tail>
void traverse(T head, Tail... tail) {
    show(head);
    traverse(tail...);   // recurse
}


int main() {
  traverse(4, 5, 2.3, "oops");
}