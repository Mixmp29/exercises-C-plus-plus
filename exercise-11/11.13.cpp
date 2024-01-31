// Упражнение 11.13. Существует по крайней мере три способа создания пар в
// программе предыдущего упражнение. Напишите три версии программы, создающей
// пары каждым из этих способов. Укажите, какая из форм проще и почему.

#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
  std::vector<std::pair<std::string, int>> word_count;
  std::string word;
  int count;

  /* while (std::cin >> word >> count) word_count.push_back({word, count});
  while (std::cin >> word >> count)
    word_count.push_back(std::pair<std::string, int>(word, count)); */
  while (std::cin >> word >> count)
    word_count.push_back(std::make_pair(word, count));

  for (auto &elem : word_count)
    std::cout << elem.first << " " << elem.second << std::endl;

  // Лично для меня удобнее использовать просто скобки {first, second}. Вполне
  // можно и явно задать пару через make_pair(). Можно также создавать временный
  // объект дли инициализаци, но тип приходится долго расписывать.
}