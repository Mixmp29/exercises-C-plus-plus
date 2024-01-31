#include <iostream>

#include "6.8.hpp"

// Упражнение 6.7. Напишите функцию, которая возвращает значение 0 при первом
// вызове, а при каждом последующем вызове возвращает последовательность
// увеличивающиеся числа.

int count() {
  static int ctr = 0;
  return ctr++;
}

int main() {
  for (int i = 0; i < 10; ++i) {
    std::cout << count() << std::endl;
  }
}