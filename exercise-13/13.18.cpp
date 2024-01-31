// Упражнение 13.18. Определите класс Employee, содержащий имя сотрудника и его
// уникальный идентификатор. Снабдите класс стандартным конструктором и
// конструктором получающим строку, представляющую имя сотрудника. Каждый
// конструктор должен создавать уникальный идентификатор за счет приращения
// статической переменной-члена.

#include <string>

class Employee {
 public:
  Employee(const std::string& n = "") : name(n), identifier(++num) {}

 private:
  static unsigned num;

  std::string name;
  unsigned identifier;
};

unsigned Employee::num = 0;

int main() { Employee worker1("John"); }