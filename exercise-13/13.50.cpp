// Упражнение 13.50. Снабдите функции перемещения класса String операторами
// вывода и снова запустите программу из упражнения 13.48 раздела 13.6.1 (стр.
// 676), в котором использовался вектор vector<String>, и посмотрите, когда
// теперь удается избежать копирования.

#include "String.h"

int main() {
  // Теперь практически всегда.

  std::vector<String> vec;
  vec.push_back("Some ");
  std::cout << "------------" << std::endl;
  vec.push_back("string ");
  std::cout << "------------" << std::endl;
  vec.push_back("here.");
  std::cout << "------------" << std::endl;
  vec.push_back("string");
  std::cout << "------------" << std::endl;
  vec.push_back("string");
  std::cout << "------------" << std::endl;
  vec.push_back("string");
  std::cout << "------------" << std::endl;
  vec.push_back("string");
  std::cout << "------------" << std::endl;
  vec.push_back("string");
  std::cout << "------------" << std::endl;
  vec.push_back("string");
}