// Упражнение 10.31. Измените программу из предыдущего упражнения так, чтобы она
// выводила только уникальные элементы. Программа должна использовать алгоритм
// unique_copy().

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::istream_iterator<int> iter_in(std::cin), end_in;
  std::ostream_iterator<int> out(std::cout, " ");

  std::vector<int> vec(iter_in, end_in);

  std::sort(vec.begin(), vec.end());
  std::unique_copy(vec.begin(), vec.end(), out);
}