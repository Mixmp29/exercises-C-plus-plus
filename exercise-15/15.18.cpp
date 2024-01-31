// Упражнение 15.18. С учетом классов со стр. 773 и 774 и типов объектов,
// приведенных в комментариях, укажите, какие из следующих присвоений допустимы.
// Объясните, почему некоторые недопустимые.

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
};

struct Priv_Derv : private Base {
  int f1() const { return prot_mem; }
};

struct Prot_Derv : protected Base {
  int f1() const { return prot_mem; }
};

struct Derived_from_Public : public Pub_Derv {
  int use_base() { return prot_mem; }
};

struct Derived_from_Private : public Priv_Derv {
  // int use_base() { return prot_mem; }
};

struct Derived_from_Protected : public Prot_Derv {
  int use_base() { return prot_mem; }
};

/*
Base *p = &d1; // Допустимо. Публичное наследование.

p = &d2; // Недопустимо только для пользователей из-за закрытого
            наследования.

p = &d3; // Доступно только для членов и друзей. Недопустимо для
            пользователей.

p = &dd1; // Допустимо. Публичное наследование во всей последовательности
             классов.

p = &dd2; // Недопустимо, вся последовательность закрыта.

p = &dd3; // Допустимо для членов и друзей. Недопустимо для пользователей.
 */