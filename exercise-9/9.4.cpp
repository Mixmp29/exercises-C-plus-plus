// Упражнение 9.4. Напишите функцию, которая получает два итератора вектора
// vector<int> и значение типа int. Организуйте поиск этого значения в диапазоне
// и возвратите логическое значение (тип bool), указывающее, что значение
// найдено.

#include <iostream>
#include <vector>

using iterator = std::vector<int>::iterator;

bool search(iterator begin, iterator end, int val) {
  while (begin != end) {
    if (val == *begin) return true;
    ++begin;
  }

  return false;
}

int main() {
  std::vector<int> vec = {4, 6, 5, 12, 33, 123, 5, 63, 1};
  std::cout << search(vec.begin(), vec.end(), 123) << std::endl;
}