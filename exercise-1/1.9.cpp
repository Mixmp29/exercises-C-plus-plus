#include <iostream>

int main() {
    // Упражнение 1.9. Напишите программу, которая использует цикл while
  // для суммирования чисел от 50 до 100.
  int sum = 0, val = 50;

  while (val < 100) {
    std::cout << sum << " + " << val << " = " << (sum += val) << std::endl;
    ++val;
  }

  std::cout << "Sum of 1 to 10 isclusive is " << sum << std::endl;
}