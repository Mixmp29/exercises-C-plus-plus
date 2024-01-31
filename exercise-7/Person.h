#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

struct Person {
  Person() = default;

  Person(const std::string& n) : name(n) {}
  Person(const std::string& n, const std::string& a) : name(n), address(a) {}

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