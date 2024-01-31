#include <iostream>

// Упражнение 4.10. Напишите условие цикла while, оторый читал бы целые числа со
// стандартного устройства ввода, пока во вводе не встретится значение 42.

int main() {
  int val;

  while (std::cin >> val && val != 42) {
    std::cout << "Input: " << val << std::endl;
  }

  std::cout << "The End" << std::endl;
}