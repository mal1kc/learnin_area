#include <iostream>

void example()
{
    int x;    // define an integer variable named x
    int y, z; // define two integer variables, named y and z

    int width; // define an integer variable named width
    width = 5; // copy assignment of value 5 into variable width

    // variable width now has value 5

    int a;     // no initializer
    int b = 5; // initializer after equals sign
    int c(6);  // initializer in parenthesis
    int d{7};  // initializer in braces

    int width = 5; // copy initialization of value 5 into variable width

    int width(5); // direct initialization of value 5 into variable width

    // IMPORTANT:
    /*
    For simple data types (like int), copy and direct initialization are essentially the same.
    For more complicated types, direct initialization tends to be more efficient than copy initialization.
    */
    // IMPORTANT:

    int width{5};     // direct brace initialization of value 5 into variable width (preferred)
    int height = {6}; // copy brace initialization of value 6 into variable height
    int depth{};      // value initialization (see next section)

    // IMPORTANT:
    /*
    Unfortunately, direct initialization can’t be used for all types of initialization
    (such as initializing an object with a list of data).
    To provide a more consistent initialization mechanism, there’s brace initialization
    (also called uniform initialization or list initialization) that uses curly braces.

    Direct and copy brace initialization function almost identically, but the direct form is generally preferred.
    Brace initialization has the added benefit of disallowing “narrowing” conversions.
    This means that if you try to use brace initialization to initialize a variable with a value it can not safely hold,
    the compiler will throw a warning or an error. For example:
    */
    int width{4.5};
    // error: not all double values fit into an int
    /*
    *In the above snippet, we’re trying to assign a number (4.5) that has a fractional part (the .5 part) to an integer variable
    (which can only hold numbers without fractional parts).
    Copy and direct initialization would drop the fractional part, resulting in initialization of value 4 into variable width.
    However, with brace initialization, this will cause the compiler to issue an error (which is generally a good thing, because losing data is rarely desired)
    Conversions that can be done without potential data loss are allowed.
    */
    // IMPORTANT:

    // H1 Value initialization and zero initialization

    /*
    When a variable is initialized with empty braces, value initialization takes place.
    In most cases, value initialization will initialize the variable to zero (or empty, if that’s more appropriate for a given type).
    In such cases where zeroing occurs, this is called zero initialization.
    */
    int width{}; // zero initialization to value 0

    // Q:When should I initialize with { 0 } vs {}?

    //  Use an explicit initialization value if you’re actually using that value.
    int x{0};       // explicit initialization to value 0
    std::cout << x; // we're using that zero value
    // Use value initialization if the value is temporary and will be replaced.
    int x{};       // value initialization
    std::cin >> x; // we're immediately replacing that value

    // H1 Initializing multiple variables

    int a, b;

    int a = 5, b = 6; // copy initialization
    int c(7), d(8);   // direct initialization
    int e{9}, f{10};  // brace initialization (preferred)

    int a, b = 5; // wrong (a is not initialized!)

    int a = 5, b = 5; // correct

    // The best way to remember that this is wrong is to consider the case of direct initialization or brace initialization:
    int a, b(5);
    int c, d{5};
    // This makes it seem a little more clear that the value 5 is only being used to initialize variable b or d, not a or c.

    // Q:What is the difference between initialization and assignment?
    //  *Initialization gives a variable an initial value at the point when it is created.
    //  *Assignment gives a variable a value at some point after the variable is created.
}

int main()
{
    int width;
    width = 5; // copy assignment of value 5 into variable width

    // variable width now has value 5

    width = 7; // change value stored in variable width to 7

    // variable width now has value 7

    return 0;
}
