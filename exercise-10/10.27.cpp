// Упражнение 10.27. В дополнение к функции unique() (ст. раздел 10.2.3, стр.
// 492) библиотека определяет функцию unique_copy(), получающую третий итератор,
// обозначающий назначение копирования уникальных элементов. Напишите программу,
// которая использует unique_copy() для копирования уникальных элементов вектора
// в первоначально пустой список.

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

int main() {
  std::vector<int> vec = {1, 2, 2, 3, 3, 4};
  std::list<int> list;
  std::unique_copy(vec.begin(), vec.end(), std::back_inserter(list));

  for (auto elem : list) std::cout << elem << " ";
  std::cout << std::endl;
}