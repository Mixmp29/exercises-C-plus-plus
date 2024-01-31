// Упражнение 10.5. Что произойдет, если в вызове функции equal() для списков
// оба из них будут содержать строки в стиле C, а не библиотечные строки?

// Все будет нормально, так как для сравнения используется допустимый для обоих
// типов оператор '=='.

#include <algorithm>
#include <iostream>

int main() {
  const char arr1[] = "string1";
  const char arr2[] = "string1";

  std::cout << std::equal(std::begin(arr1), std::end(arr1), arr2) << std::endl;
}