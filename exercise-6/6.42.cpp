#include <iostream>
#include <string>

// Упражнение 6.42. Присвойте второму параметру функции make_plural() (см.
// раздел 6.3.2, стр. 294) аргумент по умолчанию 's'. Проверьте программу,
// выведя слова "success" и "failure" в единственно и множественном числе.

std::string make_plural(size_t ctr, const std::string& word,
                        const std::string& ending) {
  return (ctr > 1) ? word + ending : word;
}

int main() {
  std::cout << make_plural(1, "The", " End.") << std::endl;
  std::cout << make_plural(2, "The", " End.") << std::endl;
}