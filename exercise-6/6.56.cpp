#include <iostream>
#include <vector>

// Упражнение 6.56. Обратитесь к каждому элементу вектора и выведите результат.

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

  for (auto elem : funcVec) {
    std::cout << elem(10, 5) << std::endl;
  }
}