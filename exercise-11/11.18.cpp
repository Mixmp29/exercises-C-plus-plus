// Упражнение 11.18. Перепишите определение типа map_it из цикла на стр. 549, не
// используя ключевое слово auto или decltype.

#include <iostream>
#include <map>
#include <string>

int main() {
  std::map<std::string, std::size_t> word_count = {{"Some", 1}, {"string", 1}};
  std::map<std::string, std::size_t>::const_iterator map_it =
      word_count.cbegin();

  while (map_it != word_count.cend()) {
    std::cout << map_it->first << " occurs " << map_it->second << " times"
              << std::endl;
    ++map_it;
  }
}