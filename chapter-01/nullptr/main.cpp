#include <iostream>

int count_x(char* p, char x) {
    if (p == nullptr) return 0;
    int count = 0;
    for (; *p != 0; ++p)
        if (*p == x)
            ++ count;
    return count;
}

int count_x2(char* p, char x) {
    int count = 0;
    while (*p) {
        if (*p == x)
            ++count;
        ++p;
    }
    return count;
}

int main()
{
    char name[] = "James";
    std::cout << name << std::endl;
    std::cout << count_x(name, 'a') << std::endl;
    std::cout << count_x2(name, 'a') << std::endl;
    return 0;
}