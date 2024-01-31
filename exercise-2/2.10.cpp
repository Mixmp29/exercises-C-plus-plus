#include <iostream>

// Упражнение 2.10. Каковы исходные значения, если таковые вообще имеются,
// каждой из следующих переменных.

std::string global_str;  // Инициализацияя по умолчанию ""
int global_int;  // Инициализацияя по умолчанию 0

int main() {
  int local_int;  // Внутри функций у int нет инициализациии по умолчанию.
                  // Значение неопределено. Может быть любое число.
  std::string local_str;  // Инициализацияя по умолчанию ""

  std::cout << global_str << " and " << local_str << std::endl;
  std::cout << global_int << " and " << local_int << std::endl;
}