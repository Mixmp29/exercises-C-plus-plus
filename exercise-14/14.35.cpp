// Упражнение 14.35. Напишите класс, подобный классу PrintString, который читает
// строку из потока istream и возвращает строку, представляющую прочитанное. При
// неудаче чтения следует возвратить пустую строку.

#include <iostream>
#include <string>

/* class ScanString {
 public:
  ScanString(std::istream& i = std::cin) : is(i) {}

  std::string operator()() {
    std::string string;
    is >> string;

    if (!is) string = "no";

    return string;
  }

 private:
  std::istream& is;
}; */

class ScanString {
 public:
  ScanString(std::istream& i = std::cin) : is(i) {}

  void operator()(std::string& string) {
    is >> string;

    if (!is) string = "no";
  }

 private:
  std::istream& is;
};

int main() {
  ScanString scaner;
  std::string string;
  scaner(string);
  std::cout << string << std::endl;
}