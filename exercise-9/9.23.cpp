// Упражнение 9.23. Какими были бы значения переменных val2, val3 и val4, в
// первой прогорамме данного раздела стр. 445, если бы функция c.size()
// возвращала значение 1?

// Все будут равны значению первого элемента, так как он также является и
// последним.

#include <iostream>
#include <vector>

int main() {
  std::vector<int> c = {1};

  if (!c.empty()) {
    auto val = *c.begin(), val2 = c.front();  // val2 = 1;

    auto last = c.end();

    auto val3 = *(--last);  // val3 = 1;
    auto val4 = c.back();   // val4 = 1;

    std::cout << val2 << std::endl;
    std::cout << val3 << std::endl;
    std::cout << val4 << std::endl;
  }
}