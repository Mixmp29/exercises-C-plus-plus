// Упражнение 15.20. Напишите код проверки ответов на предыдущие два упражнения.

class Base {
 public:
  void pub_mem();

 protected:
  int prot_mem;

 private:
  char priv_mem;
};

struct Pub_Derv : public Base {
  int f() { return prot_mem; }
  void memfcn(Base &b) { b = *this; }  // Допустимо. Публичное наследование.
};

struct Priv_Derv : private Base {
  int f1() const { return prot_mem; }
  void memfcn(Base &b) {
    b = *this;
  }  // Недопустимо только для пользователей из-за закрытого наследования.
};

struct Prot_Derv : protected Base {
  int f1() const { return prot_mem; }
  void memfcn(Base &b) {
    b = *this;
  }  // Доступно только для членов и друзей. Недопустимо для пользователей.
};

struct Derived_from_Public : public Pub_Derv {
  int use_base() { return prot_mem; }
  void memfcn(Base &b) {
    b = *this;
  }  // Допустимо. Публичное наследование во всей последовательности классов.
};

struct Derived_from_Private : public Priv_Derv {
  // int use_base() { return prot_mem; }
  // void memfcn(Base &b) { b = *this; }
  // Недопустимо, вся последовательность закрыта.
};

struct Derived_from_Protected : public Prot_Derv {
  int use_base() { return prot_mem; }
  void memfcn(Base &b) {
    b = *this;
  }  // Допустимо для членов и друзей. Недопустимо для пользователей.
};

// Все ошибки только в main.

int main() {
  Pub_Derv d1;
  Priv_Derv d2;
  Prot_Derv d3;
  Derived_from_Public dd1;
  Derived_from_Private dd2;
  Derived_from_Protected dd3;

  Base *p = &d1;  // Допустимо. Публичное наследование.

  p = &d2;  // Недопустимо только для пользователей из-за закрытого
            // наследования.

  p = &d3;  // Доступно только для членов и друзей. Недопустимо для
            // пользователей.

  p = &dd1;  // Допустимо. Публичное наследование во всей последовательности
             // классов.

  p = &dd2;  // Недопустимо, вся последовательность закрыта.

  p = &dd3;  // Допустимо для членов и друзей. Недопустимо для пользователей.
}