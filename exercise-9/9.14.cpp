// Упражнение 9.14. Напишите программу, присваивающую значения элементов списка
// указателей на симпольные строки в стиле C (тип char*) элементам вектора
// строк.

#include <list>
#include <string>
#include <vector>

int main() {
  std::list<char*> list = {"John", "Gray", "Alex"};
  std::vector<std::string> vec;

  // Типы контейнеров несовпадают.
  // vec = list;

  // Поскольку типы контейнеров несовпадают необходимо использовать функцию-член
  // assign() диапазоном элементов list.
  vec.assign(list.begin(), list.end());
}