// Что не так со следующей программу? как ее можно исправить?

#include <iostream>
#include <list>

int main() {
  std::list<int> lst1;
  std::list<int>::iterator iter1 = lst1.begin();
  std::list<int>::iterator iter2 = lst1.end();

  /* while (iter1 < iter2) {  // Операторы арифметических действий с итераторам,
                           // перечисленными в табл. 3.7. (стр. 159), применимы
                           // только к итераторам конейнеров strign, vector,
                           // deque и array. То есть в этом случае оператор '<'
                           // для контейнера типа list не определен. Достаточно
                           // просто проверять итераторы на равенствао.
  } */

  while (iter1 != iter2) {
    /* ... */
  }
}