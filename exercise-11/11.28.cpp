// Упражнения 11.28. Определите и инициализируйте переменную, содержащую
// результат вызова функции find() для карты строк и векторов целых чисел.

#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

int main() {
  std::map<std::string, std::vector<int>> map = {{"Vector: ", {1, 2, 3}}};
  std::map<std::string, std::vector<int>>::iterator map_it =
      map.find("Vector: ");

  std::cout << map_it->first;

  for (auto elem : map_it->second) std::cout << elem << " ";
  std::cout << std::endl;
}