#include <iostream>

int main() {
  // Cуммирование чисел от 1 до 10 включительно.
  int sum = 0, val = 1;

  while (val <= 10) {
    std::cout << sum << " + " << val << " = " << (sum += val) << std::endl;
    ++val;
  }
}