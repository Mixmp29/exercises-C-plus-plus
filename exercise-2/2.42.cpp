#include <iostream>

#include "Sales_data.h"

// Упражнение 2.42. Напишите собственную версию заголовка Sales_data.h и
// используйте его для новой версии упражнения из раздела 2.6.2 (стр. 116).

int main() {
  Sales_data data1, data2;
  double price;

  std::cin >> data1.bookNo >> data1.units_sold >> price;
  data1.revenue = data1.units_sold * price;

  std::cin >> data2.bookNo >> data2.units_sold >> price;
  data2.revenue = data2.units_sold * price;

  if (data1.bookNo == data2.bookNo) {
    unsigned totalCnt = data1.units_sold + data2.units_sold;
    double totalRevenue = data1.revenue + data2.revenue;

    std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";

    if (totalCnt != 0) {
      std::cout << totalRevenue / totalCnt << std::endl;
    } else {
      std::cout << "(no sales)" << std::endl;
    }
  } else {
    std::cerr << "Data must refer to the same ISBN" << std::endl;
    return -1;
  }
}