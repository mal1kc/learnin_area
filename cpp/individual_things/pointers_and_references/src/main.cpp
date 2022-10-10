#include "log.h"
#include <iostream>
#include <string.h>

// NOTE pointers are integer numbers that stores memory adresses of other type
// of data types
//
// helper video source
// -> https://www.youtube.com/watch?v=IzoFn3dfsPA
//

void p_example_1() {
  int var = 8;
  // void *ptr = nullptr; // null pointer (pointer that holds nothing)
  void *ptr = &var; // pointer that holds var's memory adress

  std::cout << "ptr :" << ptr << "\n";
}

void p_example_2() {
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

void p_example_3() {
  char *buffer = new char[8]; // allocate 8 bytes of memory
  // 4036990 is char code for "~" character
  memset(buffer, 4036990, sizeof(*buffer)); // fills 8 bytes with 0's
  char **ptr = &buffer; // thats double pointer (pointer that points pointer)

  // int var = 93;
  // int *buffer = &var;

  // int **ptr = &buffer; // thats double pointer (pointer that points pointer)

  // (void *) is used because buffer is char pointer
  std::cout << "*buffer : " << (void *)buffer << "\n"
            << "**ptr : " << ptr << "\n"
            << "data pointed by buffer : " << *buffer << "\n"
            << "data pointed by ptr : " << *ptr << "\n"
            << "data pointed by what ptr points : " << **ptr << "\n";
  delete[] buffer; // deletes char buffer from memory
}

void r_example_1() {
  int a = 5;
  int &ref = a; // ref is reference
  std::cout << "a : " << a << "\n"
            << "ref : " << ref << "\n";
  ref = 2;
  std::cout << "after setting ref to 2\n"
            << "a : " << a << "\n"
            << "ref : " << ref << "\n";
}

// extension funcs for r-example 2 to demonstrade refrence
// func1 that not used with ref it creates new value from copy ( func meant to
// Increament given value)
void r_example_2_ext1(int value) { value++; }
// func2 that used with ref ( func meant to  Increament given value)
// thats wrong (no work we want) beacause in here first increment then reference
// pointer void r_example_2_ext2(int *value) { *value++; }
void r_example_2_ext2(int *value) { (*value)++; }
// func3 that uses automaticly refrence // it does nearly same thing with func2
void r_example_2_ext3(int &value) { value++; }

// NOTE we need to use reference wherever we can because it looks nice 😎 and clean 🆒 (for better readability)
// FIXME IMPORTANT if we want to create ref and later we want to change ref we cannot do that not like pointers
//  Also we cannot use references without initilazing (setting something while creating);
                              
void r_example_2() {
  int a = 9;
  r_example_2_ext1(a);
  std::cout << "after applying func that expect int as arg : " << a << "\n";
  r_example_2_ext2(&a);
  std::cout << "after applying func that expect pointer as arg : " << a << "\n";
  r_example_2_ext3(a);
  std::cout << "after applying func that expect reference as arg : " << a
            << "\n";
}

int main(int argc, char *argv[]) {
  InitLog();
  Log("pointers example 1 \a");
  p_example_1();
  Log("pointers example 2 \a");
  p_example_2();
  Log("pointers example 3 \a");
  p_example_3();

  Log("refrences example 1\a");
  r_example_1();
  Log("references example 2\a");
  r_example_2();
  DeinitLog();

  return 0;
}
