// Упражнение 7.50. Определите, должен ли какой-либо из конструкторов вашего
// класса Person быть явным.

#include <iostream>
#include <string>

// Как бы такая возможность есть, но большой необходимости в этом нету.
// read() попросту не даст ссылку на неконстанту, а в print не страшно, если
// просто имя выведет. Так что ответ: нет.

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