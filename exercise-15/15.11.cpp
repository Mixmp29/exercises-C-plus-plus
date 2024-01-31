// Упражнение 15.11. Добавьте в иерархию класса Quote виртуальную функцию
// debug(), отображающую переменные-члены соответствующих классов.

#include <iostream>
#include <string>

class Quote {
 public:
  Quote() = default;
  Quote(const std::string &book, double sales_price)
      : bookNo(book), price(sales_price) {}

  std::string isbn() const { return bookNo; }
  virtual double net_price(std::size_t n) const { return n * price; }
  virtual void debug() {
    std::cout << "class Quote:";
    std::cout << "\t" << bookNo << std::endl;
    std::cout << "\t" << price << std::endl;
  }

  virtual ~Quote() = default;

 private:
  std::string bookNo;

 protected:
  double price = 0.0;
};

class Bulk_quote : public Quote {
 public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double p, std::size_t qty, double disc)
      : Quote(book, p), min_qty(qty), discount(disc) {}

  double net_price(std::size_t cnt) const override {
    if (cnt < min_qty)  // Достаточно поменять условие.
      return cnt * (1 - discount) * price;
    else
      return cnt * price;
  }
  void debug() override {
    std::cout << "class Quote:";
    std::cout << "\t" << isbn() << std::endl;
    std::cout << "\t" << price << std::endl;
    std::cout << "\t" << min_qty << std::endl;
    std::cout << "\t" << discount << std::endl;
  }

 private:
  std::size_t min_qty = 0;
  double discount = 0.0;
};