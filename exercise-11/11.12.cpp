// Упражнение 11.12. Напишите программу, читающую последовательность строк и
// целых чисел, сохраняя каждую прочитанную пару в объекте класса pair.
// Сохраните пары в векторе.

#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
  std::vector<std::pair<std::string, int>> word_count;
  std::string word;
  int count;

  while (std::cin >> word >> count) word_count.push_back({word, count});

  for (auto &elem : word_count)
    std::cout << elem.first << " " << elem.second << std::endl;
}
