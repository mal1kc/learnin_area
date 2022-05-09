void main(List<String> args) {
  // int? variable; // '?' means his variable can be null

  // // '!' ignores item to be null but if variable is null program crashes
  // print(variable! +10);

  List<String?> names = ['john', null, 'jack'];

  for (int i = 0; i < names.length; i++) {
    if (names[i] == null) {
      print('$i.item is null');
      // names[i] = names[i]! + ' black'; //! this will not work because item is null
    } else {
      names[i] =
          names[i]! + ' black '; //- this will work because item is not null
    }
  }
  print(names);

  //h1 one line if else statements
  // statement ? if : else
  print('a' == 'a' ? 'hi' : 'bye');
  print('a' != 'a' ? 'hi' : 'bye');

  int? nullnumber;
  // if nullnumber is null it is become 5 for once after it become null again
  print((nullnumber ?? 5));
  nullnumber = nullnumber ?? 5;
  print(nullnumber);

  nullnumber = 5;
  print(nullnumber);
}
