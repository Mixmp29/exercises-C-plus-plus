#include <iostream>

// Упражнение 2.36. Определите в следующем коде тип каждой переменной и
// значения, которые будет иметь каждая из них по завершении.

int main() {
  int a = 3, b = 4;
  decltype(a) c = a;    // int c
  decltype((b)) d = a;  // int d&
  ++c;
  ++d;

  std::cout << a << " " << b << " " << c << " " << d << std::endl;
  // 4 4 4 4
}