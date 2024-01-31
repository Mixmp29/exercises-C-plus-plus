// Упражнение 13.8. Напишите оператор присвоения для класса HasPtr из
// упражнения 13.5 раздела 13.1.1 (стр. 634). Подобно конструктору копий, данный
// оператор присвоения должен копировать объект, на который указывает указатель
// ps.

#include <string>

class HasPtr {
 public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}

  HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}

  HasPtr &operator=(const HasPtr &rhs) {
    /* ps = new std::string(*rhs.ps);
    i = rhs.i; */

    // Изменено после правки в 13.11.
    std::string *newp = new std::string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
  }

 private:
  std::string *ps;
  int i;
};