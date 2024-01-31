#include <iostream>
#include <vector>

// Упражнение 6.54. Напишите объявление фунцкии, получающей два параметра int, и
// возвращающей тип int. Объявите также вектор, элементами которого является тип
// указателя на эту функцию.

int func(int a, int b) { return a + b; }

typedef int (*PF)(int, int);
using PF2 = int (*)(int, int);

int main() {
  // std::vector<int (*)(int, int)> funcVec;
  // std::vector<decltype(func)*> funcVec;
  // std::vector<PF> funcVec;
  std::vector<PF2> funcVec;
  funcVec.push_back(func);
  std::cout << funcVec[0](5, 10) << std::endl;
}