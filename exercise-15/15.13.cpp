// Упражнение 15.13. С учетом следующих классов объ\ясните каждую из следующих
// функций print():

// В классе base функция-член print берет ссылку на вывод (cout), записывает в
// него строку basename и ничего не возвращает.

// В классе derived идет возможная попытка переопределения виртуальной функции.
// Фнутри есть ошибка: попытка вызвать print() из base без надлежащего оператора
// области видимости. Как результат будет бесконечная рекурсия.

#include <iostream>
#include <string>

class base {
 public:
  std::string name() { return basename; }
  virtual void print(std::ostream &os) { os << basename; }

 private:
  std::string basename;
};

class derived : public base {
 public:
  void print(std::ostream &os) override {
    base::print(os);
    os << " " << i;
  }

 private:
  int i;
};