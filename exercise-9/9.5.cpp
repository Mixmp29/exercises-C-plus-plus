// Упражнение 9.5. Перепишите предыдущую программу так, чтобы она возвращала
// итератор на найденный элементю функция должны учитывать случай, когда элемент
// не найден.

#include <iostream>
#include <vector>

using iterator = std::vector<int>::iterator;

iterator search(iterator begin, iterator end, int val) {
  while (begin != end) {
    if (val == *begin) return begin;
    ++begin;
  }

  return begin;  // Если элемент не найден, то возвращает end.
}

int main() {
  std::vector<int> vec = {4, 6, 5, 12, 33, 123, 5, 63, 1};
  auto iter = search(vec.begin(), vec.end(), 123);

  if (iter != vec.end())
    std::cout << *iter << std::endl;
  else
    std::cout << "Could not find the value in the swquence" << std::endl;
}