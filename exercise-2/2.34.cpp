#include <iostream>

// Упражнение 2.34. Напишите программу, содержащую переменные и присвоения из
// предыдущего упражнения. Выведите значения переменных до и после присовений,
// чтобы проверить правильность предположений в предыдущем упражнении. Если они
// неправильны, изучите примеры еще раз и выясните, что привело к неправильному
// заключению.

int main() {
  int *pointer2;
  int i = 0, &r = i;
  auto a = r;

  const int ci = i, &cr = ci;
  auto b = ci;   // int
  auto c = cr;   // int
  auto d = &i;   // int *
  auto e = &ci;  // const int *

  auto &g = ci;  // const int &

  std::cout << a << std::endl;  // int 0
  std::cout << b << std::endl;  // int 0
  std::cout << c << std::endl;  // int 0
  std::cout << d << std::endl;  // int* adress i
  std::cout << e << std::endl;  // const int* adress ci
  std::cout << g << std::endl;  // const int 0

  a = 42;  // Присвоение константного литерала переменной типа int. Верхний
           // уровень константы игнорируется.
  b = 42;  // Присвоение константного литерала переменной типа int. Верхний
           // уровень константы игнорируется.
  c = 42;  // Присвоение константного литерала переменной типа int. Верхний
           // уровень константы игнорируется.
  // d = 42;  // Недопустимое присвоение значения константного литерала
  // указателю (должен быть адрес)
  //  типа int
  // e = 42;  // Недопустимое присвоение значения константного литерала
  // указателю (должен быть адрес)
  //  типа const int
  // g = 42;  // g - const int. Значение менять нельзя.

  std::cout << a << std::endl;  // int 42
  std::cout << b << std::endl;  // int 42
  std::cout << c << std::endl;  // int 42
  std::cout << d << std::endl;  // int* adress i
  std::cout << e << std::endl;  // const int* adress ci
  std::cout << g << std::endl;  // const int 0
}