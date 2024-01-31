#include <iostream>

// Упражнение 4.30. Используя таблицу из раздела 4.12 (стр. 227), расставьте
// скобки в следующих выражениях так, чтобы продемонстрировать порядок его
// обработки:

int f() { return 1; }

struct S {
  int mem[5];
};

int main() {
  int x = 1, y = 2, a = 3, b = 4, i = 1;
  S s, *p = &s;

  std::cout << sizeof x + y << std::endl;
  std::cout << sizeof p->mem[i] << std::endl;
  std::cout << (sizeof a < b) << std::endl;
  std::cout << sizeof f() << std::endl;

  std::cout << std::endl;

  std::cout << (sizeof x) + y << std::endl;     // 4 + 2 = 6
  std::cout << sizeof(p->mem[i]) << std::endl;  // int - 4 bits
  std::cout << ((sizeof a) < b) << std::endl;   // (4 < 4) -> 0
  std::cout << sizeof(f()) << std::endl;        // return int -> 4
}