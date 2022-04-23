// bitwise_opeations
#pragma region Includes
#include <iostream>
#pragma endregion Includes

int main(int argc, char const *argv[])
{
    int a = 5;
    // int b = a<<1;
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
    return 0;
}
