// H1 Uninitialized variables and undefined behavior
// *https://www.learncpp.com/cpp-tutorial/uninitialized-variables-and-undefined-behavior/

// *note:
// *Initialization = The object is given a known value at the point of definition.
// *Assignment = The object is given a known value beyond the point of definition.
// *Uninitialized = The object has not been given a known value yet.


// ! Using the values of uninitialized variables can lead to unexpected results. Consider the following short program:

/* 
In this case, the computer will assign some unused memory to x.
It will then send the value residing in that memory location to std::cout,
which will print the value (interpreted as an integer). But what value will it print?
The answer is “who knows!”, and the answer may (or may not) change every time you run the program.
When the author ran this program in Visual Studio, std::cout printed the value 7177728 one time,
and 5277592 the next. Feel free to compile and run the program yourself (your computer won’t explode).
*/

/* 
! commented for use other examples
- #include <iostream>

int main()
{
    // define an integer variable named x
    int x; // this variable is uninitialized because we haven't given it a value

    // print the value of x to the screen
    std::cout << x; // who knows what we'll get, because x is uninitialized

    return 0;
}

*/
/*
Most modern compilers will attempt to detect if a variable is being used without being given a value. If they are able to detect this,
they will generally issue a compile-time error. For example, compiling the above program on Visual Studio produced the following warning:

c:\VCprojects\test\test.cpp(11) : warning C4700: uninitialized local variable 'x' used
*/

// If your compiler won’t let you compile and run the above program for this reason,
// here is a possible solution to get around this issue:

#include <iostream>

void doNothing(int&) // Don't worry about what & is for now, we're just using it to trick the compiler into thinking variable x is used
{
}

int main()
{
    // define an integer variable named x
    int x; // this variable is uninitialized

    doNothing(x); // make the compiler think we're assigning a value to this variable

    // print the value of x to the screen (who knows what we'll get, because x is uninitialized)
    std::cout << x;

    return 0;
}
/*
! Using uninitialized variables is one of the most common mistakes that novice programmers make, and unfortunately,
! it can also be one of the most challenging to debug (because the program may run fine anyway
! if the uninitialized variable happened to get assigned to a spot of memory that had a reasonable value in it, like 0).
*/

// ! This is the primary reason for the “always initialize your variables” best practice.

// h1 Undefined behavior
/*
Using the value from an uninitialized variable is our first example of undefined behavior.
Undefined behavior (often abbreviated UB) is the result of executing code whose behavior is not well defined by the C++ language.
In this case, the C++ language doesn’t have any rules determining what happens
if you use the value of a variable that has not been given a known value.
Consequently, if you actually do this, undefined behavior will result.


Code implementing undefined behavior may exhibit any of the following symptoms:

    Your program produces different results every time it is run.
    Your program consistently produces the same incorrect result.
    Your program behaves inconsistently (sometimes produces the correct result, sometimes not).
    Your program seems like its working but produces incorrect results later in the program.
    Your program crashes, either immediately or later.
    Your program works on some compilers but not others.
    Your program works until you change some other seemingly unrelated code.

Or, your code may actually produce the correct behavior anyway.
The nature of undefined behavior is that you never quite know what you’re going to get,
 whether you’ll get it every time, and whether that behavior will change when you make other changes.

C++ contains many cases that can result in undefined behavior if you’re not careful.
We’ll point these out in future lessons whenever we encounter them. Take note of where these cases are and make sure you avoid them.
*/

// Q:What is an uninitialized variable? Why should you avoid using them?
/*
!An uninitialized variable is a variable that has not been given a value by the program (generally through initialization or assignment).
!Using the value stored in an uninitialized variable will result in undefined behavior.
*/
// Q:What is undefined behavior, and what can happen if you do something that exhibits undefined behavior?
/*
!Undefined behavior is the result of executing code whose behavior is not well defined by the language.
!The result can be almost anything, including something that behaves correctly.
*/
