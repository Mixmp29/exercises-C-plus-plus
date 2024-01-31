// Упражнение 7.45. Определите вектор, содержащий объекты типа C из предыдущего
// упражнения.

#include <vector>

class NoDefault {
 public:
  NoDefault(int i) : a(i){};
  int a;
};

class C {
 public:
  C() : obj(NoDefault(0)) {}

 private:
  NoDefault obj;
};

int main() {
  std::vector<C> vec(10);  // Ok. При инициализации по умолчанию вызвается
                           // стандартный конструктор.
}