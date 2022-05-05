void main(List<String> args) {
  
  List<int> tamSayiListesi = [500,100,30,40,60];

  tamSayiListesi.sort();
  for (int i = 0; i < tamSayiListesi.length; i=i+1) {
    print('tam sayi : ${tamSayiListesi[i]}');
  }
  for (int i = 0; i < tamSayiListesi.length; i=i+2) {
    print('tam sayi : ${tamSayiListesi[i]}');
  }


}