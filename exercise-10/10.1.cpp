// Упражнение 10.1. В заголовке algorithm определена функция count(), подобная
// функции find(). Она получает два итератора и значение, а возвращает
// количество обнаруженных в диапазоне элементов, обладающих искомым значением.
// Организуйте чтение в вектор последовательности целых чисел. Осуществите
// подсчет элементов с указанным значением элементов.

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec;
  int val;
  while (std::cin >> val) vec.push_back(val);

  auto result = std::count(vec.begin(), vec.end(), 15);

  std::cout << "Count of elements in vector: " << result << std::endl;
}