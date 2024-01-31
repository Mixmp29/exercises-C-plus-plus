// Упражнение 13.5. Напишите с учетом следующего эскиза класса конструктор
// копий, копирующий все переменные-члены. Конструктор должен динамически
// резервировать новую строк и копировать объект на который указывает ps, а не
// сам указатель ps.

#include <string>

class HasPtr {
 public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}

  HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}

 private:
  std::string *ps;
  int i;
};