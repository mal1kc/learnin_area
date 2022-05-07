import '010-classes_Employee_class.dart';
import '../1-basics/009-enums.dart';

extension EmployeeControlExtension on Employee {
  String NameWBirthPlace() {
    return '${this.name}_${this.birthPlace}';
  }
}

extension ColorsSelectedExtension on Colors {
  bool checkName(String name) {
    return this.name == name;
  }
}

void main(List<String> args) {
  Employee employee_1 = Employee('namık', 'L');
  print(employee_1.NameWBirthPlace());
  Colors userColor = Colors.blue;
  print(userColor.checkName('blue'));
}