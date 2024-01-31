// Упражнение 8.9. Используйте функцию, написанную для первого упражнения 8.1.2
// (стр. 404), для вывода содержимого объекта класса sistringstream.

#include <iostream>
#include <sstream>
#include <string>

std::istream& read(std::istream& is) {
  std::string str;

  while (!is.eof() && is >> str) {
    std::cout << "----------\n" << str << '\n' << std::endl;
  }

  is.clear();
  return is;
}

int main() {
  std::string str = "Some string here.";
  std::istringstream record(str);
  read(record);
}