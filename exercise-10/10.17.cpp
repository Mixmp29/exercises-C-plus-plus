// Упражнение 10.17. Перепишите упражнение 10.12 из раздела 10.3.1 (стр. 496)
// так, чтобы в вызове функции sort() вместо функции compareIsbn()
// использовалось лямбда_выражение.

#include <algorithm>
#include <iostream>
#include <vector>

#include "Sales_data3.h"

int main() {
  std::vector<Sales_data> SDvec = {Sales_data("978-5-8459-1839-4"),
                                   Sales_data("978-5-8459-1839-2"),
                                   Sales_data("978-5-8459-1134-0")};

  std::stable_sort(SDvec.begin(), SDvec.end(),
                   [](const Sales_data& item1, const Sales_data& item2) {
                     return item1.isbn() < item2.isbn();
                   });

  for (auto elem : SDvec) print(std::cout, elem) << std::endl;
}