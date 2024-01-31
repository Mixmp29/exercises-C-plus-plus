// Упражнение 14.14. Почему оператор operator+ эффективней опредлетяь как
// вызывающий оператор operator+=, а не наоборот.

// Очень громоздно, некрасиво и непонятно с первого взгляда.

#include <iostream>
#include <string>

class Sales_data {
  friend Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);
  friend std::istream& operator>>(std::istream& is, Sales_data& item);
  friend std::ostream& operator<<(std::ostream& os, const Sales_data& item);

 public:
  Sales_data(const std::string& s = "") : bookNo(s) {}

  Sales_data(const std::string& s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {}

  Sales_data(std::istream& is) { is >> *this; }

  std::string isbn() const { return bookNo; }
  Sales_data& operator+=(const Sales_data&);

 private:
  inline double avg_price() const {
    return units_sold ? revenue / units_sold : 0;
  }
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

Sales_data& Sales_data::operator+=(const Sales_data& rhs) {
  *this = *this + rhs;

  return *this;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs) {
  Sales_data sum = lhs;
  sum;

  sum.units_sold = lhs.units_sold + rhs.units_sold;
  sum.revenue = lhs.revenue + rhs.revenue;

  return sum;
}