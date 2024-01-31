// Упражнение 10.37. С учетом того, что вектор содержит 10 элементов, скопируйте
// в список диапазон его элементов от позиции 3 до позиции 7 в обратном порядке.

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

int main() {
  std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  // Если считать позиции от 0.
  std::list<int> list(vec.rbegin() + 2, vec.rend() - 3);

  for (auto elem : list) std::cout << elem << " ";
  std::cout << std::endl;
}