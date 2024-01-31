// Упражнение 10.34. Используйте итератор reverse_iterator для вывода
// содержимого вектора в обратном порядке.

#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto rbegin = vec.rbegin();
  auto rend = vec.rend();
  while (rbegin != rend) std::cout << *rbegin++ << " ";
  std::cout << std::endl;
}