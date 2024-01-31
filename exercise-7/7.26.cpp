// Упражнение 7.26. Определите функцию Sales_data::avg_price как встраиваемую.

#include <iostream>

class Sales_data {
  friend Sales_data add(const Sales_data& lhs, const Sales_data& rhs);
  friend std::istream& read(std::istream& is, Sales_data& item);
  friend std::ostream& print(std::ostream& os, const Sales_data& item);

 public:
  Sales_data() = default;

  Sales_data(const std::string& s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {}

  Sales_data(const std::string& s) : bookNo(s) {}

  Sales_data(std::istream& is) {
    double price = 0;
    is >> bookNo >> units_sold >> price;
    revenue = price * units_sold;
  }

  std::string isbn() const { return bookNo; }
  Sales_data& combine(const Sales_data&);

 private:
  inline double avg_price()
      const {  // Явное определение встраиваемой функции.
               // Без inline определение было бы инквивалентным. Только это
               // должно быть именно определение.
    return units_sold ? revenue / units_sold : 0;
  }
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};