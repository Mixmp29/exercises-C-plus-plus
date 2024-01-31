#include <iostream>
#include <string>

// Упражнение 3.5. Напишите программу, читающую строки со стандартного
// устройства ввода и суммирующую их в одну большую строку. Отобразите
// полученную строку. Затем измените прогрмму так, чтобы отделить соседние
// введенные строки пробелами.

int main() {
  std::string str, totalStr;

  /* while (std::cin >> str) {
    totalStr += str;
  }

  std::cout << totalStr << std::endl; */

  while (std::cin >> str) {
    totalStr += str + " ";  // Можно также ' '
  }

  std::cout << totalStr << std::endl;
}