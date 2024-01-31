#include <iostream>
#include <vector>

// Упражнение 4.21. Напишите программу, использующую условный оператор для
// поиска в векторе vector<int> элементов с нечетным значением и их удвоения.

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  for (auto& iter : vec) {
    iter = (iter % 2 == 0) ? iter : iter * 2;
    std::cout << iter << std::endl;
  }
}