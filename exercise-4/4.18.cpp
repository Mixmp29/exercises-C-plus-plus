#include <iostream>
#include <vector>

// Упражнение 4.18. Что будет, если цикл while на странице 207 (скорее всего
// имелось в виду 205), исполуемый для отображения элементов вектора,
// задействует префиксный оператор инкремента?

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5, 6, -1, 3, 6};
  auto pbeg = v.begin();

  while (pbeg != v.end() && *pbeg >= 0) {
    std::cout << *++pbeg << std::endl;
  }
  // Программа будет работать некорректно. Для начала вывод вектора начется со
  // второй позиции, то есть с индекса 1. В первом случае программа дойдет до
  // отрицательного числа, выведет его, а только потом выйдет из цикла. Во
  // втором случае она может дойти до конца вектора и попытаться вывести
  // значение за последним элементом вектора.
}