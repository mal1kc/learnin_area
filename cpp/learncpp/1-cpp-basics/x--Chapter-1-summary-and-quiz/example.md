# Chapter 1 summary and quiz

<https://www.learncpp.com/cpp-tutorial/chapter-1-summary-and-quiz/>

## Chapter Review

A <strong>statement</strong> is a type of instruction that causes the program to perform some action. Statements are often terminated by a semicolon.

A <strong>function</strong> is a collection of statements that execute sequentially. Every C++ program must include a special function named main. When you run your program, execution starts at the top of the main function.

The rules that govern how elements of the C++ language are constructed is called a <strong>syntax</strong>. A <strong>syntax error</strong> occurs when you violate the grammatical rules of the language.

<strong>Comments</strong> allow the programmer to leave notes in the code. C++ supports two types of comments. Line comments start with a `//` and run to the end of the line. Block comments start with a `/*` and go to the paired `*/` symbol. Don’t nest comments.

You can use comments to temporarily disable lines or sections of code. This is called commenting out your code.

<strong>Data</strong> is any sequence of symbols that can be interpreted to mean something. A single piece of data, stored somewhere in memory is called a <strong>value</strong>.

A variable is a named piece of memory that we can use to store values. A variable’s name is called an <strong>identifier</strong>. In order to create a variable, we use a statement called a <strong>definition statement</strong>. When the program is run, each defined variable is <strong>instantiated</strong>, which means it is assigned a memory address.

A <strong>data type</strong> tells the compiler how to interpret a piece of data into a meaningful value. An <strong>integer</strong> is a number that can be written without a fractional component, such as 4, 27, 0, -2, or -12.

<strong>Copy assignment</strong> (via operator=) can be used to assign an already created variable a value.

<strong>Initialization</strong> can be used to give a variable a value at the point of creation. C++ supports 3 types of initialization: copy initialization, direct initialization, and uniform initialization (also called list initialization or brace initialization).

You should prefer uniform initialization over the other initialization forms, and prefer initialization over assignment.

Although you can define multiple variables in a single statement, it’s better to define and initialize each variable on its own line, in a separate statement.

<strong>std::cout</strong> and operator<< allow us to output an expression to the console as text. <strong>std::endl</strong> outputs a new line character, forcing the console cursor to move to the next line. <strong>std::cin</strong> and operator>> allow us to get a value from the keyboard.

A variable that has not been given a value is called an <strong>uninitialized variable</strong>. Trying to get the value of an uninitialized variable will result in <strong>undefined behavior</strong>, which can manifest in any number of ways.

C++ reserves a set of names called <strong>keywords</strong>. These have special meaning within the language and may not be used as variable names.

A <strong>literal constant</strong> is a fixed value inserted directly into the source code. Examples are 5 and “Hello world!”.

An <strong>operation</strong> is a mathematical calculation involving zero or more input values, called <strong>operands</strong>. The specific operation to be performed is denoted by the provided <strong>operator</strong>. The result of an operation produces an output value.

<strong>Unary</strong> operators take one operand. <strong>Binary</strong> operators take two operands, often called left and right. <strong>Ternary</strong> operators take three operands.

An <strong>expression</strong> is a combination of literals, variables, operators, and function calls that are evaluated to produce a single output value. The calculation of this output value is called <strong>evaluation</strong>. The value produced is the <strong>result</strong> of the expression.

An <strong>expression</strong> statement is an expression that has been turned into a statement by placing a semicolon at the end of the expression.

Programming is hard, and your programs will rarely come out perfect (or close to it) the first time. Get your programs working first, then refine them into something great.
