#include <iostream>

// Упражнение 2.41. Используйте класс Sales_data для перезаписи кода упражнений
// из разделов 1.5.1 (стр. 50), 1.5.2 (стр. 52) и 1.6 (стр. 54). А также
// определите свой класс Sales_data в том же файле, что и функция main().

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

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