#include <iostream>

#include "6.8.hpp"

// Упражнение 6.10. Напишите, используя указатели, функци., меняющую значения
// двух целых чисел. Проверьте функуцию, вызвав ее и отобразив измененные
// значения.

void reset(int* a, int* b) {
  *a = 0;
  *b = 0;
}

int main() {
  int a = 5;
  int b = 10;
  std::cout << a << " " << b << std::endl;
  reset(&a, &b);
  std::cout << a << " " << b << std::endl;
}