// Упражнение 9.43. Напишите функцию, получающую три строки: s, oldVal и newVal.
// Используя итераторы, а также функции insert(), и erase() замените все
// присутствующие в строке s экземпляры строки oldVal строкой newVal. Проверьте
// функцию на примере замены таких общепринятых сокращений, как "tho" на
// "though" и "thru" на "through".

#include <iostream>
#include <string>

// Реализация с итераторами. Проще с индексами конечно.
void induction(std::string& s, const std::string& oldVal,
               const std::string& newVal) {
  for (auto i = s.begin(); i < s.end() - oldVal.size(); ++i) {
    std::string substring = s.substr(
        i - s.begin(), oldVal.size());  // Вырезание подстроки подстроки.
    if (substring == oldVal) {  // Если эта подстрока та, что нужно заменить...
      s.erase(i - s.begin(), oldVal.size());      // Удалить ее.
      s.insert(i, newVal.begin(), newVal.end());  // Вставить новую.
    }
  }
}

int main() {
  std::string text;
  getline(std::cin, text);
  induction(text, "tho", "though");
  induction(text, "thru", "through");
  std::cout << text << std::endl;

  // I tho this is land. That's thru.
  // I though this is land. That's through.
}