// Упражнение 10.36. Используйте функцию find() для поиска в списке целых чисел
// последнего элемента со значением 0.

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec = {1, 2, 0, 4, 2, 0, 1, 3, 7, 0, 2, 9};
  // Возвратит реверсивный итератор.
  auto zero = std::find(vec.rbegin(), vec.rend(), 0);
  std::cout << "Last zero position in vector: " << zero.base() - vec.begin() - 1
            << std::endl;
}