#include <iostream>

// Упражнение 3.38. В этом разделе упоминалось, что не только некорректно, но и
// бессмысленно пытаться сложить два указателя. Почему сложение двух указателей
// бессмысленно?

/* Как минимум в языке не существует установленного поведения указателей через
 * оператор '+'. Можно и дальше начать дискутировать, почему оно может быть
 * бессмысленно, но думаю этого факта должно быть достаточно.*/

int main() {
  int array[] = {1, 2, 3, 4, 5};
  int *p1 = array;
  int *p2 = array + 3;

  std::cout << p1 + p2 << std::endl;  // Компилятор заругается и попросит здесь
                                      // вторым операндом целочисленное число.
}