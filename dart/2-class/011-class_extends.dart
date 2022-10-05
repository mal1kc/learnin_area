// extends and abstract class
void main() {
  Car civic = Car('civic', '2007', 'honda', 'yakındaki', 4);
  civic.sayCarInfo();
  Truck truck_1 =
      Truck('truck_1', '1999', 'mercedes', 'uzak servis', 6, 3.5, 500.0);
  truck_1.sayCarInfo();
  print(truck_1.lengthDivideVolume);
}

abstract class ICar {
  final String name;
  final String model;
  final String producer;
  String service;
  int wheels;

  ICar(this.name, this.model, this.producer, this.service, this.wheels);

  void sayCarInfo() {
    print(
        '🚗-${this.name}\n🚗-${this.model}\n👷-${this.producer}\n🔧-${this.service}\nwheels-${this.wheels}');
  }
}

class Car extends ICar {
  Car(String name, String model, String producer, String service, int wheels)
      : super(name, model, producer, service, wheels);
}

class Truck extends ICar {
  double length;
  double volume;

  Truck(String name, String model, String producer, String service, int wheels,
      this.length, this.volume)
      : super(name, model, producer, service, wheels);
  double get lengthDivideVolume => length/volume;
}
