// Упражнение 8.2. Проверье созданную функцию, передав ей при вызове объект cin
// в качестве аргумента.

#include <iostream>
#include <string>

std::istream& read(std::istream& is) {
  std::string str;

  while (!is.eof() && is >> str) {
    std::cout << "----------\n" << str << '\n' << std::endl;
  }

  is.clear();

  return is;
}

int main() { read(std::cin); }