void main(List<String> args) {
  List<int> integerList = [500, 100, 30, 40, 60];

  integerList.sort();
  for (int i = 0; i < integerList.length; i = i + 1) {
    print('integer : ${integerList[i]}');
  }
  for (int i = 0; i < integerList.length; i = i + 2) {
    print('integer : ${integerList[i]}');
  }
}
