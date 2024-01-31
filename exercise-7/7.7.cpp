#include <iostream>

#include "Sales_data2.h"

// Упражнение 7.7. Перепишите программу обработки транзакций, написанной для
// упражнений в разделе 7.1.2 (стр. 339), так, чтобы использовать эти новые
// функции.

// Очень приятно удалять здоровые куски кода.

int main() {
  Sales_data total;

  if (read(std::cin, total)) {
    Sales_data trans;

    while (read(std::cin, trans)) {
      if (total.isbn() == trans.isbn()) {
        total.combine(trans);
      } else {
        print(std::cout, total);

        // Еще бы эту сократить потом...
        /* total.bookNo = trans.bookNo;
        total.units_sold = trans.units_sold;
        total.revenue = trans.revenue; */

        // Оказывается можно сразу. Чуть позже по книге объяснят как это
        // работает.
        total = trans;
      }
    }
    print(std::cout, total);
  } else {
    std::cerr << "No data?!" << std::endl;
    return -1;
  }

  return 0;
}