#include <iostream>

// Упражнение 6.3. Напишите и проверьте собственную версию функции fact().

int fact(int val) {
  int ret = 1;

  while (val > 1) ret *= val--;

  return ret;
}

int main() { std::cout << fact(5) << std::endl; }