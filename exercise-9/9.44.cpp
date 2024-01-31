// Упражнение 9.44. Перепишите предыдущую функцию так, чтобы использовались
// индекс и функция replace().

#include <iostream>
#include <string>

// Реализация с индексами.
void induction(std::string& s, const std::string& oldVal,
               const std::string& newVal) {
  for (size_t i = 0; i < s.size() - oldVal.size(); ++i) {
    std::string substring = s.substr(i, oldVal.size());
    if (substring == oldVal) {
      s.replace(i, oldVal.size(), newVal);
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