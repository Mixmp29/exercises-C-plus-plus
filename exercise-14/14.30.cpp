// Упражнение 14.30. Добавьте операторы обращения к значению и стрелки в класс
// StrBlobPtr и класс ConstStrBlobPtr из упражнения 12.22 раздела 12.1.6 (стр.
// 606). Обратите внимание, что операторы класса ConstStrBlobPtr должны
// возвращать константные ссылки, поскольку переменная-член data класса
// ConstStrBlobPtr указывает на константный вектор.

// Вот тут надо повнимательнее со стрелкой '->'. Сама фукнция перегрузки просто
// возвращает указатель на элемент вектора. Однако под капотом проводится еще
// дополнительная операция со встроенным оператором '->'.

#include <iostream>

#include "StrBlob.h"

int main() {
  StrBlob a1 = {"hi", "bye", "now"};
  StrBlobPtr p(a1);
  *p = "okey";
  std::cout << p->size() << std::endl;  // Эквивалентно (p.operator->())->size()
  std::cout << (*p).size() << std::endl;
}