// Упражнение 9.27. Напишите программу для поиска и удаления нечетных элементов
// в контйенере forward_list<int>.

#include <forward_list>
#include <iostream>

int main() {
  std::forward_list<int> f_list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  auto curr = f_list.begin();
  auto perv = f_list.before_begin();

  while (curr != f_list.end()) {
    if (*curr % 2)
      curr = f_list.erase_after(perv);
    else {
      perv = curr;
      ++curr;
    }
  }

  for (auto elem : f_list) std::cout << elem << ' ';
  std::cout << std::endl;
}