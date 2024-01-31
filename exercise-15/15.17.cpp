// Упражнение 15.17. Попытайтесь определить объект типа Disc_quote и посмотрите,
// какие сообщения об ошибке выдал компилятор.

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

class Limited_Bulk_quote : public Disc_quote {
 public:
  Limited_Bulk_quote() = default;
  Limited_Bulk_quote(const std::string &book, double p, std::size_t qty,
                     double disc)
      : Disc_quote(book, p, qty, disc) {}

  double net_price(std::size_t cnt) const override {
    if (cnt < quantity)
      return cnt * (1 - discount) * price;
    else
      return cnt * price;
  }
};

double print_total(std::ostream &os, const Quote &item, size_t n) {
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret
     << std::endl;
  return ret;
}

int main() {
  Quote quote("book1", 10);

  // Disc_quote obj;
  // Ошибка компилятора выдает следующее: error: нельзя объявить переменную
  // 'obj' абстрактного типа Disc_quote, потому что следующие виртуальные
  // фукнции являются чистыми внутри Disc_quote: далее идет перечисление...

  Bulk_quote bulk_quote("book2", 10, 5, 0.1);           // 10% скидка.
  Limited_Bulk_quote limit_quote("book2", 10, 5, 0.1);  // 10% скидка.
  print_total(std::cout, quote, 3);
  print_total(std::cout, quote, 6);
  print_total(std::cout, bulk_quote, 3);
  print_total(std::cout, bulk_quote, 6);
  print_total(std::cout, limit_quote, 3);
  print_total(std::cout, limit_quote, 6);
}