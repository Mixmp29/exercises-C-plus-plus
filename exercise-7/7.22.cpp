// Упражнение 7.22. Измените свой класс Person так, чтобы скрыть его реализацию.

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
  friend std::istream& read(std::istream& is, Person& item);
  friend std::ostream& print(std::ostream& os, const Person& item);

 public:
  Person() = default;

  Person(const std::string& n) : name(n) {}
  Person(const std::string& n, const std::string& a) : name(n), address(a) {}
  Person::Person(std::istream& is) { read(is, *this); }

  std::string printName() const { return name; }
  std::string printAddress() const { return address; }

 private:
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