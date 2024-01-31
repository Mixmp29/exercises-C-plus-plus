#include <iostream>
#include <vector>

// Упражнение 3.14. Напишите программу, читающую последовательность целых чисел
// из потока cin и сохраняющую их в векторе.

int main() {
  int val;
  std::vector<int> vec;

  while (std::cin >> val) {
    vec.push_back(val);
  }

  std::cout << "-------------" << std::endl;

  for (const auto &v : vec) {
    std::cout << v << std::endl;
  }
}