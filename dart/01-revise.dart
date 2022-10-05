// revise from 0 to basic class subjects

void main() // main method is the entry point of the program
{
  String text = 'hello world!'; // String is data type for texts
  int number = 0; // int is data type for integer numbers
  const int numberConstant = 5; // const is keyword for constant variables
  double numberFloat = 0.1; // double is data type for floating point numbers

  print(text); // print is for give output to console
  print('number: $number'); // '$' is for format output

  //h1 operators
  // sum +
  // difference -
  // product *
  // quotient /
  // remainder %
  // increment ++
  // decrement --
  // equal ==
  // not equal !=
  // greater than >
  // less than <
  // greater than or equal to >=
  // less than or equal to <=

  print(
      'sum of number and numberConstant: ${number + numberConstant}'); // '${}' is for format output
  print('numberConstant: $numberConstant');
  print('numberFloat: ${numberFloat}');

  // logical operators : &&, ||, !
  // && is for and
  // || is for or
  // ! is for not

  //h1 statements

  // if statement
  if (number == 0) {
    print('number is zero'); // if number is 0 then print 'number is zero'
  } else if (number == 1) {
    print('number is one'); // if number is 1 then print 'number is one'
  } else {
    print(
        'number is not zero'); // if number is not 0 then print 'number is not zero'
  }

  // switch case
  switch (number) {
    case 0:
      print('number is zero');
      break;
    case 1:
      print('number is one');
      break;
    case 2:
      print('number is two');
      break;
    default:
      print('number is {$number}');
      break;
  }

  // for loop and list

  // List for multiple objects of specified data type like List<data type> variableName
  List<String> stringList = ['hello', 'world', '!'];
  List<int> integerList = [0, 1, 2, 3, 4, 8, 56, 9];

  print(stringList);

  // for loop is using to loop through the list
  // way 1:
  for (int i in integerList) {
    print(i);
  }
  // way 2:
  for (int i = 0; i < stringList.length; i++) {
    print('loop $i: ${stringList[i]}');
  }

  // while loop is using to loop through the list
  int i = 0;
  while (i < stringList.length) {
    print('loop $i: ${stringList[i]}');
    i++;
  }

  print(integerList.first); // first is for get first element of list
  print(integerList.last); // last is for get last element of list
  print(integerList.length); // length is for get length of list
  print(integerList.isEmpty); // isEmpty is for check list is empty or not

  sayHello0('name'); // used sayHello0 function with 'name' parameter
  sayHello1('name'); // used sayHello1 function with 'name' parameter
  sayHello2(
      name:
          'name'); // used sayHello2 function with name variable to 'name' parameter
  sayHello2(); // used sayHello2 function with no parameter(it will be 'none' by default)

  // Map for multiple objects with key value pair

  //* Map<key data type, value data type> variableName = {key1: value1, key2: value2, key3: value3};

  Map<String, int> integerMap = {
    '500': 500,
    '100': 100,
    '30': 30,
    '40': 40,
    '60': 60
  };

  // we can use for loop to loop through the map
  for (var key in integerMap.keys) {
    print('key : $key ,value : ${integerMap[key]}');
  }

  for (var value in integerMap.values) {
    print('value : $value');
  }

  print(integerMap.keys); // get keys of map and print it
  print(integerMap.values); // get values of map and print it
  print(integerMap.isEmpty); // check map is empty or not

  Map<String, Map<String, List<int>>> nestedMap = {
    'name': {
      'first': [1, 2, 3, 4, 5],
    }
  };

  // we can use for loop to loop through the nested map
  for (var key in nestedMap.keys) {
    if (nestedMap[key] != null)
    // if nested map is not null then print it
    {
      for (var key2 in nestedMap[key]!.keys)
      // !. is for ignore null check (because we know that nested map is not null in this case)
      {
        print('$key2 : ${nestedMap[key]?[key2]}');
      }
    } else {
      print('$key is empty');
    }
  }

  // h1 null

  // int? variable; // '?' means his variable can be null
  int? variable = null; // 'null' is for null value
  print(variable); // print 'null'
  variable = 10; // set variable to 10
  print(variable); // print '10'

  List<String?> wordList = ['hello', null, 'world'];

  for (var word in wordList) {
    // print(word + ','); // this will give error because null is not allowed in + operator
    //* '??' operator checks word if it is null then it will give 'none' to one time only
    // print(word ?? 'none');
    // print(word);
    print((word ?? 'none') + ','); // this will give
    // 'hello,
    // none,
    // world,'
  }

  // h1 one line if statement

  // statement1 ? if true : else false;
  print('a' == 'a' ? 'hi' : 'bye');
  print('a' != 'a' ? 'hi' : 'bye');

  int? nullNumber;
  // if nullNumber is null it is become 5 for once after it become null again
  print((nullNumber ?? 5));
  nullNumber = nullNumber ?? 5;
  print(nullNumber);

  nullNumber = 5;
  print(nullNumber);

  // h1 enums

  exampleEnum enumExample = exampleEnum.one;
  print(enumExample); // print 'one'
  for (var i in exampleEnum.values) {
    print(i); // print 'one', 'two', 'three' ...
  }
}

// create function that says hello with given name
void sayHello0(name) {
  print('Hello $name');
}

// create function that says hello with given name (w specified parameter type of name variable)
void sayHello1(String name) {
  print('Hello $name');
}

// create function that says hello with given name (w default value of name variable is 'none')
void sayHello2({name = 'none'}) {
  print('Hello $name');
}

// create function that returns sum of two numbers
int sum(int num1, int num2) {
  return num1 + num2;
}

// create function that returns double type sum of two  double type numbers
double sumD(double num1, double num2) {
  return num1 + num2;
}

// h1 enums

// enum is used to create constant values with enumeration
// enum name {value1, value2, value3};
enum exampleEnum { one, two, three, four, five, six, seven, eight, nine, ten }
