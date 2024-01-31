#include <iostream>
#include <vector>

// Упражнение 3.42. Напишите программу, копирующую вектор целых чисел в массив
// целых чисел.

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  int arr[vec.size()];

  for (unsigned i = 0; i < vec.size();
       ++i) {  // Нет простого способа копирования последовательностей в массив,
               // если это только не string.
    arr[i] = vec[i];

    std::cout << arr[i] << std::endl;
  }
}