#include <iostream>

#include "Sales_item.h"

// Упражнение 1.21. Напишите программу, которая читает два объекта класса
// Sales_item с одинаковыми ISBN и вычисляет их сумму.
int main() {
  Sales_item item1, item2;
  std::cin >> item1;
  while (std::cin >> item2 && item1.isbn() != item2.isbn()) {
    std::cout << "Input same ISBN" << std::endl;
  }
  std::cout << item1 + item2 << std::endl;
}