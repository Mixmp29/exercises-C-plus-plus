// Упражнение 10.21. Напишите лямбда-выражение, которое захватывает локльную
// переменную типа int и осуществляет декремент ее значения, пока оно не
// достигнет 0. Как только значение переменной достигнет 0, декремент
// переменногой прекращается. Лямбда-выражение должно возвратить логическое
// значение, указывающее, имеет ли захваченная переменная значение 0.

#include <iostream>

int main() {
  int a = 5;
  auto f = [a]() mutable -> bool {
    while (a > 0) a--;
    return a == 0;
  };

  std::cout << f() << std::endl;
}