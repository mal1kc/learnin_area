// h1 Developing your first program
// *https://www.learncpp.com/cpp-tutorial/developing-your-first-program/

#include <iostream>

int main()
{
    // h1 Multiply by 2:
    
    // h2 my solution

    int num{0};
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << "double that number is: " << num * 2 << "\n";
    

    // ! solutions from the website

    // h2 The not-good solution

    // worst version
    std::cout << "Enter an integer: ";

	int num{ };
	std::cin >> num;

	num = num * 2; // double num's value, then assign that value back to num

	std::cout << "Double that number is: " << num << '\n';
    /*
    *Why this is a bad solution:

    - Before the assignment statement, num contains the user’s input.
    After the assignment, it contains a different value. That’s confusing.
    
    - We overwrote the user’s input by assigning a new value to the input variable,
    so if we wanted to extend our program to do something else with that input value later (e.g. triple the user’s input), it’s already been lost.
    */

    // h2 The mostly-good solution

    // less-bad version

    std::cout << "Enter an integer: ";

	int num{ };
	std::cin >> num;

	int doublenum{ num * 2 }; // define a new variable and initialize it with num * 2
	std::cout << "Double that number is: " << doublenum << '\n'; // then print the value of that variable here
    /*
    The primary downside here is that we’re defining a new variable (which adds complexity) to store a value we only use once. We can do better.
    */
   // h2 The preferred solution
    // preffered version
    std::cout << "Enter an integer: ";

	int num{ };
	std::cin >> num;

	std::cout << "Double that number is: " <<  num * 2 << '\n'; // use an expression to multiply num * 2 at the point where we are going to print it

    // q:Modify the solution to the “best solution” program above so that it outputs like this (assuming user input 4):
    /*
    Enter an integer: 4
    Double 4 is: 8
    Triple 4 is: 12
    */

    int num{0};
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << "double " << num << " is: " << num * 2 << "\n";
    std::cout << "tirple " << num << " is: " << num * 3 << "\n";

    return 0;
}
