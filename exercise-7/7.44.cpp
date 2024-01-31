// Упражнение 7.44. Допустимо ли следующее объявление? Если нет, то почему?

#include <vector>

class NoDefault {
 public:
  NoDefault(int i) : a(i){};
  int a;
};

int main() {
  std::vector<NoDefault> vec(
      10);  // Недопустимо. Нет стандартного конструктора, который вызвается при
            // инициализации объекта по умолчанию.
}