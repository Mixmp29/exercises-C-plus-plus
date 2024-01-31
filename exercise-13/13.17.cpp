// Упражнение 13.17. Напишите версии класса numbered и функции f(),
// соответствующием трем предыдущим упражнениям, и проверьте правильность
// предсказания вывода.

#include <iostream>

class numbered {
 public:
  numbered() { mysn = ++num; }

  unsigned mysn;

 private:
  static unsigned num;  // Хороший пример использования статической переменной.
};

unsigned numbered::num = 0;

class numbered_with_copy {
 public:
  numbered_with_copy() { mysn = ++num; }
  numbered_with_copy(const numbered_with_copy& a) { mysn = ++num; }

  // В данном примере нет необходимости в присвоении, так как этот оператор не
  // используеся. А вообще по хорошему должен быть.

  unsigned mysn;

 private:
  static unsigned num;
};

unsigned numbered_with_copy::num = 0;

void f(numbered s) { std::cout << s.mysn << std::endl; }
void fcopy(numbered_with_copy s) { std::cout << s.mysn << std::endl; }
void fref(const numbered_with_copy& s) { std::cout << s.mysn << std::endl; }

int main() {
  numbered a, b = a, c = b;
  f(a);
  f(b);
  f(c);

  std::cout << std::endl;

  numbered_with_copy a2, b2 = a2, c2 = b2;
  fcopy(a2);
  fcopy(b2);
  fcopy(c2);

  std::cout << std::endl;

  fref(a2);
  fref(b2);
  fref(c2);
}