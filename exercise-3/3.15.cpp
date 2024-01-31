#include <iostream>
#include <string>
#include <vector>

// Упражнение 3.15. Повторите предыдущую программу, но на сей раз читайте
// строки.

int main() {
  std::string word;
  std::vector<std::string> text;

  while (std::cin >> word) {
    text.push_back(word);
  }

  std::cout << "-------------" << std::endl;

  for (const auto &v : text) {
    std::cout << v << std::endl;
  }
}