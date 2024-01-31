#include "Sales_data3.h"

// Упражнение 7.37. Используя версию класса Sales_data из этого разледа
// определите, какой конструктор используется для инициализации каждой из
// следующих переменных, а также перечислите значения переменных-членов в каждом
// формате.

/* class Sales_data {
 // ...
  Sales_data(const std::string& s = "") : bookNo(s) {}

  Sales_data(const std::string& s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {}

  Sales_data(std::istream& is) {
    double price = 0;
    is >> bookNo >> units_sold >> price;
    revenue = price * units_sold;
  }
 // ...
}; */

// Объявление глобального объекта Sales_data инициализируемая конструктором
// Sales_data(std::istream& is).
Sales_data first_item(std::cin);

int main() {
  // Конструктор Sales_data(const std::string& s = "").
  Sales_data next;
  // Конструктор Sales_data(const std::string& s = "").
  Sales_data last("9-999-99999-9");
}