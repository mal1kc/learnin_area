void main(List<String> args) {
  Map<String, int> users = {'ayşe': 32, 'ahmet': 20};

  print('ayşenin parası ${users['ayşe']}');
  for (var item in users.keys) {
    print('$item parası : ${users[item]}');
  }

  print("\x1B[2J\x1B[0;0H"); // for clearing output

  Map<String, int> categories = {
    'aksiyon': 0,
    'macera': 1,
    'drama': 3,
    'bilim-kurgu': 4,
    'gerilim': 5,
    'korku': 6,
    'fighting': 7
  };
  for (var i = 0; i < categories.length; i++) {
    print(
        'kategori adı : ${categories.keys.elementAt(i)},kategori id : ${categories.values.elementAt(i)}');
  }

  Map<String, List<int>> movies = {
    '🦇batman': [0, 1],
    '🌌interstellar🛰️🚀': [0, 4, 1],
    'taxi driver🚕': [0, 3],
    '👽alien👽': [0, 1, 4, 5, 6],
    '👽👽aliens': [0, 4, 5],
    '🦾iron man': [0, 4, 1],
    '🚗drive my car🚗': [3],
    '🐉🦖gorilla V kong🦍': [7],
    'shin godzilla 🐉🦖': [0, 5, 3, 4]
  };
  List<String> same_category = [];

  for (var i = 0; i < categories.length; i++) {
    for (var item in movies.keys) {
      for (var j = 0; j < movies[item]!.length; j++) {
        if (categories.values.elementAt(i) == movies[item]![j]) {
          same_category.add(item);
        }
      }
    }
    print(
        '${'-' * 10} \n \n ${categories.keys.elementAt(i)} kategorisindeki filmler : ');
    for (var i = 0; i < same_category.length; i++) {
      print('- ${same_category[i]}');
    }
    print('\n${'-' * 10}');
    same_category.clear();
  }
}
