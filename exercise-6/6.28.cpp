#include <initializer_list>
#include <iostream>

// Упражнение 6.28. Во второй версии функции error_msg(), где у нее есть
// параметр типа ErrCode, каков тим элемента в цикле for?

struct ErrCode {
  int msg() { return 0; }  // заглушка
};

void error_msg(ErrCode e, std::initializer_list<std::string> il) {
  std::cout << e.msg() << ": ";
  for (const auto &elem : il) std::cout << elem << " ";
  std::cout << std::endl;
}

// Тип управляющей переменной является string, так как элементы в массиве имеют
// тот же тип.