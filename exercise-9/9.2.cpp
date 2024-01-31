// Упражнение 9.2. Определите список (list), элементами которого будут
// духсторонние очереди целых чисел.

#include <deque>
#include <iostream>
#include <list>

int main() {
  std::list<std::deque<int>> list(10, {10, 15, 20});
  auto lIter = list.begin();
  std::cout << lIter->size() << std::endl;
}