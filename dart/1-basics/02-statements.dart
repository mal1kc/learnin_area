void main() {
  
  //@note example 1
  final int money = 15;
  bool isUserRich = false;
  String userName = 'veli';

  print('$userName isimli kullanıcının parası : $money ₺');
  isUserRich = money > 10;
  if (isUserRich) {
    print('bir yarım yersin artık');
  } else {
    print('aç kaldın');
  }
  
  // şirket yöneticileri

  // @note example 2

  final String aCompany = 'ali';
  final String bCompany = 'burak';
  final String cCompany = 'cemil';
  final String kCompany = 'kamil';
  final String jCompany = 'ki';

  const int companyBossLenght = 3;
  String results = ' ';

//* √
  if (aCompany.length <= companyBossLenght) {
    results += ', ' + aCompany;
  }
  if (bCompany.length <= companyBossLenght) {
    results += ', ' + bCompany;
  }
  if (cCompany.length <= companyBossLenght) {
    results += ', ' + cCompany;
  }
  if (kCompany.length <= companyBossLenght) {
    results += ', ' + kCompany;
  }
  if (jCompany.length <= companyBossLenght) {
    results += ', ' + jCompany;
  }
  if (results.length == 1) {
    print('hepsinın adı $companyBossLenght den uzun');
  } else {
    print('adı $companyBossLenght den kısa olanlar $results');
  }

  // @note switch case

  final int classDegree = 2;

  switch(classDegree){
    case 2:
    print('bravo');
    break;
    case 1:
      print('olur');
    break;
    case 0:
    print('basaramadın');
    break;
    default:
    print('sen naptin ?');
    break;
  }

}
