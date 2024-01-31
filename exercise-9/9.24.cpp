// Упражнение 9.24. Напишите программу, которая обращается к первому элементу
// вектора, используя функции at(), fornt() и begin(), а также оператор
// индексирования. Проверьте программу на пустом векторе.

#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec;

  // Компилятор на это никак не реагирует.

  std::cout << vec.at(0)
            << std::endl;  // Выдает исключение вида std::out_of_range.
  std::cout << vec.front() << std::endl;  // Ошибка сегментирования.
  std::cout << *vec.begin() << std::endl;  // Ошибка сегментирования.
  std::cout << vec[0] << std::endl;  // Ошибка сегментирования.
}