#include <iostream>

// Упражнение 5.21. Переделайте программу из упражнения раздела 5.5.1 (стр. 255)
// так, чтобы она искала дубликаты только тех слов, которые начинаются с
// прописной буквы.

int main() {
  std::string repeat, word;

  while (std::cin >> word) {
    if (!isupper(word[0]))
      continue;  // Если первый символ не в верхнем регистре, то продложать ввод
                 // дальше.
    if (word == repeat) break;
    repeat = word;
  }

  if (word == repeat) std::cout << "Repeat word: " << repeat << std::endl;
}