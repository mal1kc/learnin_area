void main() {

  print('Hello, World!');

  String verinin_adi = 'Dart';
  
  print(verinin_adi);

  String userName = 'Ahmet';
  int userMoney = 25;
  int userAge = 15;

  userAge = userAge ~/ 2;

  print('Merhaba $userName, $userMoney adet para var.');
  print('Merhaba $userName, ${userMoney + 5} adet para var.');
  print('Merhaba $userName, $userAge yaşında.');

}
