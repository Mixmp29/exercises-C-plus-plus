#include <iostream>

// Упражнение 4.36. С учетом того, что i имеет тип int, а d - doublue, напишите
// выражение i *= d так, чтобы осуществлялось целочисленное умножение, а не с
// плавающей запятой.

int main() {
  int i = 2;
  double d = 3.5;
  std::cout << (i *= static_cast<int>(d)) << std::endl;
}