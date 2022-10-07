#include <iostream>
#include <regex>
#include <string>

// int main(int argc, char *argv[]) {
//   std::string example_text = "MemTotal:       16313192 kB"
//                              "MemFree:        10332752 kB"
//                              "MemAvailable:   13959848 kB";
//   std::regex regexp("([0-9]+\\S\\w)");
//   std::smatch m;
//   if (std::regex_search(example_text, m, regexp)) {
//     std::cout << "string that matches the pattern:"
//               << "\n";
//     // for (auto x : m)
//     std::cout << m.size() << "\n";
//     for (uint i = 0; i < m.size(); i++)
//       std::cout << m[i] << " ";
//   }
//   return 0;
// }

int main(int argc, char *argv[]) {
  using namespace std;
  string sp("geeks for geeks"
            "geks for geeks"
            "geeks for geeks");
  regex re("(\\w+)");

  // flag type for determining the matching behavior
  // && here it is for matches on strings.
  smatch match;

  // we can use member function on match
  // to extract the matched pattern.
  if (regex_match(sp.begin(), sp.end(), match, re) == true) {

    // The size() member function indicates the
    // number of capturing groups plus one for the overall match
    // match size = Number of capturing group + 1
    // (.*) which "forgeeks" ).
    cout << "Match size = " << match.size() << endl;

    // Capturing group is index from 0 to match_size -1
    // .....here 0 to 2
    // pattern at index 0 is the overall match "geeksforgeeks"
    // pattern at index 1 is the first capturing group "geeks"
    // pattern at index 2 is the 2nd capturing group "forgeeks"

    cout << "Whole match : " << match.str(0) << endl;
    cout << "First capturing group is '" << match.str(1)
         << "' which is captured at index " << match.position(1) << endl;
  } else {
    cout << "No match is found" << endl;
  }
  return 0;
  return 0;
}
