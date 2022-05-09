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

  const int companyBossLength = 3;
  String results = ' ';

//* √
  if (aCompany.length <= companyBossLength) {
    results += ', ' + aCompany;
  }
  if (bCompany.length <= companyBossLength) {
    results += ', ' + bCompany;
  }
  if (cCompany.length <= companyBossLength) {
    results += ', ' + cCompany;
  }
  if (kCompany.length <= companyBossLength) {
    results += ', ' + kCompany;
  }
  if (jCompany.length <= companyBossLength) {
    results += ', ' + jCompany;
  }
  if (results.length == 1) {
    print('hepsinin adı $companyBossLength den uzun');
  } else {
    print('adı $companyBossLength den kısa olanlar $results');
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
    print('başaramadın');
    break;
    default:
    print('sen ne yaptın ?');
    break;
  }

}
