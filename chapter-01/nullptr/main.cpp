#include <iostream>

// The actual behavior I see is a segfault once p becomes 0x7ffffffff000
int count_x(char* p, char x) {
    if (p == nullptr) return 0;
    int count = 0;
    for (; p != nullptr; ++p)  // why would p ever become equal to nullptr tho??
        if (*p == x)
            ++ count;
    return count;
}

int count_x2(char* p, char x) {
    int count = 0;
    while (p) {                 // same question here!
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
    return 0;
}