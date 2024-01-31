#include <iostream>

#include "Sales_data.h"

// Упражнение 7.1. Напишите версию программы обработки транзакций из раздела 1.6
// (стр. 52) с использованием класса Sales_data, созданного для упражнений в
// разделе 2.6.1 (стр. 112).

// Что-то такое уже было в 2.41.

int main() {
  Sales_data total;
  double price;

  if (std::cin >> total.bookNo >> total.units_sold >> price) {
    total.revenue = total.units_sold * price;

    Sales_data trans;

    while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
      trans.revenue = trans.units_sold * price;

      if (total.bookNo == trans.bookNo) {
        total.units_sold += trans.units_sold;
        total.revenue += trans.revenue;
      } else {
        std::cout << total.bookNo << " " << total.units_sold << " "
                  << total.revenue << " " << std::endl;

        total.bookNo = trans.bookNo;
        total.units_sold = trans.units_sold;
        total.revenue = trans.revenue;
      }
    }
    std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue
              << " " << std::endl;
  } else {
    std::cerr << "No data?!" << std::endl;
    return -1;
  }

  return 0;
}