void main() {
  /* 
  * 100 kapasiteli bir halı saha var
  * saat 10 da 20 kisilik bir grub(musteri1) gelcek
  * saat 10 müsteri2 gelip 80 kisilik yer arıtcak
  * bu islemler sonucunda halı sahada ne kadar kişilik yer kalmıştır
  */

  const int kapasite = 100;
  int musteri1 = 20;
  int musteri2 = 80;

  int kalanKapasite = kapasite;

  print('dükkanı açtım saat 9');
  print(
      '\nsaat 10 müşteri1 geldi kapasitemden $musteri1 düştü, yeni kapasitem : ${kalanKapasite = kapasite - musteri1}\n');
  print(
      '\nbir musteri daha geldi musteri2 $musteri2 lik yer ayırttı kalan kapasitem : ${kalanKapasite = kalanKapasite - musteri2}\n');
}
