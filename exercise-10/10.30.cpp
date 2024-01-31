// Упражнение 10.30. Используйте потоковые итераторы, а также функции sort() и
// copy() для чтения последовательности целых чисел со стандартного устройства
// ввода, их сортировки и последующего вывода на стандартное устройство вывода.

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::istream_iterator<int> iter_in(std::cin), end_in;
  std::ostream_iterator<int> out(std::cout, " ");

  // Не получится просто запихать итераторы cin в sort() и copy(). Компилятор
  // как минимум говорит, что у итераторов не предусмотрена операция разницы '-'
  // между ними.
  std::vector<int> vec(iter_in, end_in);

  std::sort(vec.begin(), vec.end());
  std::copy(vec.begin(), vec.end(), out);
}