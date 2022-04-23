// h1 Introduction to literals and operators
// *https://www.learncpp.com/cpp-tutorial/introduction-to-literals-and-operators/

#include <iostream>

void main()
{
    // h1 Literals
    std::cout << "Hello world!";
    int x{5};
    /*
    q:What are “Hello world!” and 5? They are literals ?
    ! A literal (also known as a literal constant) is a fixed value that has been inserted directly into the source code.

    Literals and variables both have a value (and a type).
    However, the value of a literal is fixed and can’t be changed (hence it being called a constant),
    whereas the value of a variable can be changed through initialization and assignment.
    */
    /*
    h1 Operators
    In mathematics, an operation is a mathematical calculation involving zero or more input values (called operands) that produces a new value (called an output value).
    The specific operation to be performed is denoted by a construct (typically a symbol or pair of symbols) called an operator.

    For example, as children we all learn that 2 + 3 equals 5. In this case, the literals 2 and 3 are the operands,
    and the symbol + is the operator that tells us to apply mathematical addition on the operands to produce the new value 5.


    *You are likely already quite familiar with standard arithmetic operators from common usage in mathematics,
    *including addition (+), subtraction (-), multiplication (*), and division (/). In C++, assignment (=) is an operator as well,
    *as are << (insertion) and >> (extraction). Some operators use more than one symbol, such as the equality operator (==),
    *which allows us to compare two values to see if they are equal. There are also a number of operators that are words (e.g. new, delete, and throw).

    The number of operands that an operator takes as input is called the operator’s arity
    (almost nobody knows what this word means, so don’t drop it in a conversation and expect anybody to have any idea what you’re talking about).
    ! Operators in C++ come in three different arities:

    !Unary operators act on one operand. An example of a unary operator is the - operator.
    *For example, given -5, operator- takes literal operand 5 and flips its sign to produce new output value -5.

    !Binary operators act on two operands (known as left and right). An example of a binary operator is the + operator.
    *For example, given 3 + 4, operator+ takes the left operand (3) and the right operand (4) and applies mathematical addition to produce new output value 7.
    *The insertion (<<) and extraction (>>) operators are binary operators, taking std::cout or std::cin on the left side, and the item to output or variable to input to on the right side.

    !Ternary operators act on three operands. There is only one of these in C++, which we’ll cover later.

    * note : that some operators have more than one meaning depending on how they are used.
        For example, operator- has two contexts. It can be used in unary form to invert a number’s sign,
        e.g. to convert 5 to -5, or vice versa, or it can be used in binary form to do subtraction (e.g. 4 - 3).
    */

    // h1 Chaining operators

    /*
    Operators can be chained together such that the output of one operator can be used as the input for another operator.
    For example, given the following: 2 * 3 + 4, the multiplication operator goes first,
    and converts left operand 2 and right operand 3 into new value 6 (which becomes the left operand for the plus operator).
    Next, the plus operator executes, and converts left operand 6 and right operand 4 into new value 10.
    */
    // q:For each of the following, indicate what output they produce:

    std::cout << 3 + 4; // 7

    std::cout << 3 + 4 - 5; // 2

    std::cout << 2 + 3 * 4; // 14
}