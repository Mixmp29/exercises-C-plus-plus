#include <iostream>

int main() {
  // Упражнение 1.11. Напишите программу, которая запрашивает у пользователя два
  // целых числа, а затем отображет каждое число в диапазоне, определенном этими
  // двумя числами.

  int left, right;

  std::cin >> left >> right;

  while (left <= right) {
    std::cout << left++ << std::endl;
  }
}