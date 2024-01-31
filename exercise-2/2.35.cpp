#include <iostream>
#include <typeinfo>

// Упражнение 2.35. Укажите типы, выведенные в каждом из следующих определений.
// Затем напишите программу, чтобы убедиться в своей правоте.

int main() {
  const int i = 42;
  auto j = i;  // int j. Верхний уровень константы откидывается.
  const auto &k = i;  // const int &k. Можно обойтись без const, просто будет
                      // явное объявление с этим типом.
  auto *p = &i;  // const int *p. Верхние константы адресов откидываются. Нижние
                 // значений должы совпадать.

  const auto j2 = i,  // const int j
      &k2 = i;        // const int k2;

  std::cout << typeid(i).name() << std::endl;
  std::cout << typeid(j).name() << std::endl;
  std::cout << typeid(k).name() << std::endl;
  std::cout << typeid(p).name() << std::endl;
  std::cout << typeid(j2).name() << std::endl;
  std::cout << typeid(k2).name() << std::endl;

  // Как я понял в зависимости от компилятора выведет либо подробно, либо
  // сокращенно. В VS code достаточно навестись на переменную длд определения
  // типа переменной.
}