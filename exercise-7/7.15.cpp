// Упражнение 7.15. Добавьте соответствующие конструкторы в класс Person.

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