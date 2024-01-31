#include <iostream>

// Упражнение 5.19. Напишите программу, использующую цикл do while для
// циклического запроса у пользователя двух строк и указания, которая из них
// меньше другой.

int main() {
  do {
    std::string str1, str2;
    std::cout << "Please enter two strings: ";
    if (std::cin >> str1 >> str2) {
      if (str1 > str2)
        std::cout << "string \"" << str1 << "\" is bigger then \"" << str2
                  << "\"" << std::endl;
      else if (str1 < str2)
        std::cout << "string \"" << str1 << "\" is smaller then \"" << str2
                  << "\"" << std::endl;
      else
        std::cout << "string \"" << str1 << "\" is equal to \"" << str2 << "\""
                  << std::endl;
    }
  } while (std::cin);
}