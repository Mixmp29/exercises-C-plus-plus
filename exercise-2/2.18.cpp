#include <iostream>

// Упражнение 2.18. Напишите код, изменяющий значение указателя. Напишите код
// для изменения знчения, на которое указывает указатель.
int main() {
  int val = 54;
  int *pv = nullptr;

  pv = &val;

  std::cout << *pv << " " << val << std::endl;

  *pv += 10;

  std::cout << *pv << " " << val << std::endl;
}