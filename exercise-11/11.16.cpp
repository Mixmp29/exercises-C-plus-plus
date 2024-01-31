// Упражнение 11.16. Используя итератор карты, напишите выражение, присваивающее
// значение элементу.

#include <iostream>
#include <map>

int main() {
  std::map<int, int> map = {{1, 1}, {2, 1}};
  auto map_it = map.begin();
  (++map_it)->second = 2;
  std::cout << map_it->first << " " << map_it->second << std::endl;
}