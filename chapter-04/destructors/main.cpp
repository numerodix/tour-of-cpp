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

    ~Vector() { delete[] elem; }

    double& operator[](int i) { return elem[i]; }
    int size() const { return sz; }
};


int main() {
  Vector v(3);

  v[0] = 2;
  assert(v[0] == 2);
}