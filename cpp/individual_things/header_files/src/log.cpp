#include "log.h"
#include <iostream>

void InitLog() { Log("Initializing Log"); }
void Log(const char *message) {
  std::cout << "\n\e[0;36m[LOG]\e[1;97m : " << message << "\n";
}
