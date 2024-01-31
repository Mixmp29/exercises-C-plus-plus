#include <iostream>
#include <string>

// Упражнение 3.7. Что будет, если определить управляющщую переменную цикла в
// предыдущем упражнении как имеющую тип char? Прескажите результат, а затем
// измените программу так, чтобы использовался тип char, и убедитесь в своей
// правоте.

int main() {
  std::string str("Hello, World!");

  for (char &c : str) {  // Ничего не изменится, так как все символы в
                         // последовательности имеют тип char.
    c = 'X';
  }

  std::cout << str << std::endl;
}