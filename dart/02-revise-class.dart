// class is a blueprint for creating objects
class Person {
  final String name; // final is used for constant
  late final int age; // late is used for lazy initialization

  Person(this.name,
      {this.age =
          0}); // this function is used for initializing the object (constructor) and it is need to be named as same as class name
  // age is optional parameter and it is set to 0 by default

  // * this is also constructor but it is used with lazy initialization
  // late final String name; // final is used for constant
  // late final int age; // late is used for lazy initialization
  // Person(String name,int age){
  //   this.name = name;
  //   this.age = age;
  // }

  bool isOld() =>
      age >=
      60; // this is one line function if we add 'get' keyword then it will be getter
  bool get isAdult => age >= 18; // get is used for getter
  bool get isChild => age < 18; // get is used for getter
}

class Employee extends Person {
  // Employee is a subclass of Person
  String company;
  Employee(String name, int age, this.company)
      : super(name,
            age: age); // this is used for calling the super class constructor

}

class Company {
  String name;
  late final int foundationYear;
  String? _country; // ? is used for nullable and _ is used for private variable
  String? get country =>
      _country; // this line is used for getter of private variable

  set country(String? country) {
    // this line is used for setter of private variable

    // this is one line if else statement
    // example:
    // statement ? if : else
    _country = country == null ? 'CA' : country;
  }

  Company(this.name, this.foundationYear, {String? country = null})
  // // country is optional parameter and it is set to 'CA' by default if we don't pass it
  {
    // (we can set default country as 'CA' in the constructor but we don't because for revise purpose )
    if (country == null) {
      _country = 'CA';
    } else {
      _country = country;
    }
  }
}

abstract class IBook {
  final String title;
  final String author;
  final int pages;

  bool? _isAvailable;
  bool? get isAvailable => _isAvailable;
  set isAvailable(bool? isAvailable) {
    _isAvailable = isAvailable;
  }

  late String _id;
  get id => _id;
  void _createId() // this is used for creating id private method
  {
    _id = _id =
        "${title.toLowerCase().replaceAll(' ', '_')}.${author.toLowerCase().replaceAll(' ', '_')}.${pages}";
  }

  IBook(this.title, this.author, this.pages, {bool? isAvailable = null}) {
    _createId();
  }

  void printInfo() {
    print("$title by $author ($pages pages)");
  }
}

class Encyclopedia extends IBook // Encyclopedia is a inherited class from IBook
{
  final int edition;
  Encyclopedia(String title, String author, int pages,
      {bool? isAvailable = null, this.edition = 1})
      : super(title, author, pages, isAvailable: isAvailable);

  @override // this 'override' keyword used for overriding the method of IBook
  void printInfo() {
    print("$title by $author ($pages pages) edition $edition");
  }
}

class Book extends IBook // Book is a inherited class from IBook
{
  final String publisher;
  Book(String title, String author, int pages,
      {bool? isAvailable = null, this.publisher = 'unknown'})
      : super(title, author, pages, isAvailable: isAvailable);
}

class Book_O implements IBook // Book is a inherited class from IBook
{
  // if we use 'implements' keyword then we need to implement all the methods and properties of IBook
  @override
  late String _id;

  @override
  bool? _isAvailable;

  @override
  bool? isAvailable;

  @override
  void _createId() {
    _id = _id =
        "${title.toLowerCase().replaceAll(' ', '_')}.${author.toLowerCase().replaceAll(' ', '_')}.${pages}";
  }

  @override
  late String author;

  @override
  String get id => _id;
  @override
  late int pages;

  @override
  late String title;

  Book_O(String s, String t, int i, {required bool isAvailable}) {
    this.title = s;
    this.author = t;
    this.pages = i;
    this.isAvailable = isAvailable;
    _createId();
  }
  @override
  void printInfo() {
    print("$_id book : $title by $author ($pages pages)");
  }
}

class _Book implements IBook
// _Book private class(class only accessible from created file ) is a inherited class from IBook
{
  late double discount;

  @override
  late String _id;

  @override
  bool? _isAvailable;

  @override
  bool? isAvailable;

  @override
  late String author;

  @override
  String get id => _id;
  @override
  late int pages;

  @override
  late String title;
  @override
  void _createId() {
    _id = _id =
        "${title.toLowerCase().replaceAll(' ', '_')}.${author.toLowerCase().replaceAll(' ', '_')}.${pages}";
  }

  _Book(this.title, this.author, this.pages,
      {this.isAvailable = null, this.discount = 20.0}) {
    _createId();
  }

  @override
  void printInfo() {
    print(
        "$_id book : $title by $author ($pages pages) with discount %$discount");
  }
}

extension Book_E on IBook
// this is used for extending the class with new methods
{
  void printInfoFromEx() {
    print("$_id book : $title by $author ($pages pages)");
    print('used from extension');
  }

  List<String> nameWAuthor() {
    return [this.title, this.author];
  }
}

void main(List<String> args) {
  Person person = Person('John', age: 30); // this is used for creating object
  print(person.name); // this is used for accessing the property
  print(person.age); // this is used for accessing the property
  print(person.isOld()); // this is used for calling the method
  print(person.isAdult); // this is used for calling the getter
  print(person.isChild); // this is used for calling the getter

  Employee employee =
      Employee('John', 30, 'Google'); // this is used for creating object
  print(employee.name);
  print(employee.age);
  print(employee.isOld());
  print(employee.isAdult);
  print(employee.isChild);
  print(employee.company);

  Company company = Company('Google', 1998,
      country: 'USA'); // this is used for creating object
  print(company.name);
  print(company.foundationYear);
  print(company.country);

  Book book = Book('Flutter', 'Flutter', 100,
      isAvailable: true,
      publisher: "no_one"); // this is used for creating object
  print(book.title);
  print(book.author);
  print(book.pages);
  print(book.isAvailable);
  print(book.id);
  print(book.publisher);
  book.printInfo(); // we can call the method of IBook

  Encyclopedia encyclopedia = Encyclopedia('Google', 'John', 100,
      isAvailable: true,
      edition: 1); // this is used for creating Encyclopedia object
  print(encyclopedia.title);
  print(encyclopedia.author);
  print(encyclopedia.pages);
  encyclopedia
      .printInfo(); // we can call the method of Encyclopedia class using Encyclopedia object

  Book_O book_o = Book_O('n_book', 'john', 99, isAvailable: true);
  print(book_o.title);
  print(book_o.author);
  print(book_o.pages);
  book_o.printInfo();

  _Book book_p =
      _Book('private book', 'private', 19, isAvailable: false, discount: 20.0);
  print(book_p.id);
  print(book_p.title);
  print(book_p.author);
  print(book_p.pages);
  print(book_p.discount);
  book_p.printInfo();

  book_p.isAvailable = false;
  print(book_p.isAvailable);

  book_p.isAvailable = null;
  print(book_p.isAvailable);

  print(book_p.nameWAuthor());
  book_p.printInfo();
  book_p.printInfoFromEx();

  print(book_o.nameWAuthor());
  book_o.printInfo();
  book_o.printInfoFromEx();
}
