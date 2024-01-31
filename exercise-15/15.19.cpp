// Упражнение 15.19. Предположим, у каждого из классов со стр. 773 и 774 есть
// функция-член в формате void memfcn(Base &b) { b = *this; }

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