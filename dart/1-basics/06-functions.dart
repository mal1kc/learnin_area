void main(List<String> args)
{
  selamla0();                 // herkese merhabe!
  selamla1('ahmet');          // ahmet, merhaba!
  selamla1('mehmet');         // mehmet, merhaba!
  selamla2(name: 'ali');      // ali, merhaba!
  selamla2();                 // isimsiz, merhaba!
  toplaYaz(5, 8);             // 5 + 8 = 13
  print(topla(8, 5));         // 13
  print(toplaD(8, 5));        // 13.0 ben afk
}

void selamla0() {
  print('herkese merhaba!');
}

void selamla1(String name) {
  print('$name, merhaba!');
}

void selamla2({name = 'isimsiz'}){
  print('$name, merhaba!');
}
void toplaYaz(int say1, int say2) {
  print('$say1 + $say2 = ${say1 + say2}');
}

int topla(int say1,int say2){
  return say1 + say2;
}
double toplaD(double say1,double say2){
  return say1 + say2;
}