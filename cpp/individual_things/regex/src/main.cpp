#include <ios>
#include <iostream>
#include <regex>

// source of example code  ---|
//                            
// "https://www.fluentcpp.com/2020/02/28/c-regex-101-simple-code-for-simple-cases-with-regexes/"

/* NOTE std::regex used for creating regex patterns

      std::regex regexp = std::regex(R"(\d+)");
*/
/* NOTE std::regex_match is used for check if the entire searched text matches
 * \ the pattern of regex
 *
 * NOTE std::regex_search is used for check if searched text contains a sub-part
 * \ that matches the pattern of regex
 *
 * NOTE in other way,
 *
 *  std::regex_match is used to validated that string follows a pattern
 * \ (a date, a phone number, and so on)
 *
 *  std::search is used to perform the equivalent of a greo in piece of text
 */

int example_regexlib_usage() {
  auto const regex = std::regex(R"((my|your) regex)");
  auto const myText = std::string("A piece of text that contains my regex.");
  bool myTextContainsRegex =
      std::regex_search(myText, regex); // searching for regex match

  // auto const yourText =
  //     std::string("A piece of text that contains your regex.");
  // bool const yourTextContainsRegex = std::regex_search(yourText, regex);

  // auto const theirText =
  std::string("A piece of text that contains their regex.");
  // bool const theirTextContainsRegex = std::regex_search(theirText, regex);

  // std::cout << std::boolalpha << myTextContainsRegex << '\n'
  //           << yourTextContainsRegex << '\n'
  //           << theirTextContainsRegex << '\n';
  auto matchResults = std::smatch{};
  myTextContainsRegex = std::regex_search(
      myText, matchResults, regex); // for finding position of match

  std::cout << "text : " << myText << "\n"
            << "regex pattern : "
            << "((my|your) regex)"
            << "\n"
            << "text have any matches : " << std::boolalpha
            << myTextContainsRegex << "\n";
  std::cout << "prefix : " << matchResults.prefix() << "\t, suffix"
            << matchResults.suffix() << "\n";
  std::cout << "matchResults location is : " << matchResults.prefix().length()
            << "," << matchResults.length() << "\nmatch : ["
            << myText.substr(matchResults.prefix().length(),
                             matchResults.length())
            << "]\n\n";
  return 0;
}

int my_regex_example() {

  using namespace std;

  auto const regexp = regex(R"(\d+)");
  auto const example_text = string("MemTotal:       16313192 kB"
                                   "MemFree:        10332752 kB"
                                   "MemAvailable:   13959848 kB");
  bool const example_contains_regex = regex_search(example_text, regexp);
  cout << boolalpha << example_contains_regex << "\n";
  return 0;
}

int main(int argc, char *argv[]) {

  std::cout << "working example output"
            << "\n";
  example_regexlib_usage();
  std::cout << "my example output"
            << "\n";

  my_regex_example();
  return 0;
}
