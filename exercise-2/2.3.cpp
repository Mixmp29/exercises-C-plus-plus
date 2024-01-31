#include <iostream>

// Упражнение 2.3-2.4. Каков будет вывод следующего кода?
int main() {
  unsigned u = 10, u2 = 42;
  std::cout << u2 - u << std::endl;  // 32
  std::cout << u - u2 << std::endl;  // здоровое число

  int i = 10, i2 = 42;
  std::cout << i2 - i << std::endl;  // 32
  std::cout << i - i2 << std::endl;  // -32
  std::cout << i - u << std::endl;   // 0
  std::cout << u - i << std::endl;   // 0
}