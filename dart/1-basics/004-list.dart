void main() {
  String name = '';
  List<int> moneys = [100, 110, 500];
  List<Object> objeler = [100, 'merhaba', 9900, 7.98];

  print('musteri  2 parasi: ${moneys[0]}');

  print(moneys);

  List<double> customerMoney = List.generate(30, (index)
  {
    return (index) - 15;
  }
  );
  print(moneys.indexOf(500));

  print(customerMoney);
}
