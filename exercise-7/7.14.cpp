// Упражнение 7.14. Напишите версию стандартного конструктора, явно
// инициализирующую переменные-члены значениями, предоставленными
// внутриклассовыми инициализаторами.

#ifndef SALES_DATA2_H
#define SALES_DATA2_H

#include <iostream>
#include <string>

struct Sales_data {
  // Переопределение инициализации.
  Sales_data() : bookNo(""), units_sold(0), revenue(0) {}

  Sales_data(const std::string& s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {}

  Sales_data(const std::string& s) : bookNo(s) {}

  Sales_data(std::istream& is) {
    double price = 0;
    is >> this->bookNo >> this->units_sold >> price;
    this->revenue = price * this->units_sold;
  }

  std::string isbn() const { return bookNo; }
  Sales_data& combine(const Sales_data&);

  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

#endif