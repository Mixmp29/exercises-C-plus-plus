// Упражнение 15.6. Проверьте свою функцию print_total() из упражнения 15.2.1
// (стр. 752), передав ей объекты класса Quote и Bulk_quote.

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

class Bulk_quote : public Quote {
 public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double p, std::size_t qty, double disc)
      : Quote(book, p), min_qty(qty), discount(disc) {}

  double net_price(std::size_t cnt) const override {
    if (cnt >= min_qty)
      return cnt * (1 - discount) * price;
    else
      return cnt * price;
  }

 private:
  std::size_t min_qty = 0;
  double discount = 0.0;
};

double print_total(std::ostream &os, const Quote &item, size_t n) {
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret
     << std::endl;
  return ret;
}

int main() {
  Quote quote("book1", 10);
  Bulk_quote bulk_quote("book2", 10, 5, 0.1);  // 10% скидка.
  print_total(std::cout, quote, 3);
  print_total(std::cout, quote, 6);
  print_total(std::cout, bulk_quote, 3);
  print_total(std::cout, bulk_quote, 6);
}