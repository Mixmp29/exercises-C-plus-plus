// Упражнение 7.8. Почему функция read() определяет свой параметр типа
// Sales_data как простую ссылку, а функция print() - как ссылку на константу?

// Здесь объект item изменяет значения своих переменных-членов, поэтому
// константность там не ставится: значения читаются из cin в переменные-члены и
// также высчитвается revenue.
std::istream& read(std::istream& is, Sales_data& item) {
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;

  return is;
}

// Здесь же не нужно никак изменять файл, поэтому поставив const мы гарантируем,
// что в теле функции объект item никак не будет изменен.
std::ostream& print(std::ostream& os, const Sales_data& item) {
  os << item.isbn() << " " << item.units_sold << " " << item.revenue;

  return os;
}