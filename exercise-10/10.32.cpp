// Упражнение 10.32. Перепешите програму книжного магазина из раздела 1.6 (стр.
// 52). Используйте вектор для хранения транзакции и различные алгоритмы для
// обработки. Используйте алгоритм sort() с собственной функцией compareIsbn()
// из раздела 10.3.1 (стр.496) для упорядочивания транзакций, а затем
// используйте алгоритмы find() и accumulate() для вычисления суммы.

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

#include "Sales_item.h"

bool lessIsbn(const Sales_item& item1, const Sales_item& item2) {
  return item1.isbn() < item2.isbn();
}

// Мне кажется, что я перемудрил и можно было сделать это гораздо проще
// (возможно). Как есть, так есть. Долго голова доходила для такого алгоритма.

int main() {
  std::istream_iterator<Sales_item> iter_in(std::cin), end_in;
  std::vector<Sales_item> trans(iter_in, end_in);

  std::sort(trans.begin(), trans.end(), lessIsbn);

  auto beg_trans = trans.begin();
  auto end_trans = trans.end();

  while (beg_trans != trans.end()) {
    end_trans = std::find_if(beg_trans, trans.end(),
                             [beg_trans](const Sales_item& trans) {
                               return beg_trans->isbn() != trans.isbn();
                             });

    Sales_item total =
        std::accumulate(beg_trans, end_trans, Sales_item(beg_trans->isbn()));
    std::cout << total << std::endl;

    beg_trans = end_trans;
  }

  std::cout << "--------------------------" << std::endl;
  for (auto elem : trans) std::cout << elem << std::endl;

  return 0;
}

/* int main() {
  Sales_item total;

  if (std::cin >> total) {
    Sales_item trans;

    while (std::cin >> trans) {
      if (total.isbn() == trans.isbn()) {
        total += trans;
      } else {
        std::cout << total << std::endl;
        total = trans;
      }
    }
    std::cout << total << std::endl;
  } else {
    std::cerr << "No data?!" << std::endl;
    return -1;
  }

  return 0;
} */