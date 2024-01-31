#include <iostream>

// Упражнение 4.26. Что будет, если в приведенном выше примере оценки учеников
// использовать для переменной quiz1 тип unsigned int?

/* Использованный тип unsigned long имеет 64 бит, то есть для поставленной
 * задачи этот тип был взят с большим запасом, можно добавить еще 34 участника.
 * Тип unsigned int имеет 32 бита. Для задачи необходимо 30 учеников.
 * Количества битов хватает для ее решения. */

int main() {
  unsigned int quiz1 = 0;
  bool status;

  quiz1 |= 1UL << 27;
  status = quiz1 & (1UL << 27);
  std::cout << status << std::endl;

  quiz1 &= ~(1UL << 27);
  status = quiz1 & (1UL << 27);
  std::cout << status << std::endl;
}