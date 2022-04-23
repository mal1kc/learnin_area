// h1 Keywords and naming identifiers
// *https://www.learncpp.com/cpp-tutorial/keywords-and-naming-identifiers/

// h1 Keywords:
/*
C++ reserves a set of 92 words (as of C++20) for its own use. These words are called keywords (or reserved words),
and each of these keywords has a special meaning within the C++ language.
Here is a list of all the C++ keywords (through C++20):

    alignas
    alignof
    and
    and_eq
    asm
    auto
    bitand
    bitor
    bool
    break
    case
    catch
    char
    char8_t (since C++20)
    char16_t
    char32_t
    class
    compl
    concept (since C++20)
    const
    consteval (since C++20)
    constexpr
    constinit (since C++20)
    const_cast
    continue
    co_await (since C++20)
    co_return (since C++20)
    co_yield (since C++20)
    decltype
    default
    delete
    do
    double
    dynamic_cast
    else
    enum
    explicit
    export
    extern
    false
    float
    for
    friend
    goto
    if
    inline
    int
    long
    mutable
    namespace
    new
    noexcept
    not
    not_eq
    nullptr
    operator
    or
    or_eq
    private
    protected
    public
    register
    reinterpret_cast
    requires (since C++20)
    return
    short
    signed
    sizeof
    static
    static_assert
    static_cast
    struct
    switch
    template
    this
    thread_local
    throw
    true
    try
    typedef
    typeid
    typename
    union
    unsigned
    using
    virtual
    void
    volatile
    wchar_t
    while
    xor
    xor_eq
*/

//! C++ also defines special identifiers: override, final, import, and module.
//! These have a specific meaning when used in certain contexts but are not reserved.

// h1 Identifier naming rules
/*
As a reminder, the name of a variable (or function, type, or other kind of item) is called an identifier.
C++ gives you a lot of flexibility to name identifiers as you wish.
However, there are a few rules that must be followed when naming identifiers:

! The identifier can not be a keyword. Keywords are reserved.
! The identifier can only be composed of letters (lower or upper case), numbers,and the underscore character. That means the name can not contain symbols (except the underscore) nor whitespace (spaces or tabs).
! The identifier must begin with a letter (lower or upper case) or an underscore. It can not start with a number.
! C++ is case sensitive, and thus distinguishes between lower and upper case letters. nvalue is different than nValue is different than NVALUE.
*/

// h1 Identifier naming best practices

int value; // correct

int Value; // incorrect (should start with lower case letter)
int VALUE; // incorrect (should start with lower case letter)
int VaLuE; // incorrect (see your psychiatrist) ;)

/*
!Most often, function names are also started with a lowercase letter (though there’s some disagreement on this point).
We’ll follow this convention, since function main (which all programs must have) starts with a lowercase letter,
as do all of the functions in the C++ standard library.
*/

/*
!If the variable or function name is multi-word, there are two common conventions: words separated by underscores,
called snake_case, or intercapped (sometimes called camelCase, since the capital letters stick up like the humps on a camel).
*/

int my_variable_name;   // correct (separated by underscores/snake_case)
int my_function_name(); // correct (separated by underscores/snake_case)

int myVariableName;   // correct (intercapped/CamelCase)
int myFunctionName(); // correct (intercapped/CamelCase)

//! int my variable name; // invalid (whitespace not allowed)
//! int my function name(); // invalid (whitespace not allowed)

int MyVariableName;   // valid but incorrect (should start with lower case letter)
int MyFunctionName(); // valid but incorrect (should start with lower case letter)

/*
we will typically use the intercapped approach because it’s easier to read (it’s easy to mistake an underscore for a space in dense blocks of code).
But it’s common to see either -- the C++ standard library uses the underscore method for both variables and functions.
Sometimes you’ll see a mix of the two: underscores used for variables and intercaps used for functions.
*/

// h1 list of identifier exmples
/*
*  int ccount           ||    Bad       ||     What does the c before “count” stand for?
*  int customerCount    ||    Good      ||     Clear what we’re counting
*  int i                ||    Either    ||     Okay if use is trivial, bad otherwise
*  int index            ||    Either    ||     Okay if obvious what we’re indexing
*  int totalScore       ||    Either    ||     Okay if there’s only one thing being scored, otherwise too ambiguous
*  int _count           ||    Bad       ||     Do not start names with underscore
*  int count            ||    Either    ||     Okay if obvious what we’re counting
*  int data             ||    Bad       ||     What kind of data?
*  int time             ||    Bad       ||     Is this in seconds, minutes, or hours?
*  int minutesElapsed   ||    Good      ||     Descriptive
*  int value1, value2   ||    Either    ||     Can be hard to differentiate between the two
*  int numApples        ||    Good      ||     Descriptive
*  int monstersKilled   ||    Good      ||     Descriptive
*  int x, y             ||    Either    ||     Okay if use is trivial, bad otherwise
*/

/* 
Q:Based on how you should name a variable, indicate whether each variable name is correct (follows convention),
 incorrect (does not follow convention), or invalid (will not compile), and why.
*/
int sum {}; // assume it’s obvious what we’re summing // * corect

int _apples {}; // * incorrect (should not start with underscore)

int VALUE {}; // * incorrect (should start with lower case letter)

int my variable name {}; // * invalid (whitespace not allowed)

int TotalCustomers {}; // * incorrect (variable names should start with a lower case letter.)

int void {}; // * invalid (should not be c++ keyword)

int numFruits {}; // * correct

int 3some {}; // * invalid (should not start with a number)

int meters_of_pipe {}; // * correct