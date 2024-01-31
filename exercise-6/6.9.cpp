#include <iostream>

#include "6.8.hpp"

// Упражнение 6.9. Напишите собственные версии файлов fact.cc и Main.cc
// (6.9.cpp). Эти файлы должны включать заголовок Chapter6.h (6.8.hpp) из
// упражнение предыдущего раздела. Используйте эти файлы чтобы понять, как ваш
// компилятор обеспечивает раздельную компиляцию.

int main() {
  int v;

  std::cout
      << "Enter the number that will be used to calculate the factorial: ";
  std::cin >> v;

  std::cout << "The factorial of " << v << " is " << fact(v) << std::endl;

  /* В моем случае, если не вдаваться в подробности, поддерживаются нескольок
  вариантов:

  g++ 6.9.cpp fact.cpp -o 6.9

  g++ -o 6.9 6.9.cpp fact.cpp

  g++ -c 6.9.cpp
  g++ -c fact.cpp
  g++ 6.9.o fact.o -o 6.9
  */
}