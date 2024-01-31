#include <iostream>

// Упражнение 6.38. Перепешите функцию arrPtr() так, чтобы она возвращала ссылку
// на массив.

int odd[] = {1, 3, 5, 7, 9};

decltype(odd) &arrPtr() { return odd; }

int main() {
  for (int i = 0; i < 5; ++i) {
    std::cout << arrPtr()[i] << std::endl;
  }
}