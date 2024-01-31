// Упражнение 10.14. Напишите лямбда-выражение, получающее два целых числа и
// возвращающее их сумму.

#include <iostream>

int main() {
  auto f = [](int a, int b) { return a + b; };

  std::cout << f(5, 10) << std::endl;
}