#include <iostream>
#include <string>

// Упражнение 6.25. Напишите функцию main(), получающую два аргумента.
// Конкатинируйте предоставленные аргументы и выведите полученную строку.

int main(int argc, char** argv) {
  std::string args;

  for (int i = 1; i < argc; ++i) {
    args += argv[i];
  }

  std::cout << args << std::endl;
}