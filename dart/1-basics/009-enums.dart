void main(List<String> args) {
  final defaultColor = Colors.black;
  Colors userColor = defaultColor;
  switch (userColor) {
    case Colors.white:
      print('are u want to be blind ${Colors.white}');
      break;
    case Colors.black:
      print('standart is standart ${Colors.black}');
      break;
    case Colors.red:
      print('for blood ${Colors.red}');
      break;
    case Colors.yellow:
      print('for sun ${Colors.yellow}');
      break;
    case Colors.blue:
      print('for tech ${Colors.blue}');
      break;
  }
}

enum Colors { white, black, red, yellow, blue }
