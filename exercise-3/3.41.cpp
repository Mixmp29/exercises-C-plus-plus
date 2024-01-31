#include <iostream>
#include <iterator>  // Библиотека где определены begin() и end()
#include <vector>

// Упражнение 3.41. Напишите программу, инициализирующую вектор значениями из
// массива целых чисел.

int main() {
  int array[] = {1, 2, 3, 4, 5};
  std::vector<int> vector(
      array, std::end(array));  // В прямую инициализацию подаются аргументы
                                // адреса первого элемента и адреса за последним
                                // элементом копируемого массива.

  for (auto elem : vector) {
    std::cout << elem << std::endl;
  }
}