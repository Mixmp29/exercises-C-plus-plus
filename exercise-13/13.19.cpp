// Упражнение 13.19. Должен ли класс Employee определить собственные версии
// функций-членов управления копированием? Если да, то почему? Если нет, то тоже
// почему? Реализуйте все члены управления копированием, в которых на ваш
// взгляд, нуждается класс Employee.

// Класс нуждается в собственные версии инициализации копированием и оператора
// присвоения копией. Это обусловлено наличием уникального номера работника,
// который присваивается при создании. Разжевано в упражнениях 13.14 - 13.17.

#include <string>

class Employee {
 public:
  Employee(const std::string& n = "") : name(n), identifier(++num) {}
  Employee(const Employee& rhs) : name(rhs.name), identifier(++num) {}

  // Пока не знаю, нужно ли оперделять присвоеине для сотрудников. Оставлю на
  // случай, если нужно будет его использовать.
  Employee& operator=(const Employee& rhs) { name = rhs.name; }

 private:
  static unsigned num;

  std::string name;
  unsigned identifier;
};

unsigned Employee::num = 0;

int main() { Employee worker1("John"); }