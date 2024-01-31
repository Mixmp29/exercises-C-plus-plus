// Упражнение 7.2. Добавьте функции-члены combine() и isbn() в класс Sales_data,
// который был написан для упражнений из раздела 2.6.2 (стр. 116).

// Буду писать версию класса для этого задания здесь и вносить изменения в файл
// Sales_data2.h.

#ifndef SALES_DATA2_H
#define SALES_DATA2_H

#include <string>

struct Sales_data {
  // std::string isbn() const { return (*this).bookNo; } // Эквивалентные
  // std::string isbn() const { return this->bookNo; } // определения.
  std::string isbn() const { return bookNo; }
  Sales_data& combine(const Sales_data&);

  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data& rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;

  return *this;
}

#endif