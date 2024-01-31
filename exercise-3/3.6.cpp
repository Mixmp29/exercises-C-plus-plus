#include <iostream>
#include <string>

// Упражнение 3.6. Используйте серийный оператор for для замены всех символов
// строки на X.

int main() {
  std::string str("Hello, World!");

  for (auto &c :
       str) {  // Получение ссылки на каждое значение последовательности.
    c = 'X';
  }

  std::cout << str << std::endl;
}