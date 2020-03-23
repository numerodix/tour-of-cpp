#include <cassert>


class Vector {
  private:
    double* elem;
    int sz;

  public:
    Vector(int s): elem{new double[s]}, sz{s} {
      for (int i=0; i!=s; i++)
        elem[i] = 0;
    }

    // copy ctor
    Vector(const Vector& other) : elem{new double[other.sz]}, sz{other.sz} {
      for (int i=0; i!=other.sz; ++i) {
        elem[i] = other.elem[i];
      }
    }

    // copy assignment
    Vector& operator=(const Vector& other) {
      double* p = new double[other.sz];
      for (int i=0; i!=other.sz; ++i) {
        p[i] = other.elem[i];
      }
      delete[] elem;
      elem = p;
      sz = other.sz;
      return *this;
    }

    // move constructor
    Vector(Vector&& other) : elem{other.elem}, sz{other.sz} {
      other.elem = nullptr;
      other.sz = 0;
    }

    // move assignment
    Vector& operator=(Vector&& other) {
      delete[] elem;
      elem = other.elem;
      sz = other.sz;

      other.elem = nullptr;
      other.sz = 0;

      return *this;
    }

    ~Vector() { delete[] elem; }

    double& operator[](int i) { return elem[i]; }
    int size() const { return sz; }
};


int main() {
  Vector v(3);

  v[0] = 2;
  assert(v[0] == 2);

  Vector v2{v};
  assert(v2[0] == v[0]);

  Vector v3{0};
  v3 = v;
  assert(v3[0] == v[0]);

  Vector v4{Vector{1}};
  assert(v4[0] == 0);

  Vector v5 = Vector{1};
  assert(v5[0] == 0);
}