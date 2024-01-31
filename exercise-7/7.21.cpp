#include <iostream>

#include "Sales_data3.h"

// Упражнение 7.21. Измените свой класс Sales_data так, чтобы скрыть его
// реализацию. Написанные вами программы, которые использовали операции класса
// Sales_data, должны продолжить работать. Перекомпилируйте эти программы с
// новым определением класса, чтобы проверить, остались ли они работоспособными.

// Новое определение будет в Sales_data3.h

int main() {
  Sales_data total;

  if (read(std::cin, total)) {
    Sales_data trans;

    while (read(std::cin, trans)) {
      if (total.isbn() == trans.isbn())
        total.combine(trans);
      else {
        print(std::cout, total) << std::endl;
        total = trans;
      }
    }
    print(std::cout, total) << std::endl;
  } else {
    std::cerr << "No data!?" << std::endl;
  }
}