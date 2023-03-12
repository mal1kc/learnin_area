#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>

/*
** NOTE list syntax
** template < class Type, class Alloc = allocator<T> > class list;
**
**  -- > T = defines the type of element contained, any data type include user
*     |-> defined types
**
**  -- > Alloc = defines the type of allocator object this uses allocator class
**    |-> template by default
**    |-> it is value-dependent and uses a simple memory allocation model.
**
*/

void example_1() {
  using namespace std;
  list<string> strList = {string("hello"), string("world")};
  for (string str : strList) {
    cout << str << "\n";
  }
}

/*
** NOTE some list functions
**
**    | fn                | desc
**    |
**    | insert()          | inserts a new item before the position the iterator
**    |                      points.
**    | push_back()       | add a new item at the list's end
**    |
**    | push_front()      | add a new item at the list's front
**    |
**    | pop_front()       | it deletes the list's first item
**    |
**    | size()            | return item count contained by list
**    |
**    | front()           | to determine the list's first items
**    |
**    | back()            | to determine the list's last's item
**    |
**    | reverse()         | it reverses the list items
**    |
**    | merge()           | it merges two sorted list's
**    |
**
* NOTE some list constructors
*
* |> default constructor --> it creates an empty list, that with zero elements
*
* |> fill constructor --> it creates a list with n elements and assigns a
*                      |-> value of zero to each element
*
* |> range constructor --> creates with many elements in the range of
*                       |-> first and last
*
* |> copy constructor --> creates with a copy of each element contained
*                      |-> in the existing list
*
* |> move constructor --> creates list with the elements of another list using
*                      |-> move semantics
*
* |> initializer list constructor --> creates with elements of another list
*                                  |-> using move semantics
*/

void example_2() {
  using namespace std;

  // default constructor
  list<int> l;
  // fill constructor
  list<int> l1 = {10, 20, 30};
  // range constructor
  list<int> l2(l1.begin(), l1.end());
  // move constructor
  list<int> l3(move(l1));

  cout << "size of list 1: " << l.size() << "\n";
  cout << "list l2 contents : "
       << "\n";
  for (auto it = l2.begin(); it != l2.end(); it++)
    cout << *it << "\t";

  cout << "\n"
       << "list 13 contents: "
       << "\n";
  for (auto it = l3.begin(); it != l3.end(); ++it)
    cout << *it << "\t";
  cout << "\n";
}

/*
 * NOTE container properties
 *
 *  | property           | desc
 *  |
 *  | sequence           | sequence containers order their elements
 *  |                      in a strict linear sequence, elements are
 *  |                      access by their position in the sequence
 *  |
 *  | doubly-linked list | every element has information on how to
 *  |                      locate previous and next elements this
 *  |                      allows for constant time for insertion
 *  |                      and deletion operations
 *  |
 *  | allocator-aware    | an allocator object is used for modifying
 *  |                      the storage size dynamically
 *
 */

void example_3() {

  using namespace std;
  list<int> mlist = {12, 5, 10, 9};
  mlist.push_front(11);
  mlist.push_back(18);
  auto it = std::find(mlist.begin(), mlist.end(), 10);
  if (it != mlist.end())
    mlist.insert(it, 21);
  for (int x : mlist) {
    cout << x << "\n";
  }
}

void example_4() {
  using namespace std;
  list<int> mlist = {15, 213, 42, 53, 32};
  cout << "mlist elements : \n";
  for (int x1 : mlist) {
    cout << x1 << "\t";
  }
  list<int>::iterator i = mlist.begin();
  mlist.erase(i);
  cout << "\n"
       << "mlist elements after deletion: ";
  for (int x2 : mlist) {
    cout << x2 << '\t';
  }
}

void example_5() {
  using namespace std;
  list<string> strList0 = {string("hello"), string("world")};
  list<string> strList1 = {"!", "and", "hello", "mom !"};
  // list<string> strList2 = strList0;

  for (auto str : strList1)
    strList0.push_back(str);
  cout << "items added via pushback func :"
       << "\n";

  cout << "strList0 :"
       << "\n";
  for (auto str : strList0)
    cout << str << " ";

  cout << "\n "
       << "strList1 :"
       << "\n";
  for (auto str : strList1)
    cout << str << " ";

  // cout << "\n"
  //      << "strList2 :"
  //      << "\n";

  // for (auto str : strList2)
  //   cout << str << " ";

  // strList2.merge(strList1);
  // cout << "items added via merge func"
  //      << "\n";
  // cout << "strList0 :"
  //      << "\n";
  // for (auto str : strList2)
  //   cout << str << " ";
}

int main(int argc, char *argv[]) {
  std::cout << "example_1 :\n"
            << "----------->\n";
  example_1();
  std::cout << "<-----------\n";

  std::cout << "example_2 :\n"
            << "----------->\n";
  example_2();
  std::cout << "<-----------\n";

  std::cout << "example_3 :\n"
            << "----------->\n";
  example_3();
  std::cout << "<-----------\n";

  std::cout << "example_4 :\n"
            << "----------->\n";
  example_4();
  std::cout << "<-----------\n";

  std::cout << "example_5 :\n"
            << "----------->\n";
  example_5();
  std::cout << "<-----------\n";

  return 0;
}
