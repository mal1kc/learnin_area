#include <fstream> // for file stream
#include <iostream>
#include <string>

int write_file_Ios_filemode() {
  /*
  ** ! Ios file mode  |  meaning
  ** ! app            |  opens the file in append mode
  ** ! ate            |  seeks to the end of the file before reading/writing
  ** ! binary         |  opens the file in binary mode (instead of text mode)
  ** ! in             |  opens the file in read mode (default for ifstream)
  ** ! out            |  opens the file in write mode (default for ofstream)
  ** ! trunc          |  erases the file if it already exists
  */

  /* tip :
   * due to the way fstream was designed,it may fall if std::ios::in is used and
   * the file being opened does not exist. if you need to create a new file
   * using fstream, use std::ios::out mode only.
   */

  std::ofstream outf{"sample.txt", std::ios::app};
  if (!outf) {
    std::cerr << "nope thats not right, sample.txt could not be openeed for "
                 "writing\n";
    return 1;
  }
  outf << "this is line 3\n";
  outf << "this is line 4\n";

  // for explicitly opening and closing files

  outf << "this is line 5\n";
  outf.close();
  outf.open("sample.txt", std::ios::app);
  outf << "this is line 6\n";
  outf.close();
  return 0;
}

int read_sample_fixed() {
  std::ifstream inf{"sample.txt"};

  if (!inf) {
    std::cerr << "nope ,sample.txt could not be reading!\n";
    return 1;
  }
  while (inf) {
    std::string strInput;
    std::getline(inf, strInput); // fixed line
    std::cout << strInput << "\n";
  }
  return 0;
}

int read_sample() {
  // if stream is used for reading files
  std::ifstream inf{"sample.txt"};

  if (!inf) {
    std::cerr << "oh sh$t, sample.txt could not be opened for reading\n";
    return 1;
  }

  // while there's still stuff left to read
  while (inf) {
    std::string strInput;
    inf >> strInput;
    std::cout << strInput << "\n";
  }
  return 0;
}

int write_sample() {
  // ofstream is usde for writing files
  std::ofstream outf{"sample.txt"}; // created outfilestream for writing

  if (!outf) // checked for can we write
  {
    std::cerr << "no way, sample.txt could not be opened for writing\n";
    return 1;
  }

  outf << "this is line 1\n";
  outf << "this is line 2\n";

  return 0;
  // when outf goes out of scope, the ofstream
  // destructor will close the file
}

int main(int argc, char *argv[]) {

  std::cout << "write_sample"
            << "\n\n";

  write_sample();
  std::cout << "read_sample"
            << "\n\n";

  read_sample();
  std::cout << "read_sample_fixed"
            << "\n\n";

  read_sample_fixed();
  std::cout << "write_file_Ios_filemode"
            << "\n\n";

  write_file_Ios_filemode();
  std::cout << "read_sample_fixed"
            << "\n\n";

  read_sample_fixed();
  return 0;
}
