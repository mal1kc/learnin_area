// h1 Introduction to expressions
// *https://www.learncpp.com/cpp-tutorial/introduction-to-expressions/


#include <iostream>
// h1 Expressions

// five() is a function that returns the value 5
int five()
{
    return 5;
}
int main()
{
    int a{ 2 };             // initialize variable a with literal value 2
    int b{ 2 + 3 };         // initialize variable b with computed value 5
    int c{ (2 * 3) + 4 };   // initialize variable c with computed value 10
    int d{ b };             // initialize variable d with variable value 5
    int e{ five() };        // initialize variable e with function return value 5

    /*
    Each of these statements defines a new variable and initializes it with a value.
    Note that the initializers shown above make use of a variety of different constructs:
        literals, variables, operators, and function calls. Somehow,
        C++ is converting all of these different things into a single value that can then be used as the initialization value for the variable.

    What do all of these have in common? They make use of an expression.

    An expression is a combination of literals, variables, operators, and function calls that can be executed to produce a singular value.
    The process of executing an expression is called evaluation, and the single value produced is called the result of the expression.

    When an expression is evaluated, each of the terms inside the expression are evaluated, until a single value remains.
    Here are some examples of different kinds of expressions, with comments indicating how they evaluate:
    */

    2               // 2 is a literal that evaluates to value 2
    "Hello world!"  // "Hello world!" is a literal that evaluates to text "Hello world!"
    x               // x is a variable that evaluates to the value of x
    2 + 3           // operator+ combines values 2 and 3 to produce value 5
    x = 2 + 3       // 2 + 3 evaluates to value 5, which is then assigned to variable x
    std::cout << x  // x evaluates to the value of x, which is then printed to the console
    five()          // evaluates to the return value of function five()

    /*
    As you can see, literals evaluate to their own values. Variables evaluate to the value of the variable.
    We haven’t covered function calls yet, but in the context of an expression, function calls evaluate to whatever value the function returns.
    And operators (such as operator+) let us combine multiple values together to produce a new value.

    Note that expressions do not end in a semicolon, and cannot be compiled by themselves.
    For example, if you were to try compiling the expression x = 5,your compiler would complain (probably about a missing semicolon).
    Rather, expressions are always evaluated as part of statements.

    For example, take this statement:
    */
    int x{ 2 + 3 }; // 2 + 3 is an expression that has no semicolon -- the semicolon is at the end of the statement containing the expression

    //*If you were to break this statement down into its syntax, it would look like this:
    type identifier { expression };
    /*
    Type could be any valid type (we chose int). Identifier could be any valid name (we chose x).
    And expression could be any valid expression (we chose 2 + 3, which uses 2 literals and an operator).
    */
   // h1 Expression statements
    /*Certain expressions (like x = 5) are useful by themselves. However, we mentioned above that expressions must be part of a statement,
    so how can we use these expressions by themselves?

    Fortunately, we can convert any expression into an equivalent statement (called an expression statement).
    An expression statement is a statement that consists of an expression followed by a semicolon. When the statement is executed, the expression will be evaluated (and the result of the expression will be discarded).

    Thus, we can take any expression (such as x = 5), and turn it into an expression statement (such as x = 5;) that will compile.

    Note that we can make expression statements that compile but are meaningless/useless (e.g. 2 * 3;).
    This expression evaluates to 6, and then the value 6 is discarded.*/

    /*
    q:What is the difference between a statement and an expression?
        Statements are used when we want the program to perform an action.
        Expressions are used when we want the program to calculate a value.
    */
    
    // q:Indicate whether each of the following lines are statements that do not contain expressions, statements that contain expressions, or are expression statements.
    
    int x; // Statement does not contain an expression (this is just a variable definition)
    int x = 5; /* Statement contains an expression 
    (The right hand side of the equals side is an expression containing a single value, but the rest of the statement isn’t an expression)*/
    x = 5; // Expression statement (the entire statement is an expression, terminated by a semicolon)
    std::cout << x; // Hint: operator<< is a binary operator. 
    // * If operator<< is a binary operator, then std::cout must be the left-hand operand, and x must be the right-hand operand.
    // *Since that’s the entire statement, this must be an expression statement.
    
    // q:Determine what values the following program outputs. Do not compile this program. Just work through it line by line in your head.

    std::cout << 2 + 3 << '\n'; // expressions of 2+3 evaluate to 5 // prints  5\n

	int x{ 6 };
	int y{ x - 2 };
	std::cout << y << '\n'; // prints 4\n

	int z{ };
	z = x;
	std::cout << z - x << '\n'; // prints 0\n

    return 0;
}
