#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>


class Vector {
  private:
    double* elem;
    int sz;

  public:
    Vector(int s): elem{new double[s]}, sz{s} {
      for (int i=0; i!=s; i++)
        elem[i] = 0;
    }

    Vector(std::initializer_list<double> lst)
      :elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())} {
      std::copy(lst.begin(), lst.end(), elem);
    }

    ~Vector() { 
      std::cout << "I had " << sz << " elements" << std::endl;
      delete[] elem;
    }

    double& operator[](int i) { return elem[i]; }
    int size() const { return sz; }
};


int main() {
  Vector v(2);

  v[0] = 2;
  assert(v[0] == 2);

  Vector v2{1, 2, 3};
  assert(v2[0] == 1);
  assert(v2[2] == 3);
}