#include <iostream>

int main() {
  // Упражнение 1.12. Что делает следующий цикл for? - считает сумму от -100 до
  // 100 включительно.
  // Каково будет финальное значение переменной sum? - ответом будет 0.
  int sum = 0;

  for (int val = -100; val <= 100; ++val) {
    std::cout << (sum += val) << std::endl;
  }
}