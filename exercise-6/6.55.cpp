#include <iostream>
#include <vector>

// Упражнение 6.55. Напишите четыре функции, которые добавляют, вычитают,
// умножают и делят два значения типа int. Сохраните указатели на эти значения в
// векторе из предыдущего упражнения.

int sum(int a, int b) { return a + b; }
int minus(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divi(int a, int b) { return a / b; }

int main() {
  std::vector<int (*)(int, int)> funcVec;
  funcVec.push_back(sum);
  funcVec.push_back(minus);
  funcVec.push_back(mul);
  funcVec.push_back(divi);
}