// Упражнение 9.51. Напишите класс, у которого есть три беззнаковых члена,
// представляющих год, месяц и день. Напишите конструктор, получающий строку,
// представляющую датую Конструктор должен понимать множество форматов даты,
// такие как "January 1, 1900", "1/1/1900", "Jan 1, 1900" и т.д.

#include <iostream>
#include <string>
#include <vector>

class Date {
  friend std::ostream& print_date(std::ostream&, const Date&);

 public:
  Date(std::string s) {
    std::string::size_type pos = 0;
    // Если формат записи месяца не числовой...
    if (s.find_first_of("0123456789") != 0)
      // Взять подстроку, где нет символов " .,/0123456789", и сравнить с
      // месяцами года.
      month = int_month(s.substr(s.find_first_not_of(" .,/0123456789"),
                                 s.find_last_not_of(" .,/0123456789")));
    else
      month = step(s, pos);

    day = step(s, pos);
    year = step(s, pos);
  }

 private:
  // Функция нахождения следующего числа в строке.
  int step(const std::string& s, std::string::size_type& pos) {
    // Найти число в строке.
    pos = s.find_first_of("0123456789", pos);
    // Формировать чило пока не появится другой символ.
    int val = std::stoi(s.substr(pos));
    // Поставить позицию за сформированным числом.
    pos = s.find_first_of(".,/", pos);

    // Вернуть сформированное целочисленное значение.
    return val;
  }

  int int_month(const std::string s) {
    // Вектор 12-ти месяцев года.
    std::vector<std::string> months = {
        "January", "February", "March",     "April",   "May",      "June",
        "Jule",    "August",   "September", "October", "November", "December"};

    for (int i = 0; i < 12; ++i) {
      // Если хотя бы один месяц совпадает, то вернуть номер месяца.
      if (months[i].find(s) != std::string::npos) return i + 1;
    }

    // Если ни один месяц не подходит, то вернуть 0 в качестве ошибки.
    return 0;
  }

  unsigned year = 0;
  unsigned month = 0;
  unsigned day = 0;
};

std::ostream& print_date(std::ostream& os, const Date& date) {
  os << date.month << "." << date.day << "." << date.year << std::endl;

  return os;
}

int main() {
  Date date1("January 1, 1900");
  Date date2("January, 1, 1900");
  Date date3("1, 1, 1900");
  Date date4("January/1/1900");
  Date date5("January.1.1900");
  Date date6("1.1.1900");

  print_date(std::cout, date1);
  print_date(std::cout, date2);
  print_date(std::cout, date3);
  print_date(std::cout, date4);
  print_date(std::cout, date5);
  print_date(std::cout, date6);
}