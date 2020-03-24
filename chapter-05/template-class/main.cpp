#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <list>
#include <stdexcept>


template<typename T>
class Vector {
  private:
    T* elem;
    int sz;

  public:
    explicit Vector(int s): elem{new T[s]}, sz{s} {}

    ~Vector() { 
      std::cout << "I had " << sz << " elements" << std::endl;
      delete[] elem;
    }

    T& operator[](int i) { return elem[i]; }
    int size() const;
};


template<typename T>
int Vector<T>::size() const {
  return sz;
}


// To support range for loop
template<typename T>
T* begin(Vector<T>& x) {
  return x.size() ? &x[0] : nullptr;
}


// To support range for loop
template<typename T>
T* end(Vector<T>& x) {
  return begin(x) + x.size();
}


int main() {
  Vector<int> vec{1};
  vec[0] = 7;

  assert(vec[0] == 7);
  assert(vec.size() == 1);

  Vector<std::list<int>> ints{2};
  ints[0] = std::list<int>{1, 2, 3};

  assert(ints[0].size() == 3);

  for (auto& item: vec) {
    std::cout << item << std::endl;
  }
}