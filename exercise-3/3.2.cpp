#include <iostream>
#include <string>

// Упражнение 3.2. Напишите программу, читающую со стандартного устройства ввода
// по одной строке за раз. Измените программу так, чтобы читать по одному слову
// за раз.

int main() {
  std::string str;

  /* std::cout << "Читать по одной строке за раз:\n";
  while (getline(std::cin, str)) {
    std::cout << str << std::endl;
  } */

  std::cout << "Читать по одному слову за раз:\n";
  while (std::cin >> str) {
    std::cout << str << std::endl;
  }
}