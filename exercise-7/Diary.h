#ifndef DIARY_H
#define DIARY_H

#include <iostream>
#include <string>
#include <vector>

// Класс для упражнения 7.40. В последующих заданиях он также используется и
// изменяется.

class Diary {
  friend Diary compareEntry(const Diary&, const Diary&);
  friend std::istream& read(std::istream&, Diary&);
  friend std::ostream& print(std::ostream&, const Diary&);

 public:
  Diary(int d, int m, int y, const std::string& s)
      : day(d), moth(m), year(y), entries({s}) {}

  Diary() : Diary(0, 0, 0, {}){};
  Diary(int d, int m, int y) : Diary(d, m, y, {}) {}

  Diary& changeDate(int, int, int);
  Diary& addEntry(const std::string&);
  Diary& addEntries(std::istream&);
  Diary& TransferEntries(const Diary&);

 private:
  Diary& pushEntries(const Diary& item) {
    for (const std::string& elem : item.entries) entries.push_back(elem);

    return *this;
  }

  int day = 0;
  int moth = 0;
  int year = 0;
  std::vector<std::string> entries;
};

Diary& Diary::changeDate(int d, int m, int y) {
  day = d;
  moth = m;
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
  pushEntries(item);

  return *this;
}

Diary compareEntry(const Diary& lhs, const Diary& rhs) {
  Diary sum = lhs;

  sum.pushEntries(rhs);

  return sum;
}

std::istream& read(std::istream& is, Diary& item) {
  std::string s;
  is >> item.day >> item.moth >> item.year;
  while (is >> s) item.entries.push_back(s);

  return is;
}

std::ostream& print(std::ostream& os, const Diary& item) {
  os << "\nDate: " << item.day << "." << item.moth << "." << item.year;
  os << "\nEntries:\n";
  for (const std::string& elem : item.entries)
    os << "\t* " << elem << std::endl;

  return os;
}

#endif