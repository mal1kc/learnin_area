class Employee {
  late final String name;
  late final String? birthPlace;

  double? _money;

  double? get money => _money;

  set money(double? money) {
    _money = money == null ? 0.0 : money;
  }

  late Map<String, String> cloths;

  Employee(String name, String birthPlace,
      {Map<String, String> cloths = const {
        'body': 'shirt',
        'legs': 'black pants'
      },
      double money = 0.0}) {
    this.name = name;
    this.birthPlace = birthPlace;
    this.cloths = cloths;
    _money = money;
  }

  bool get isClothsEmpty => this.cloths.isEmpty;
  Map<String,String> get clothsTemplate =>{
        'body': 'shirt',
        'legs': 'black pants'
  };
}
