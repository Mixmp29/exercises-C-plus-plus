#include <iostream>
#include <string>

int myatoi(const char* str) {
  int pow = 10;
  int result = 0;

  for (auto i = str; *i != '\0'; ++i) {
    if (*i >= '0' && *i <= '9') {
      result *= pow;
      result += *i - '0';
    }
  }

  return result;
}

int main(int argc, char** argv) {
  if (argc > 0) {
    for (int i = 0; i < argc; ++i) {
      std::string s = argv[i];
      if (s == "-atoi" && i != argc - 1) myatoi(argv[i + 1]);
    }
  }
}