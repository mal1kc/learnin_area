#include <iostream> // for std::cout and std::cin

int main()
{
    std::cout << "Enter a number: "; // ask user for a number
    int x{};                         // define variable x to hold user input
    std::cin >> x;                   // get number from keyboard and store it in variable x
    std::cout << "You entered " << x << '\n';
    return 0;

    //* first input was A letter, such as 'h'
    // output was:'You entered 0'
    //* second input was a number with a fractional component, such as '5.5'
    // output was:'You entered 5'
    //* third input was a negative integer, such as '-3'
    // output was:'You entered -3'
    //* fourth input was a word, such as 'Hello'
    // output was:'You entered 0'
    //* fifth input was a really big number (at least 3 billion) such as '3123456789'
    // output was:'You entered 2147483647'
}
