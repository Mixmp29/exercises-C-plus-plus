// Упражнение 11.4. Усовершенствуйте свою программу так, чтобы игнорировать
// регистр и пунктуацию. Т.е. слова "example" и "Example", например, должны
// увеличить тот же счетчик.

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>

void ignorePunct(std::string& word) {
  // Не сработает с повторяющейся пунктуацией: "This is was YOU!!!", но будет
  // меньше проходить последователеьность.
  word = word.substr(0, word.find_last_of(",.!?-"));

  // Будет гораздо больше проходить последовательность, но исключит повторения
  // пунктуации.
  // word = word.substr(0, word.find_first_of(",.!?-"));
}

void tolower(std::string& word) {
  for (auto& c : word) {
    c = std::tolower(c);
  }
}

int main() {
  std::map<std::string, std::size_t> word_count;
  std::set<std::string> exclude = {"the", "but", "and", "or", "an", "a",
                                   ",",   ".",   "!",   "?",  "-"};
  std::set<std::string> exclude_punctuation = {};

  std::string word;
  while (std::cin >> word) {
    ignorePunct(word);
    tolower(word);
    if (exclude.find(word) == exclude.end()) {
      ++word_count[word];
    }
  }

  for (const auto& elem : word_count) {
    std::cout << elem.first << " occurs " << elem.second
              << ((elem.second > 1) ? " times " : " time ") << std::endl;
  }
}