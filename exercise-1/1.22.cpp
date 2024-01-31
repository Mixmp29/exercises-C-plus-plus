#include <iostream>

#include "Sales_item.h"

// Упражнение 1.22. Напишите программу, читающую несколько транзакций с
// одинаковым ISBN и отображающую сумму всех прочитанных транзакций.
int main() {
  Sales_item item1, item2;

  std::cin >> item1;

  while (std::cin >> item2) {
    if (item1.isbn() != item2.isbn()) {
      std::cout << "Input same ISBN" << std::endl;
    } else {
      item1 += item2;
    }
  }

  std::cout << item1 << std::endl;

  return 0;
}