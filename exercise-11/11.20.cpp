// Упражнение 11.20. Перепешите программу подсчета слов из раздела 11.1
// (стр.539) так, чтобы использовать функцию insert() вместо индексации. Какая
// версия программы по-вашему проще? Объясните почему.

// Проще использовать итератор индекса []. Однако по такой программе наглядно
// понятно как работает алгоритм, сразу видно, что используется map.

#include <iostream>
#include <map>
#include <set>

int main() {
  std::map<std::string, std::size_t> word_count;
  std::set<std::string> exclude = {"The", "But", "And", "Or", "An", "A",
                                   "the", "but", "and", "or", "an", "a"};

  std::string word;
  while (std::cin >> word)
    if (exclude.find(word) == exclude.end()) {
      auto ret = word_count.insert({word, 1});
      if (!ret.second) ++ret.first->second;
    }

  for (const auto& elem : word_count) {
    std::cout << elem.first << " occurs " << elem.second
              << ((elem.second > 1) ? " times " : " time ") << std::endl;
  }
}