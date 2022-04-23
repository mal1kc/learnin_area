// bitwise_opeations
#pragma region Includes
#include <iostream>
#include <bitset>
#pragma endregion Includes

int main(int argc, char const *argv[])
{
    int a = 5;
    std::cout << "a = " << a << "\n";
    std::cout << "a << 1 = " << (a << 1) << "\n";
    std::cout << "a << 4 = " << (a << 4) << "\n";
    std::cout << "(a << 1) << 4 = " << ((a << 1) << 4) << "\n";
    std::cout << "(a << 1) >> 1 = " << ((a << 1) >> 1) << "\n";
    std::cout << "--- minimal version ---"
              << "\n";
    std::cout << "y << x = ( +y2^x )"
              << "\n";
    std::cout << "y >> x = ( -y2^x )"
              << "\n";

    a = 0b101;        // binary 101 = 5
    int b = 0b010110; // binary 010110 = 22
    b <<= 4; // binary 010110 << 4 = 0101100000 = 352
    int c = a | b;
    std::cout << std::bitset<9>(c) << "\n";
    return 0;
}
