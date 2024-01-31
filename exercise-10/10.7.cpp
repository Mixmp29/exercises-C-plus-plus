// Упражнение 10.7. Определите, есть ли ошибки в следующих фрагментах кода, и,
// если есть, как их исправить:

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main() {
  // (a) Вектор vec пустой. Функция copy подразумевает, что vec дожен быть
  // длинной не меньше list. Можно поставить итератор back_inserter().
  // Возращаемое значение функции не обязательно присваивать.

  // Заметка: алгоритм copy() возвращает итератор на конец последовательности, в
  // которую записывают копию элементов. Точнее на следующий после
  // скопированного.

  std::vector<int> vec;
  std::list<int> lst;
  int i;
  while (std::cin >> i) lst.push_back(i);
  std::copy(lst.begin(), lst.end(), std::back_inserter(vec));

  // (b) Как бы резерв есть, но vec все равно пуст, так что это не сработает.
  // Можно сделать вместо этого resize().

  std::vector<int> vec2;
  vec2.resize(10);
  fill_n(vec2.begin(), 10, 0);  // Хотя, если тут 0, тожно убрать, так как по
                                // умолчанию в vec значения уже имеют 0.

  for (auto elem : vec) std::cout << elem << " ";
  std::cout << std::endl;

  for (auto elem : vec2) std::cout << elem << " ";
  std::cout << std::endl;
}