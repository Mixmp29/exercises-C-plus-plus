// Упражнение 14.36. Используя класс из предыдущего упражнения, организуйте
// чтение со стандартного устройства ввода, сохраняя кажду строку в векторе как
// элемент.

#include <iostream>
#include <string>
#include <vector>

class ScanString {
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
};

/* class ScanString {
 public:
  ScanString(std::istream& i = std::cin) : is(i) {}

  void operator()(std::string& string) {
    is >> string;

    if (!is) string = "";
  }

 private:
  std::istream& is;
}; */

int main() {
  ScanString scaner;
  std::vector<std::string> vec;
  // std::string string;

  while (std::cin) {
    // scaner(string);
    vec.push_back(scaner());
  }

  for (auto e : vec) std::cout << e << " ";
  std::cout << std::endl;
}