// Упражнение 15.26. Определите для классов Quote и Bulk_quote функции-члены
// управления копированием, осуществляющие те же действия, что и синтезируемые
// версии. Снабдите их и другие конструкторы операторами вывода,
// идентифицирующими выполняемую функцию. Напишите программу с использованием
// этих классов и укажите, какие объекты будут созданы и удалены. Сравните свои
// предположения с выводом и продолжите экспериментировать, пока ваши
// предположения не станут правильными.

#include <iostream>
#include <string>

class Quote {
 public:
  Quote() { std::cout << "Quote()" << std::endl; }
  Quote(const std::string &book, double sales_price)
      : bookNo(book), price(sales_price) {
    std::cout << "Quote(const std::string &book, double sales_price)"
              << std::endl;
  }
  Quote(const Quote &rhs) : price(rhs.price) {
    std::cout << "Quote(const Quote &rhs)" << std::endl;
  }
  Quote(Quote &&rhs) : price(rhs.price) {
    std::cout << "Quote(Quote &&rhs)" << std::endl;
  }
  Quote &operator=(const Quote &rhs) {
    std::cout << "Quote &operator=(const Quote &rhs)" << std::endl;
    price = rhs.price;
    return *this;
  }
  Quote &operator=(Quote &&rhs) {
    std::cout << "Quote &operator=(Quote &&rhs)" << std::endl;
    price = rhs.price;
    return *this;
  }
  virtual ~Quote() { std::cout << "~Quote()" << std::endl; }

  std::string isbn() const { return bookNo; }
  virtual double net_price(std::size_t n) const { return n * price; }

 private:
  std::string bookNo;

 protected:
  double price = 0.0;
};

class Disc_quote : public Quote {
 public:
  Disc_quote() { std::cout << "Disc_quote()" << std::endl; }
  Disc_quote(const std::string &book, double p, std::size_t qty, double disc)
      : Quote(book, p), quantity(qty), discount(disc) {
    std::cout << "Disc_quote(const std::string &book, double p, std::size_t "
                 "qty, double disc)"
              << std::endl;
  }
  Disc_quote(const Disc_quote &rhs)
      : Quote(rhs), quantity(rhs.quantity), discount(rhs.discount) {
    std::cout << "Disc_quote(const Disc_quote &rhs)" << std::endl;
  }
  Disc_quote(Disc_quote &&rhs)
      : Quote(std::move(rhs)), quantity(rhs.quantity), discount(rhs.discount) {
    std::cout << "Disc_quote(Disc_quote &&rhs)" << std::endl;
  }
  Disc_quote &operator=(const Disc_quote &rhs) {
    std::cout << "Disc_quote &operator=(const Disc_quote &rhs)" << std::endl;
    Quote::operator=(rhs);
    quantity = rhs.quantity;
    discount = rhs.discount;
    return *this;
  }
  Disc_quote &operator=(Disc_quote &&rhs) {
    std::cout << "Disc_quote &operator=(Disc_quote &&rhs)" << std::endl;
    Quote::operator=(std::move(rhs));
    quantity = rhs.quantity;
    discount = rhs.discount;
    return *this;
  }

  virtual ~Disc_quote() { std::cout << "~Disc_quote()" << std::endl; }

  double net_price(std::size_t cnt) const = 0;

 protected:
  std::size_t quantity = 0;
  double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
 public:
  Bulk_quote() { std::cout << "Bulk_quote()" << std::endl; }
  Bulk_quote(const std::string &book, double p, std::size_t qty, double disc)
      : Disc_quote(book, p, qty, disc) {
    std::cout << "Bulk_quote(const std::string &book, double p, std::size_t "
                 "qty, double disc)"
              << std::endl;
  }
  Bulk_quote(const Bulk_quote &rhs) : Disc_quote(rhs) {
    std::cout << "Bulk_quote(const Bulk_quote &rhs)" << std::endl;
  }
  Bulk_quote(Bulk_quote &&rhs) : Disc_quote(std::move(rhs)) {
    std::cout << "Bulk_quote(Bulk_quote &&rhs)" << std::endl;
  }
  Bulk_quote &operator=(const Bulk_quote &rhs) {
    std::cout << "Bulk_quote &operator=(const Bulk_quote &rhs)" << std::endl;
    Disc_quote::operator=(rhs);
    return *this;
  }
  Bulk_quote &operator=(Bulk_quote &&rhs) {
    std::cout << "Bulk_quote &operator=(Bulk_quote &&rhs)" << std::endl;
    Disc_quote::operator=(std::move(rhs));
    return *this;
  }

  double net_price(std::size_t cnt) const override {
    if (cnt >= quantity)
      return cnt * (1 - discount) * price;
    else
      return cnt * price;
  }
};

int main() {
  Quote a;
  Bulk_quote b;

  Quote c(b);

  Quote *ap = &a;
}