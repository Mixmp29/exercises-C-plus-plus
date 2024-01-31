#include <iostream>
#include <vector>

// Упражнение 3.32. Скопируйте массив, определенный в предыдущем упражнении, в
// другой массив. Перезапишите эту программу так, чтобы использовались векторы.

int main() {
  int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  // int arr2[10] = arr; Так делать нельзя. Можно сделать указатль или ссылку на
  // этот массив, но это будет работа с последовательностью arr, а не arr2.
  int arr2[10];

  for (size_t i = 0; i < 10; ++i) {
    arr2[i] = arr[i];
  }

  for (int elem : arr2) {
    std::cout << elem << std::endl;
  }

  std::cout << "-----------------" << std::endl;

  std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> vec2 = vec;  // Инициализация vec2 копированием
                                // за счет вектора vec.

  for (int elem : vec2) {
    std::cout << elem << std::endl;
  }
}