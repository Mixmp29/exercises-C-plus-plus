// Упражнение 7.12. Переместите определение конструктора Sales_data(),
// получающего объект istream, в тело класса Sales_data.

#include <iostream>
#include <string>

struct Sales_data {
  Sales_data() = default;
  // Поведение синтезируемого стандартного конструктора.

  Sales_data(const std::string& s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {}

  Sales_data(const std::string& s) : bookNo(s) {}

  // Функция read() не определена. Можно сделать функцию членом класса, можно
  // копировать ее реализацию. Второй вариант предпочтительнее. Думаю особенно,
  // когда надо будет переопределять операторы под свои нужды. Потом, когда
  // появится дружеское отношение через ключевое слово friend, можно будет
  // просто вызвать функцию read().
  Sales_data(std::istream& is) {
    double price = 0;
    is >> this->bookNo >> this->units_sold >> price;
    this->revenue = price * this->units_sold;
  }

  std::string isbn() const { return bookNo; }
  Sales_data& combine(const Sales_data&);

  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};
