#include <iostream>
#include <iterator>
// Упражнение 3.45. Перепешите программы снова, на сей раз используя
// спецификатор auto.

int main() {
  int ia[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  for (auto &row : ia) {
    for (auto &col : row) {
      std::cout << col << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "--------------" << std::endl;

  for (size_t i = 0; i < 3; ++i) {
    for (size_t j = 0; j < 4; ++j) {
      std::cout << ia[i][j] << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "--------------" << std::endl;

  for (auto prow = std::begin(ia); prow != std::end(ia); ++prow) {
    for (auto pcol = std::begin(*prow); pcol != std::end(*prow); ++pcol) {
      std::cout << *pcol << " ";
    }
    std::cout << std::endl;
  }
}