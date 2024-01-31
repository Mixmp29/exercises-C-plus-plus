// Упражнение 11.3. Напишите собственную версию программы подсчета слов.

#include <iostream>
#include <map>
#include <set>

int main() {
  std::map<std::string, std::size_t> word_count;
  std::set<std::string> exclude = {"The", "But", "And", "Or", "An", "A",
                                   "the", "but", "and", "or", "an", "a"};

  std::string word;
  while (std::cin >> word)
    if (exclude.find(word) == exclude.end()) ++word_count[word];

  for (const auto& elem : word_count) {
    std::cout << elem.first << " occurs " << elem.second
              << ((elem.second > 1) ? " times " : " time ") << std::endl;
  }
}