int main() {
    static_assert(sizeof(double) == 8, "double is not 8 bytes");

    constexpr int result = 8 / 3;
    static_assert(result == 2, "I got the wrong result!");
}