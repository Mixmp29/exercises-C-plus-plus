// Упражнение 14.21. Напишите операторы класса Sales_data так, чтобы +
// осуществлял сложение, а оператор += вызвал оператор +. Обсудите недостатки
// этого подхода по сравнению со способом, которым эти операторы были определены
// в разделах 14.3 (стр. 710) и 14.4 (стр. 713).

// Писать оператор operator+ было неудобно. Тоже самое можно сказать про '+='.
// Реализации из книги сделаны интуитивно понятно. Здесь же с первого взгляда
// непонятно, что делает код.

Sales_data& Sales_data::operator+=(const Sales_data& rhs) {
  *this = *this + rhs;

  return *this;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs) {
  Sales_data sum = lhs;
  sum;

  sum.units_sold = lhs.units_sold + rhs.units_sold;
  sum.revenue = lhs.revenue + rhs.revenue;

  return sum;
}