// h1 Whitespace and basic formatting
// *https://www.learncpp.com/cpp-tutorial/whitespace-and-basic-formatting/
#include <iostream>

void main(){
/*
Whitespace is a term that refers to characters that are used for formatting purposes.
In C++, this refers primarily to spaces, tabs, and newlines.
The C++ compiler generally ignores whitespace, with a few minor exceptions (when processing text literals).
For this reason, we say that C++ is a whitespace-independent language.

Consequently, the following statements all do the exact same thing:
*/


std::cout << "Hello world!"; // 1

std::cout               <<            "Hello world!"; // 2

		std::cout << 		"Hello world!"; // 3

std::cout
	<< "Hello world!"; // 4

// Even the last statement that is split over two lines compiles just fine.

}

// The following functions all do the same thing:

int add(int x, int y) { return x + y; } //1

int add(int x, int y) {
    return x + y; } // 2

int add(int x, int y)
{    return x + y; } // 3

int add(int x, int y)
{
    return x + y;
}// 4

//! One exception where the C++ compiler does pay attention to whitespace is inside quoted text, such as "Hello world!".

/*
! "Hello world!" is different than: "Hello     world!" and each prints out exactly as you’d expect.
*/
// Newlines are not allowed in quoted text:

std::cout << "Hello
     world!"; // Not allowed!

// * Quoted text separated by nothing but whitespace (spaces, tabs, or newlines) will be concatenated:
std::cout << "Hello "
     "world!"; // prints "Hello world!"

/*
Another exception where the C++ compiler pays attention to whitespace is with // comments. 
Single-line comments only last to the end of the line. Thus doing something like this will get you in trouble:
*/
std::cout << "Hello world!"; // Here is a single-line comment
this is not part of the comment

// h1 Basic formatting

/*
Unlike some other languages, C++ does not enforce any kind of formatting restrictions on the programmer (remember, trust the programmer!)
Many different methods of formatting C++ programs have been developed throughout the years,and you will find disagreement on which ones are best.
Our basic rule of thumb is that the best styles are the ones that produce the most readable code, and provide the most consistency.
*/

// SUMMARY examples

// Harder to read:
cost = 57;
pricePerItem = 24;
value = 5;
numberOfItems = 17;
// Easier to read:
cost          = 57;
pricePerItem  = 24;
value         = 5;
numberOfItems = 17;
// Harder to read:
std::cout << "Hello world!\n"; // cout lives in the iostream library
std::cout << "It is very nice to meet you!\n"; // these comments make the code hard to read
std::cout << "Yeah!\n"; // especially when lines are different lengths
// Easier to read:
std::cout << "Hello world!\n";                  // cout lives in the iostream library
std::cout << "It is very nice to meet you!\n";  // these comments are easier to read
std::cout << "Yeah!\n";                         // especially when all lined up

// Harder to read:

// cout lives in the iostream library
std::cout << "Hello world!\n";
// these comments make the code hard to read
std::cout << "It is very nice to meet you!\n";
// especially when all bunched together
std::cout << "Yeah!\n";

// Easier to read:

// cout lives in the iostream library
std::cout << "Hello world!\n";

// these comments are easier to read
std::cout << "It is very nice to meet you!\n";

// when separated by whitespace
std::cout << "Yeah!\n";
