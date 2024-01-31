#include <iostream>

#include "Sales_data2.h"

// Упражнение 7.13. Перепишиту программу со стр. 333 так, чтобы использовать
// конструктор с параметром istream.

// Не знаю зачем, но пожалуйста.

int main() {
  Sales_data total(std::cin);

  if (std::cin) {
    while (std::cin) {
      Sales_data trans(std::cin);
      if (total.isbn() == trans.isbn())
        total.combine(trans);
      else {
        print(std::cout, total) << std::endl;
        total = trans;
      }
    }
    // тут print() даже не понадобился, так как при некорректном вводе или конце
    // файла алгоритм while продолжится до конца блока.
  } else {
    std::cerr << "No data!?" << std::endl;
  }
}