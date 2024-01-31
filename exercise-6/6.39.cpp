#include <iostream>

// Упражнение 6.39. Объясните результат второго объявления в каждом из следующих
// наборов. Укажите, какое из них (если есть) недопустимо.

// (a) Недопустимо. Константность верхнего уровня ну учитывается при объявлении
// фунцкии. Эти два объявления идентичны.

// (b) Недопустимо. Тип возвращаемого значения не учитывается при перегрузке.

// (c) Ok. Типы возварщаемых значений не будут учтены, однако типы параметров
// отличаются. Компилятор подберет функцию с подходящим типом.

void reset(int a) { std::cout << "int " << a << std::endl; }
void reset(double a) { std::cout << "double " << a << std::endl; }

int main() {
  int a = 5;
  double b = 10;
  reset(a);
  reset(b);
}