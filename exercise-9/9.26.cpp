// Упражнение 9.26. Используя приведенное ниже определение массива ia,
// скопируйте его содержимое в вектор и в список. Используя версию функции
// erase() для одного итератора, удалите из списка элемент с нечетными
// значениями, а из вектора - с нечетными.

#include <iostream>
#include <list>
#include <vector>

int main() {
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};

  std::vector<int> vec(std::begin(ia), std::end(ia));
  std::list<int> list(std::begin(ia), std::end(ia));

  auto vb = vec.begin(), ve = vec.end();
  auto lb = list.begin(), le = list.end();

  while (lb != le) {
    if (*lb % 2)
      lb = list.erase(lb);
    else
      ++lb;
  }

  while (vb != ve)
    if (*vb % 2 == 0)
      vb = vec.erase(vb);
    else
      ++vb;

  for (auto i : list) std::cout << i << ' ';
  std::cout << std::endl;
  for (auto i : vec) std::cout << i << ' ';
  std::cout << std::endl;
}