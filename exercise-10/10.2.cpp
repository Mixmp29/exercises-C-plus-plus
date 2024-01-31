// Упражнение 10.2. Повторите предыдущую программу, но чтение значений
// организуйте в список (list) строк.

#include <algorithm>
#include <iostream>
#include <list>

int main() {
  std::list<int> list;
  int val;
  while (std::cin >> val) list.push_back(val);

  auto result = std::count(list.begin(), list.end(), 15);

  std::cout << "Count of elements in list: " << result << std::endl;
}