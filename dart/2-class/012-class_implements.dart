void main(List<String> args) {


}

abstract class IStudent {
  final String age;
  final String name;

  IStudent(this.age, this.name);

  void printInfo() {
    print('$name-$age');
  }
}

class Student_S implements IStudent {
  final String age;
  final String name;

  Student_S(this.age, this.name);

  @override
  void printInfo() {
    // print('$age-$name');
  }
}

class Student_O implements IStudent{

  final String age;
  final String name;
  final List<int> notes;
  Student_O(this.age, this.name,this.notes);


  @override
  void printInfo() {
    print('$name-$age-${notes.length}');
      print('notes:\n');
    for (var item in notes) {
      print('$item');
    }
    print('\n');
  }

}
