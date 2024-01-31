#include <iostream>

// Упражнение 6.5. Напишите функцию, возвращающую абсолютное значение ее
// аргумента.

int ABS(int val) {
  if (val < 0) val *= -1;
  return val;
}

int main() {
  int v;
  std::cin >> v;
  std::cout << abs(v) << std::endl;
}