#include "Sales_data3.h"

// Упражнение 7.38. Конструктору, получающему аргумент типа istream&, можно
// предоставить объект cin как аргумент по умолчанию. Напишите объявление
// конструктора, использующего объект cin как аргумент по умолчанию.

// В таком случае нужно убрать аргумент по умолчанию в
// Sales_data(const std::string& s = ""), иначе будет два стандартных
// конструктора.

/* #include <iostream>
#include <string>
class Sales_data {
 // ...
  Sales_data(const std::string& s) : bookNo(s) {}

  Sales_data(const std::string& s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {}

  Sales_data(std::istream& is = std::cin) {
    double price = 0;
    is >> bookNo >> units_sold >> price;
    revenue = price * units_sold;
  }
 // ...
}; */

int main() {
  Sales_data item;
  print(std::cout, item) << std::endl;
}