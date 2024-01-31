// Упражнение 9.20. Напишите программу, копирующую элементы списка list<int> в
// две двухсторонни очереди, причем нечетные элементы должны копироваться в один
// контейнер deque, а четные в другой.

#include <deque>
#include <iostream>
#include <list>

int main() {
  std::list<int> list = {1, 2, 3, 4, 5, 6, 7, 8};
  std::deque<int> evenQue;
  std::deque<int> oddQue;

  for (auto elem : list) {
    if (elem % 2 == 0)
      evenQue.push_back(elem);
    else
      oddQue.push_back(elem);
  }

  for (auto elem : evenQue) std::cout << elem << ' ';
  std::cout << std::endl;

  for (auto elem : oddQue) std::cout << elem << ' ';
  std::cout << std::endl;
}