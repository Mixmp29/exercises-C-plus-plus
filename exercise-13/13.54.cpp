// Упражнение 13.54. Что бы случилос, если бы мы определили оператор
// присваивания при перемещении для HasPtr, но не изменили оператор копии и
// обмена? Напишите код для проверки вашего ответа.

// operator=(HasPtr &&rhs) и operator=(HasPtr rhs) будут одинаково
// подходить r-value. Тоже самое по отношению l-value и конструктора копии.

#include <iostream>
#include <string>

class HasPtr {
  friend void swap(HasPtr &, HasPtr &);

 public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}
  HasPtr(HasPtr &&rhs) = delete;
  ~HasPtr() { delete ps; }

  HasPtr &operator=(HasPtr &&rhs) {
    std::cout << "operator=(HasPtr &&rhs)" << std::endl;
    if (this != &rhs) {
      delete ps;
      ps = rhs.ps;
      i = rhs.i;

      rhs.ps = nullptr;
    }

    return *this;
  }

  // Сделать еще оператор присвоения копировани без ссылок будет невозможно -
  // они будут конфликторвать с другими операторами присвоения, даже если убрать
  // соответствующие конструкторы.
  HasPtr &operator=(HasPtr rhs) {
    std::cout << "operator=(HasPtr rhs)" << std::endl;
    swap(*this, rhs);

    return *this;
  }

 private:
  std::string *ps;
  int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
}

int main() {
  HasPtr h1("1");
  HasPtr h2("2");

  HasPtr h3;
  HasPtr h4;

  h3 = h1;
  h4 = std::move(h2);  // Ошибка. Подойдет и operator=(HasPtr &&rhs) и
                       // operator=(HasPtr rhs).
}