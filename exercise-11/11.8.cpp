// Упражнение 11.8. Напишите программу, которая хранит исключенные слова в
// векторе, а не в наборе. Каковы преимущества использования набора?

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

// В наборе удобно определены специфические функции алгоритмов, такие как
// find(). Нужно возиться с итераторами. Для set достаточно просто вызвать
// функцию find().

int main() {
  std::map<std::string, std::size_t> word_count;
  std::vector<std::string> exclude = {"The", "But", "And", "Or", "An", "A",
                                      "the", "but", "and", "or", "an", "a"};

  std::string word;
  while (std::cin >> word)
    if (find(exclude.begin(), exclude.end(), word) == exclude.end())
      ++word_count[word];

  for (const auto& elem : word_count) {
    std::cout << elem.first << " occurs " << elem.second
              << ((elem.second > 1) ? " times " : " time ") << std::endl;
  }
}