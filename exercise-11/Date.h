#pragma once

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