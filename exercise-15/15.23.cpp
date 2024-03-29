// Упражнение 15.23. Предположим, что рпделененный на стр. 782 класс D1
// намеревается переопределить свою унаследованную функцию fcn(). Как исправить
// этот класс? Предположим, что класс исправлен так, что функция fcn()
// соответствует ояпределению в классе Base. Как бы распознавались вызовы в этом
// разделе?

// Для корректного переопределения следует сделать одинаковые параметры в обоих
// классах фукнции. После этого объект Base сможет вызывать Base::fcn(), объект
// D1 сможет D1::fcn(). Поскольку виртуальные фукнции прописаны теперь
// правильно, доступно динамическое связывания: указатель/ссылка объекта Base
// сможет вызвать либо base::fcn(), либо D1::fcn() в зависимости от объекта.

// Стоит также добавить, что не стоит добавлять override для виртуальных фукнций
// для уверенности, что это было явное переопределение, а не ошибка, где
// пользователь предполагал создание новой функции (не связанной с виртуальными
// функциями базовых классов).

#include <iostream>

class Base {
 public:
  virtual void fcn() { std::cout << "Base" << std::endl; };
};

class D1 : public Base {
 public:
  void fcn() { std::cout << "D1" << std::endl; };
};

int main() {
  Base base;
  D1 d1;
  Base *bd1 = &d1;
  Base *bd2 = &base;

  base.fcn();
  d1.fcn();
  bd1->fcn();
  bd2->fcn();
}