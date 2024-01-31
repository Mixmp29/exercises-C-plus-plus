// Упражнение 7.9. Добавьте в код, написанный для упражнений в разделе 7.1.2
// (стр.339), операции чтения и вывода объектов класса Person.

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

struct Person {
  std::string printName() const { return name; }
  std::string printAddress() const { return address; }

  std::string name = "";
  std::string address = "";
};

std::istream& read(std::istream& is, Person& item) {
  is >> item.name >> item.address;

  return is;
}

std::ostream& print(std::ostream& os, const Person& item) {
  os << item.name << " " << item.address;

  return os;
}

#endif