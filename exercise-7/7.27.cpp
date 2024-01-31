#include <iostream>

#include "Screen.h"

// Упражнение 7.27. Добавьте функции move(), set() и display() в свою версию
// класса Screen. Проверьте свой класс, выполнив следующий код.

int main() {
  Screen myScreen(5, 5, 'X');
  myScreen.move(4, 0).set('#').display(std::cout);
  std::cout << '\n';
  myScreen.display(std::cout);
  std::cout << '\n';
}