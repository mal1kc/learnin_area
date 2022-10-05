import '010-classes_Company_class.dart';
import '010-classes_Employee_class.dart';

void main(List<String> args) {
  Employee malik = Employee('malik', 'kocaeli');
  malik.cloths = {
    'body':'t-shirt',
    'legs':'black jean'
  };
  print(malik.cloths['body']);
  print(malik.cloths['legs']);
  print(malik.cloths);
  print(malik.money);

  Company youtube =
      Company('youtube', 2005, geoCode: [37.62792, -122.42654], country: 'US');

  print(youtube.isEmptyID); // false

  print(malik.isClothsEmpty);
  print(malik.clothsTemplate);
}
