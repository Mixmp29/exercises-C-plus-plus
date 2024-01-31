#include <iostream>

// Упражнение 4.5. Определите результат следующих выражений:

int main() {
  int var1 = -30 * 3 + 21 / 5;  // -86
  int var2 = -30 + 3 * 21 / 5;  // -18
  int var3 = 30 / 3 * 21 % 5;   // 0
  int var4 = -30 / 3 * 21 % 4;  // -2

  std::cout << var1 << std::endl;
  std::cout << var2 << std::endl;
  std::cout << var3 << std::endl;
  std::cout << var4 << std::endl;
}