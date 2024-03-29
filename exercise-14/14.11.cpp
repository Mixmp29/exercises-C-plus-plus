// Упражнение 14.11. Что не так со следующим оператором ввода класса Sales_data?
// Что будет при передаче этому оператору данных предыдущего упражнения?

// В данном случае нет проверки на правильность ввода потока. Это значит, что
// если будет введен вариант (b) из предыдущего упражнения, то переменная
// revenue посчитается с неопределенной price, что приведет к неопределенному
// поведению. Сам объект s также может записать значения, которые в случае
// ошибки не будут соответствовать (то есть будет записана только чать).

/*

  istream& operator>>(istream& in, Sales_data& s)
  {
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    s.revenue = s.units_sold  * price;

    return in;
  }

 */