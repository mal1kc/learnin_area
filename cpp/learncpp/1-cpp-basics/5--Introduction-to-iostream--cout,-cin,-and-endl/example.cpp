// H1 The input/output library
//* https://www.learncpp.com/cpp-tutorial/introduction-to-iostream-cout-cin-and-endl
#include <iostream>

// rest of code that uses iostream functionality here

int main()
{
    // H1 std::cout
    std::cout << "Hello world!"; // print Hello world! to console
    std::cout << 4;              // print 4 to console

    int x{5};       // define integer variable x, initialized with value 5
    std::cout << x; // print value of x (5) to console

    std::cout << "Hello"
              << " world!"; // print Hello world! to console

    int y{5};
    std::cout << "y is equal to: " << y; // *This line prints:y is equal to: 5

    // H1 std::endl
    std::cout << "Hi!" << std::endl; // std::endl will cause the cursor to move to the next line of the console
    std::cout << "My name is Alex.";

    // h1 std::endl vs ‘\n’
    /*
    Using std::endl can be a bit inefficient, as it actually does two jobs:
    it moves the cursor to the next line, and it “flushes” the output (makes sure that it shows up on the screen immediately).
    When writing text to the console using std::cout, std::cout often flushes output anyway
    (and if it doesn’t, it usually doesn’t matter), so having std::endl perform a flush is rarely important.
    *Because of this, use of the ‘\n’ character is typically preferred instead.
    *The ‘\n’ character moves the cursor to the next line, but doesn’t request a flush,
    *so it will perform better in cases where a flush would not otherwise happen.
    The ‘\n’ character also tends to be easier to read since it’s both shorter and can be embedded into existing text.
    */
    int z{5};

    std::cout << "z is equal to: " << z << '\n'; // Using '\n' standalone
    std::cout << "And that's all, folks!\n";     // Using '\n' embedded into a double-quoted piece of text (note: no single quotes when used this way)

    // H1 std::cin

    std::cout << "Enter a number: "; // ask user for a number

    int d{};       // define variable d to hold user input (and zero-initialize it)
    std::cin >> d; // get number from keyboard and store it in variable d
    std::cout << "You entered " << d << '\n';

    std::cout << "Enter two numbers separated by a space: ";

    int e{ }; // define variable e to hold user input (and zero-initialize it)
    int f{ }; // define variable f to hold user input (and zero-initialize it)
    std::cin >> e >> f; // get two numbers and store in variable e and f respectively

    std::cout << "You entered " << e << " and " << f << '\n';

    return 0;
}