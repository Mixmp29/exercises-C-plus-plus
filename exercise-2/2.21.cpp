#include <iostream>

// Упражнение 2.21. Объясните каждое из следующих определений. Укажите, все ли
// они корректны и почему.
int main() {
  int i = 0;

  double* dp = &i;
  // Недопустимо присваивать адрес переменной int указателю double.

  int* ip = i;
  // Недопустимо присовение переменной указателю без оператора доступа адреса.

  int* p = &i;  // Допустимо
}