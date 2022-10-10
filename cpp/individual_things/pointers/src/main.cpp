#include "log.h"
#include <iostream>
#include <string.h>

// NOTE pointers are integer numbers that stores memory adresses of other type
// of data types

void example_1() {
  int var = 8;
  // void *ptr = nullptr; // null pointer (pointer that holds nothing)
  void *ptr = &var; // pointer that holds var's memory adress

  std::cout << "ptr :" << ptr << "\n";
}

void example_2() {
  int var = 9;
  // we told the compiler that pointer points memory addres of
  // int type of data
  int *ptr = &var;

  std::cout << "pointer : " << ptr << "\n"
            << "data pointed by pointer : " << *ptr
            << "\n"; // accesing data pointed by pointer
  *ptr = 12;         // change variable that pointed by pointer
  std::cout << "after change :"
            << "\n\t"
               "pointer : "
            << ptr << "\n"
            << "\t"
            << "data pointed by pointer : " << *ptr
            << "\n"; // accesing data pointed by pointer
}

void example_3() {
  char *buffer = new char[8]; // allocate 8 bytes of memory
  // 4036990 is char code for "~" character
  memset(buffer, 4036990, sizeof(*buffer)); // fills 8 bytes with 0's
  char **ptr = &buffer; // thats double pointer (pointer that points pointer)

  // int var = 93;
  // int *buffer = &var;

  // int **ptr = &buffer; // thats double pointer (pointer that points pointer)

  std::cout << "\n"
            // (void *) is used because buffer is char pointer
            << "*buffer : " << (void *)buffer << "\n"
            << "**ptr : " << ptr << "\n"
            << "data pointed by buffer : " << *buffer << "\n"
            << "data pointed by ptr : " << *ptr << "\n"
            << "data pointed by what ptr points : " << **ptr << "\n";
  delete[] buffer; // deletes char buffer from memory
}

int main(int argc, char *argv[]) {
  InitLog();
  using namespace std;
  Log("example 1 \b");
  example_1();
  Log("example 2 \b");
  example_2();
  Log("example 3 \b");
  example_3();
  DeinitLog();

  return 0;
}
