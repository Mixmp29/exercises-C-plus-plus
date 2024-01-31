// Упражнение 10.35. Теперь отобразите элементы в обратном порядке, используя
// обычные итераторы.

#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto begin = vec.begin() - 1;
  auto end = vec.end() - 1;
  while (begin != end) std::cout << *end-- << " ";
  std::cout << std::endl;
}