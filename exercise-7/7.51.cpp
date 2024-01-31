// Упражнение 7.51. Как, по вашему, почему вектор определяет свой конструктор с
// одним аргументом как явный, а строка нет?

// Для удобвства и понимания кода.

// Для строки удобно в определении просто писать константный литерал в
// определении, вместо явного преобразования из const char* в string каждый раз.

// Для вектора же такое поведение может сбить с толку: будет неясно, что
// использовать как тип вектора, неясно чем заполнится вектор.

#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string s = "string";
  // Какой тип ставить: char, const char* или string?
  // Если это будет string, то в объект пойдет строка как первый элемент?
  // Если const char*, тот же самый вопрос.
  // Если char, то это будет последовательность char'ов?
  // std::vector<std::string> vec(s);

  std::vector<std::string> vec({s});
  // Все таки надо определять, либо явно объектом, либо int'ом для количества
  // элементов в екторе

  std::cout << vec[0] << std::endl;
}