// Упражнение 10.42. Переделайте программу,.устранявшую повторяющиеся слова,
// написанную в разделе 10.2.3 (стр. 491), так, чтобы использовался список, а не
// вектор.

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>

void elimDups(std::list<std::string>& word) {
  word.sort();    // Сортирует без итераторов.
  word.unique();  // Сразу удаляет элементы. Изменяет размер списка.
}

int main() {
  std::istream_iterator<std::string> in(std::cin), end;
  std::list<std::string> slist(in, end);

  elimDups(slist);

  std::cout << slist.size() << std::endl;
  for (auto elem : slist) std::cout << elem << " ";
  std::cout << std::endl;
}