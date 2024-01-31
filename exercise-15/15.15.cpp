// Упражнение 15.15. Определите собственные версии классов Disc_quote и
// Bulk_quote.

#include <iostream>
#include <string>

class Quote {
 public:
  Quote() = default;
  Quote(const std::string &book, double sales_price)
      : bookNo(book), price(sales_price) {}

  std::string isbn() const { return bookNo; }
  virtual double net_price(std::size_t n) const { return n * price; }

  virtual ~Quote() = default;

 private:
  std::string bookNo;

 protected:
  double price = 0.0;
};

class Disc_quote : public Quote {
 public:
  Disc_quote() = default;
  Disc_quote(const std::string &book, double p, std::size_t qty, double disc)
      : Quote(book, p), quantity(qty), discount(disc) {}

  double net_price(std::size_t cnt) const = 0;

 protected:
  std::size_t quantity = 0;
  double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
 public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double p, std::size_t qty, double disc)
      : Disc_quote(book, p, qty, disc) {}

  double net_price(std::size_t cnt) const override {
    if (cnt >= quantity)
      return cnt * (1 - discount) * price;
    else
      return cnt * price;
  }
};

/* class Bulk_quote : public Disc_quote {
 public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double p, std::size_t qty, double disc)
      : Disc_quote(book, p, qty, disc) {}

  double net_price(std::size_t cnt) const override {
    if (cnt < quantity)  // Достаточно поменять условие.
      return cnt * (1 - discount) * price;
    else
      return cnt * price;
  }
}; */