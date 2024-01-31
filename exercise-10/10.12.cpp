// Упражнение 10.12. Напишите функцию compareIsbn(), которая сравинвает члены
// isbn двух объектов класса Sales_data. Используйте эту функцию для сортировки
// вектора объектов класса Sales_data.

#include <algorithm>
#include <iostream>
#include <vector>

#include "Sales_data3.h"

bool compareIsbn(const Sales_data& item1, const Sales_data& item2) {
  return item1.isbn() < item2.isbn();
}

int main() {
  std::vector<Sales_data> SDvec = {Sales_data("978-5-8459-1839-4"),
                                   Sales_data("978-5-8459-1839-2"),
                                   Sales_data("978-5-8459-1134-0")};

  std::stable_sort(SDvec.begin(), SDvec.end(), compareIsbn);

  for (auto elem : SDvec) print(std::cout, elem) << std::endl;
}