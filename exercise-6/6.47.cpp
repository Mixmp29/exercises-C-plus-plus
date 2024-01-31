#define NDEBUG  // Работает, если находится выше include.

#include <cassert>
#include <iostream>
#include <vector>

// Упражнение 6.47. Пересмотрите программу, написанную в упражнениее
// раздела 6.3.2 (стр. 299), где использовалась рекурсия для отображения
// содержимого вектора так, чтобы условно отображать информацию о ее выполнении.
// Например, отобразите размер вектора при каждом вызове. Откмпилируйте и
// запустите программу с влченное отладкой и с выключенной.

std::vector<int>::iterator print(std::vector<int>::iterator begin,
                                 std::vector<int>::iterator end) {
  // Выведет ошибку, если определена переменная препроцессора NDEBUG.
  assert(0);
  std::cerr << "In file " << __FILE__
            << " size of vector subset: " << end - begin << std::endl;
  if (begin != end) std::cout << *print(begin, end - 1) << std::endl;
  return end;
}

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};
  print(v.begin(), v.end());
}