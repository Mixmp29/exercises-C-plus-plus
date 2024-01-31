#include <iostream>

// Упражнение 4.6. Напишите выражение, чтобы определить, является ли значение
// типа int четным или нечетным.

int main() {
  int n;

  while (std::cin >> n) {
    if (n % 2 == 0)
      std::cout << "Четное" << std::endl;
    else
      std::cout << "Нечетное" << std::endl;
  }
}