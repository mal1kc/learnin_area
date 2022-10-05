// h1 Chapter 1 summary and quiz
// *https://www.learncpp.com/cpp-tutorial/chapter-1-summary-and-quiz/

// Read Readme.md

// q:What is the difference between initialization and assignment?

/*Initialization provides a variable with an initial value (at the point of creation).
Assignment gives a variable a new value after the variable has already been defined.*/

// q:When does undefined behavior occur? What are the consequences of undefined behavior?
/*Undefined behavior occurs when the programmer does something that is ill-specified by the C++ language.
The consequences could be almost anything, from crashing to producing the wrong answer to working correctly anyway.*/

/*
q:  Write a program that asks the user to enter a number, and then enter a second number.
q:      The program should tell the user what the result of adding and subtracting the two numbers is.
q:          The output of the program should match the following (assuming inputs of 6 and 4):
*/

/*
Enter an integer: 6
Enter another integer: 4
6 + 4 is 10.
6 - 4 is 2.
*/

#include <iostream>

int main()
{
    std::cout << "Enter an integer : ";
    int num1{0};
    std::cin >> num1;
    std::cout << "Enter another integer : ";
    int num2{0};
    std::cin >> num2;
    std::cout << num1 << " + " << num2 << " is " << num1 + num2 << ".\n";
    std::cout << num1 << " - " << num2 << " is " << num1 - num2 << ".\n";
    return 0;
}