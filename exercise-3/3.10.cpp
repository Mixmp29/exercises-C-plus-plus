#include <iostream>
#include <string>

// Упражнение 3.10. Напишите программу, которая читает строку символов,
// включающую знаки пунктуации, и выведите ее, но уже без знаков пунктуации.

int main() {
  std::string str, noPunct;

  getline(std::cin, str);

  for (char &c : str) {
    if (!ispunct(c)) noPunct += c;
  }

  std::cout << noPunct << std::endl;

  // или

  for (char &c : str) {
    if (!ispunct(c)) std::cout << c;
  }
  std::cout << std::endl;
}