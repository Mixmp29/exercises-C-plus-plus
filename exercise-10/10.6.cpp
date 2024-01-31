// Упражнение 10.6. Напишите программу, использующую функцию fill_n() для
// обнуления последовательности целых чисел.

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5};

  std::fill_n(vec.begin(), vec.size(), 0);

  for (auto elem : vec) std::cout << elem << " ";
  std::cout << std::endl;
}