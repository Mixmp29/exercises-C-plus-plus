#include <iostream>

// Упражнение 6.4. Напишите взаимодействующую с пользователем функцию, которая
// запрашивает число и вычисляет его факториал. Вызовите эту функцию из функции
// main().

int fact(int val) {
  int ret = 1;

  while (val > 1) ret *= val--;

  return ret;
}

int main() {
  int v;

  std::cout
      << "Enter the number that will be used to calculate the factorial: ";
  std::cin >> v;

  std::cout << "The factorial of " << v << " is " << fact(v) << std::endl;
}