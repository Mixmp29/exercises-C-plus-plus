#pragma once

#include <iostream>
#include <string>
#include <vector>

class Diary {
  // Дружеское отношение необходим для доступа к закрытым членам.
  friend Diary& operator+=(Diary&, const Diary&);
  friend bool operator==(const Diary&, const Diary&);
  friend bool operator!=(const Diary&, const Diary&);
  friend bool operator<(const Diary&, const Diary&);
  friend bool operator>(const Diary&, const Diary&);
  friend bool operator<=(const Diary&, const Diary&);
  friend bool operator>=(const Diary&, const Diary&);
  friend std::ostream& operator<<(std::ostream&, const Diary&);
  friend std::istream& operator>>(std::istream&, Diary&);

 public:
  Diary() = default;
  // 14.24.
  Diary(const Diary& d) : day(d.day), month(d.month), year(d.year) {
    entries.clear();
    pushEntries(d);
  };

  // 14.24.
  Diary(Diary&& d) : day(d.day), month(d.month), year(d.year) {
    entries.clear();
    pushEntries(std::move(d));
  };

  // 14.24.
  Diary& operator=(const Diary& d) {
    entries.clear();

    day = d.day;
    month = d.month;
    year = d.year;

    pushEntries(d);

    return *this;
  };

  // 14.24.
  Diary& operator=(Diary&& d) {
    entries.clear();

    day = d.day;
    month = d.month;
    year = d.year;

    pushEntries(std::move(d));

    return *this;
  };

  // 14.49
  explicit operator bool() const {
    if (day && month && year && entries.size() > 0)
      return true;
    else
      return false;
  }

  Diary(int d, int m, int y) : day(d), month(m), year(y) {}  // Дата без записи.
  Diary(int d, int m, int y, const std::string& s)  // Дата с записью.
      : day(d), month(m), year(y), entries({s}) {}

  Diary& changeDate(int, int, int);  // Поменять дату у объекта.
  Diary& addEntry(const std::string&);  // Добавить запись у объекту.
  Diary& addEntries(std::istream&);  // Добавить серию записей в объект.
  Diary& TransferEntries(const Diary&);

 private:
  Diary& pushEntries(const Diary& item) {
    for (const std::string& elem : item.entries) entries.push_back(elem);

    return *this;
  }

  Diary& pushEntries(Diary&& item) {
    for (const std::string& elem : item.entries) entries.push_back(elem);

    return *this;
  }

  int day = 0;                       // День.
  int month = 0;                     // Месяц.
  int year = 0;                      // Год.
  std::vector<std::string> entries;  // Записи строкой.
};

Diary& Diary::changeDate(int d, int m, int y) {
  day = d;
  month = m;
  year = y;

  return *this;
}

Diary& Diary::addEntry(const std::string& s) {
  entries.push_back(s);

  return *this;
}

Diary& Diary::addEntries(std::istream& is) {
  std::string entry;
  while (getline(is, entry)) entries.push_back(entry);

  return *this;
}

Diary& Diary::TransferEntries(const Diary& item) {
  // Каждый элемент записи item.entries добавить в this->entries.
  pushEntries(item);

  return *this;
}

// Объединить записи. Возвращает новый объект записей.
Diary& operator+=(Diary& lhs, const Diary& rhs) {
  // Каждый элемент записи rhs.entries добавить в sum.entries.
  lhs.pushEntries(rhs);

  return lhs;
}

bool operator==(const Diary& lhs, const Diary& rhs) {
  return lhs.day == rhs.day && lhs.month == rhs.month && lhs.year == rhs.year;
}

bool operator!=(const Diary& lhs, const Diary& rhs) { return !(lhs == rhs); }

bool operator<(const Diary& lhs, const Diary& rhs) {
  return lhs.day * lhs.month * lhs.year < rhs.day * rhs.month * rhs.year;
}
bool operator>(const Diary& lhs, const Diary& rhs) { return rhs < lhs; }
bool operator<=(const Diary& lhs, const Diary& rhs) { return !(lhs > rhs); }
bool operator>=(const Diary& lhs, const Diary& rhs) { return !(lhs < rhs); }

// Вывод содержимого объекта в терминал. Возвращает объект ostream;
std::ostream& operator<<(std::ostream& os, const Diary& item) {
  os << "\nDate: " << item.day << "." << item.month << "." << item.year;
  os << "\nEntries:\n";
  for (const std::string& elem : item.entries)
    os << "\t* " << elem << std::endl;

  return os;
}

// Чтение содержимого потока ввода в объект. Возвращает объект istream;
std::istream& operator>>(std::istream& is, Diary& item) {
  std::string entry;
  is >> item.day >> item.month >> item.year;
  if (is) {
    item.entries.clear();
    std::cin.ignore();  // В конце cin есть '\n'. Этот вызов позволит убрать
                        // этот лишний символ.
    while (getline(is, entry)) item.entries.push_back(entry);
  } else
    item = Diary();

  return is;
}