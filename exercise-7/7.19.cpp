// Упражнение 7.19. Укажите, какие члены класса Person имеет смысл объявить как
// public, а какие private. Объясните свой выбор.

#include <string>

class Person {
 public:  // Части интерфейса (любое взаимодействие пользователя с объектом)
          // должны быть открытыми.
  Person() = default;

  Person(const std::string& n) : name(n) {}
  Person(const std::string& n, const std::string& a) : name(n), address(a) {}

  std::string printName() const { return name; }
  std::string printAddress() const { return address; }

 private:  // Части реализации должны быть закрыты.
  std::string name = "";
  std::string address = "";
};