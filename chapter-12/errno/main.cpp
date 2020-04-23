#include <cmath>
#include <iostream>

int main() {
  double res = sqrt(-1.0);
  if (errno == EDOM) {
    std::cout << "got EDOM\n";
  }

  std::cout << res << '\n';
}
