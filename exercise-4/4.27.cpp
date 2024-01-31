#include <iostream>
// Упражнение 4.27. Каков результат каждого из этих выражений?

int main() {
  unsigned long ul1 = 3, ul2 = 7;
  // unsigned long - 64 бита. Для краткости будет опущен 61 нуль слева.
  // 3 = 011, 7 = 111.

  std::cout << (ul1 & ul2) << std::endl;  // 3
  // & 011
  //   111
  // = 011 = 3
  std::cout << (ul1 && ul2) << std::endl;  // 1
  // Обычное условие на AND.
  std::cout << (ul1 | ul2) << std::endl;  // 7
  // | 011
  //   111
  // = 111 = 7
  std::cout << (ul1 || ul2) << std::endl;  // 1
  // Обычное условие на OR.
}