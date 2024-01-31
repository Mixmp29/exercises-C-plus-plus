#include <iostream>

// Упражнение 2.13. Каково значение переменной j в вследующей программе?

int i = 42;

int main() {
  int i = 100;
  int j = i;  // j = 100;

  std::cout << j << std::endl;
}