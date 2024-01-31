#include <initializer_list>
#include <iostream>

// Упражнение 6.27. Напишите функцию, получающую параметр типа
// initializer_list<int> и возвращающую сумму элементов списка.

int sumArgs(std::initializer_list<int> list) {
  int result = 0;

  for (int elem : list) {
    result += elem;
  }

  return result;
}

int main() { std::cout << sumArgs({5, 10, 15, 20}) << std::endl; }