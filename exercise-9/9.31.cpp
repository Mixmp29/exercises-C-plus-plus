// Упражнение 9.31. Программа на стр. 455, удаляющая четные и дублирующая
// нечетные элементы, не будетработать с контейнером list или forward_list.
// Почему? Переделайте программу так, чтобы она работала с этими типами тоже.

#include <forward_list>
#include <iostream>
#include <list>
#include <vector>

int main() {
  // Версия vector.
  /*  std::vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
   auto iter = vi.begin();

   while (iter != vi.end()) {
     if (*iter % 2) {
       iter = vi.insert(iter, *iter);
       iter += 2;  // Как минимум из-за вот этой строки. Поскольку в памяти
                   // элементы хранятся не рядом, не предусмотрены
   арифметические
                   // выражения с итераторами list и forward_list.
     } else
       iter = vi.erase(iter);
   } */

  // Версия list.
  /* std::list<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto iter = vi.begin();

  while (iter != vi.end()) {
    if (*iter % 2) {
      iter = vi.insert(iter, *iter);
      ++(++iter); // Инкремент и декремент предусмотрен.
    } else
      iter = vi.erase(iter);
  } */

  // Версия forward_list.
  std::forward_list<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto curr = vi.begin();
  auto prev = vi.before_begin();

  while (curr != vi.end()) {
    if (*curr % 2) {
      curr = vi.insert_after(curr, *curr);
      prev = curr;
      ++curr;  // Инкремент и декремент предусмотрен.
    } else
      curr = vi.erase_after(prev);
  }

  for (auto elem : vi) std::cout << elem << ' ';
  std::cout << std::endl;
}