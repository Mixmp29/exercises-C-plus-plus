#ifndef SALES_DATA4_H
#define SALES_DATA4_H

#include <iostream>
#include <string>

class Sales_data {
  // 14.20
  friend Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);
  friend std::istream& operator>>(std::istream& is, Sales_data& item);
  friend std::ostream& operator<<(std::ostream& os, const Sales_data& item);

 public:
  Sales_data(const std::string& s = "") : bookNo(s) {}

  Sales_data(const std::string& s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {}

  Sales_data(std::istream& is) { is >> *this; }

  std::string isbn() const { return bookNo; }

  // 14.22
  Sales_data& operator=(const std::string& rhs);
  Sales_data& operator+=(const Sales_data&);

  // 14.45 и 14.46
  operator std::string() const { return bookNo; }
  operator double() const { return revenue; }

 private:
  inline double avg_price() const {
    return units_sold ? revenue / units_sold : 0;
  }
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

// 14.22
Sales_data& Sales_data::operator=(const std::string& rhs) {
  bookNo = rhs;

  return *this;
}

// 14.20
Sales_data& Sales_data::operator+=(const Sales_data& rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;

  return *this;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs) {
  Sales_data sum = lhs;
  sum += rhs;

  return sum;
}

std::istream& operator>>(std::istream& is, Sales_data& item) {
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;

  return is;
}

std::ostream& operator<<(std::ostream& os, const Sales_data& item) {
  os << item.isbn() << " " << item.units_sold << " " << item.revenue;

  return os;
}

#endif