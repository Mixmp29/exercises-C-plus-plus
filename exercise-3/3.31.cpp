#include <iostream>

// Упражнение 3.31. Напишите программу, где определен массив из десяти целых
// чисел, каждому элементу которого присовено значение, соответстсвующее его
// позиции в массиве.

int main() {
  int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  std::cout << arr[0] << std::endl;
  std::cout << arr[1] << std::endl;
  std::cout << arr[2] << std::endl;
  std::cout << arr[3] << std::endl;
  std::cout << arr[4] << std::endl;
  std::cout << arr[5] << std::endl;
  std::cout << arr[6] << std::endl;
  std::cout << arr[7] << std::endl;
  std::cout << arr[8] << std::endl;
  std::cout << arr[9] << std::endl;
}