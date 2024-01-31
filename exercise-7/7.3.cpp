#include <iostream>

#include "Sales_data2.h"

// Упражнение 7.3. Пересмотрите свою программу обработки транзакций из
// раздела 7.1.1 (стр. 333) так, чтобы использовать эти функции-члены.

int main() {
  Sales_data total;
  double price;

  if (std::cin >> total.bookNo >> total.units_sold >> price) {
    total.revenue = total.units_sold * price;

    Sales_data trans;

    while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
      trans.revenue = trans.units_sold * price;

      if (total.isbn() == trans.isbn()) {
        total.combine(trans);  // Сократились две длинные строки в одну.
      } else {
        std::cout << total.isbn() << " " << total.units_sold << " "
                  << total.revenue << " " << std::endl;

        total.bookNo = trans.bookNo;
        total.units_sold = trans.units_sold;
        total.revenue = trans.revenue;
      }
    }
    std::cout << total.isbn() << " " << total.units_sold << " " << total.revenue
              << " " << std::endl;
  } else {
    std::cerr << "No data?!" << std::endl;
    return -1;
  }

  return 0;
}