void main() {
  String name = '';
  List<int> moneys = [100, 110, 500];
  List<Object> objeler = [100, 'merhaba', 9900, 7.98];

  print(objeler);
  name = 'isim';
  print('müşteri : $name -> 2 parası: ${moneys[0]}');

  print(moneys);

  List<double> customerMoney = List.generate(30, (index) {
    return (index) - 15;
  });
  print(moneys.indexOf(500));

  print(customerMoney);
}
