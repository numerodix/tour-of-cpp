#include <iostream>


union Value {
    char* s;
    int i;
};

int main() {
    Value val;

    char name[] = "hi";
    val.s = name;
    std::cout << val.s << std::endl;

    val.i = 42;
    std::cout << val.i << std::endl;
}