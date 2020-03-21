#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <list>
#include <stdexcept>


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


class Container {
  public:
    virtual double& operator[](int) = 0;
    virtual int size() const = 0;
    virtual ~Container() {}
};


class VectorContainer : public Container {
  public:
    VectorContainer(int s) : v(s) {}
    ~VectorContainer() {}

    double& operator[](int i) { return v[i]; }
    int size() const { return v.size(); }

  private:
    Vector v;
};


class ListContainer : public Container {
  public:
    ListContainer() {}
    ListContainer(std::initializer_list<double> il): ld{il} {}
    ~ListContainer() {}

    double& operator[](int i);
    int size() const { return ld.size(); }

  private:
    std::list<double> ld;
};


double& ListContainer::operator[](int i) {
  for (auto& x: ld) {
    if (i == 0) return x;
    --i;
  }
  throw std::out_of_range{"ListContainer"};
}


void use(Container& cont) {
  std::cout << cont[0] << std::endl;
}


int main() {
  // Vector v{1};
  // assert(v[0] == 0);

  // VectorContainer c{3};
  // c[0] = 1;

  ListContainer c{3};
  c[0] = 1;

  use(c);

  assert(c[0] == 1);
}