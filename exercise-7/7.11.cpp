#include <iostream>

#include "Sales_data2.h"

// Упражнение 7.11. Добавьте в класс Sales_data конструкторы и напишите
// программу, использующую каждый из них.

/* struct Sales_data {
  #1
  Sales_data() = default;
  // Поведение синтезируемого стандартного конструктора.

  #2
  Sales_data(const std::string& s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {}

  #3
  Sales_data(const std::string& s) : bookNo(s) {}

  #4
  Sales_data(std::istream& is);

  std::string isbn() const { return bookNo; }
  Sales_data& combine(const Sales_data&);

  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

Sales_data::Sales_data(std::istream& is) { read(is, *this); } */

int main() {
  Sales_data total1;  // #1. Стандартный конструктор.
  Sales_data total2("0-201-78345-X");          // #3
  Sales_data total3("0-201-78345-X", 10, 25);  // #2
  Sales_data total4(std::cin);

  // Кстати, так нельзя делать. Эквивалентно std::cout << std::cout;. У cout
  // попросту не предусмотрено поведения при std::ostream << std::ostream.
  // std::cout << print(std::cout, total1) << std::endl;

  // А так можно
  print(std::cout, total1) << std::endl;
  print(std::cout, total2) << std::endl;
  print(std::cout, total3) << std::endl;
  print(std::cout, total4) << std::endl;
}