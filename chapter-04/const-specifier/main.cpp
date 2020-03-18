#include <cassert>


class complex {
    double re, im;

  public:
    complex(double r, double i): re{r}, im{i} {}

    double imag() const {
        // im = im * 2;   // does not compile!
        return im;
    }
};


int main() {
    complex c(2, 3);

    assert(c.imag() == 3.0);
}