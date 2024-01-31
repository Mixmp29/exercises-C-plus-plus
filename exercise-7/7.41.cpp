// Упражнение 7.41. Перепишите собственную версию класса Sales_data, чтобы
// использовать делегирующие. Добавьте в тело каждого конструктора оператор,
// выводящий сообщений всякий раз, когда он выполняется. Напишите объявления для
// сохдания объекта класса Sales_data любыми возможными способами. Изучите вывод
// и удостоверьтесь, что понимаете порядок выполнения делигирующих
// конструкторов.

// Нагляднее будет, если использовать пример из книги.

// Думаю еще требуется маленькое пояснение: делегированный (делегируемый)
// конструктор - констуктор, который вызвал делегирующий конструктор.

#include <iostream>
#include <string>

class Sales_data {
  friend std::istream& read(std::istream& is, Sales_data& item);

 public:
  Sales_data(const std::string& s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {
    std::cout << "Sales_data(const std::string& s, unsigned n, double p)"
              << std::endl;
  }

  Sales_data() : Sales_data("", 0, 0) {
    std::cout << "Sales_data()" << std::endl;
  }

  Sales_data(const std::string& s) : Sales_data(s, 0, 0) {
    std::cout << "Sales_data(const std::string& s = \"\")" << std::endl;
  }

  // Прроще так.
  Sales_data(std::istream& is) : Sales_data() {
    read(is, *this);
    std::cout << "Sales_data(std::istream& is)" << std::endl;
  }

  // Эквивалентно
  // Sales_data(std::istream& is) : Sales_data("", 0, 0) { read(is, *this); }

 private:
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

std::istream& read(std::istream& is, Sales_data& item) {
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;

  return is;
}

int main() {
  std::cout << "- - - - - -\n";
  Sales_data item1;
  std::cout << "- - - - - -\n";
  Sales_data item2("9999-9099=00");
  std::cout << "- - - - - -\n";
  Sales_data item3(std::cin);
  std::cout << "- - - - - -\n";
  Sales_data item4("9999-9099=01", 3, 15);
  std::cout << "- - - - - -\n";

  // Идет спуск до самого дальнего делегируемого конструктора и потом подъем и
  // вывод из тела.
}