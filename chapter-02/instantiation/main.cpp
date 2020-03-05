#include <iostream>

struct Vector {
    public:
        Vector(int size) : sz{size} {};
        int size() { return sz; }
    private:
        int sz;
};

int main() {
    Vector v(6);
    std::cout << v.size() << std::endl;

    Vector v2{6};
    std::cout << v2.size() << std::endl;

    return 0;
}