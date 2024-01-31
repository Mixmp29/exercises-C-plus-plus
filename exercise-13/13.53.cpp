// Упражнение 13.53. С точки зрения низкоуровневой эффективности оператор
// присвоения класса HasPtr не идеален. Объясните почему. Реализуйте для класса
// HasPtr оператор присвоения копии и присвоения при перемещении и сравните
// действия, выполняемые в новом операторе присвоения при перемещении, с версией
// копии и обмена.

// На заметку: operator=(HasPtr &&rhs) и operator=(HasPtr rhs) будут одинаково
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

  // Если нужно было так, то определенно выигрывает перемещение.
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

  // В таком случае также поменяется и rhs, так как на него взята ссылка.
  HasPtr &operator=(HasPtr &rhs) {
    std::cout << "operator=(HasPtr rhs)" << std::endl;
    swap(*this, rhs);

    return *this;
  }

  // Сделать еще оператор копирования без ссылок будет невозможно - они будут
  // конфликторвать с другими операторами присвоения, даже если убрать
  // соответствующие конструкторы.
  /* HasPtr &operator=(HasPtr rhs) {
    std::cout << "operator=(HasPtr rhs)" << std::endl;
    swap(*this, rhs);

    return *this;
  } */

  // Если все же имелась обычная копия. В этом случае лишний раз происходит
  // копирование членов rhs. У перемещения этого можно избежать, но надо не
  // забывать сделать указатель ps безопасным для удаления при вызове
  // деструктора.
  /* HasPtr &operator=(HasPtr rhs) {
    std::string *newp = new std::string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;

    return *this;
  } */

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
  h4 = std::move(h2);
}