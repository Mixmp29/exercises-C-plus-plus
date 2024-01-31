// Упражнение 9.16. Перепишите предыдущую программу, но сравните элементы списка
// list<int> и вектора vector<int>.

#include <iostream>
#include <list>
#include <vector>

int main() {
  std::list<int> list = {1, 2, 3};
  std::vector<int> vec2 = {1, 2, 3};

  // Бан от компилятора: не предуспотрена перегрузка оператора '=='
  // между list и vector.
  std::cout << (list == vec2 ? true : false) << std::endl;
}