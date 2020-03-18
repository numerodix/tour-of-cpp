#include <cassert>


class complex {
    double re, im;

  public:
    complex(double r, double i): re{r}, im{i} {}

    double real() const { return re; }
    double imag() const { return im; }

    complex& operator+=(complex z) { re+=z.re; im+=z.im; return *this; }
};

complex operator+(complex a, complex b) { return a+=b; }
complex operator-(complex a) { return {-a.real(), -a.imag()}; }



int main() {
    complex c1{2, 3};
    complex c2{5, 7};

    c1 += c2;
    assert(c1.real() == 7);
    assert(c1.imag() == 10);

    complex c3 = c1 + c2;
    assert(c3.real() == 12);
    assert(c3.imag() == 17);

    complex c4 = -c1;
    assert(c4.real() == -7);
    assert(c4.imag() == -10);
}