void main(List<String> args) {
  final user = _User('s123c', bodySize: null);
  print('${user}');
  
}

class _User {
  // private class
  final String Id;
  int? bodySize;

  _User(this.Id, {this.bodySize});

}
