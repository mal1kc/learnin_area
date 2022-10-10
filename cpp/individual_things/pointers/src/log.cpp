#include "log.h"
#include <iostream>
#include <ostream>

void Log(const char *message) {
  std::cout << "\e[0;36m" // cyan ansi escape sequence
            << "[log]"
            << "\e[1;97m" // bold white ansi escape sequence
            << " : " << message << "\n";
}
void InitLog() {
  Log("\e[41m" // red background ansi escape sequence
      "program started"
      "\e[0m" // reset color ansi escape sequence
  );
}

void DeinitLog() {
  Log("\e[41m" // red background ansi escape sequence
      "program finished"
      "\e[0m" // reset color ansi escape sequence
  );
  std::cout << std::endl;
}
