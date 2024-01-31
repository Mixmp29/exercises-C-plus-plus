// Упражнение 9.19. Перепишите программу из предыдущего упражнения, чтобы
// использовался контейнер list. Перечислите необходимые изменения.

// Достаточно заменить имя deque на list во всей программе. Или хотя бы в
// заголовке и объявлении.

#include <iostream>
#include <list>
#include <string>

int main() {
  std::string word;
  std::list<std::string> list;

  while (std::cin >> word) {
    list.insert(list.end(), word);  // Эквивалентно push_back().
  }

  for (auto elem : list) std::cout << elem << std::endl;
}