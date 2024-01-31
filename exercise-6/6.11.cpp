#include <iostream>

#include "6.8.hpp"

// Упражнение 6.11. Напишите и проверьте собственную версию функции reset(),
// получающую ссылку.

void reset(int& a) { a = 0; }

int main() {
  int a = 5;
  std::cout << a << std::endl;
  reset(a);
  std::cout << a << std::endl;
}