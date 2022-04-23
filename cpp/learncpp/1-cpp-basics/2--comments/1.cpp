#include <iostream>

int main(int argc, char const *argv[])
{
    int sight;
    // Replace this line with the snippet of code you'd like to compile

    /* This is a multi-line comment.
   This line will be ignored.
   So will this one. */
    /* This is a multi-line comment.
     * the matching asterisks to the left
     * can make this easier to read
     */
    std::cout << "Hello world!";                   // Everything from here to the end of the line is ignored
    std::cout << "Hello world!\n";                 // std::cout lives in the iostream library
    std::cout << "It is very nice to meet you!\n"; // these comments make the code hard to read
    std::cout << "Yeah!\n";                        // especially when lines are different lengths

    std::cout << "Hello world!\n";                 // std::cout lives in the iostream library
    std::cout << "It is very nice to meet you!\n"; // this is much easier to read
    std::cout << "Yeah!\n";                        // don't you think so?

    // To generate a random item, we're going to do the following:
    // 1) Put all of the items of the desired rarity on a list
    // 2) Calculate a probability for each item based on level and weight factor
    // 3) Choose a random number
    // 4) Figure out which item that random number corresponds to
    // 5) Return the appropriate item

    // BAD COMMENT
    // Set sight range to 0
    sight = 0;

    // GOOD COMMENT
    // The player just drank a potion of blindness and can not see anything
    sight = 0;

    int cost = 0, quantity = 0, storePrice = 0;

    // BAD COMMENT
    // Calculate the cost of the items
    cost = quantity * 2 * storePrice;

    // GOOD COMMENT
    // We need to multiply quantity by 2 here because they are bought in pairs
    cost = quantity * 2 * storePrice;

    return 0;
}
