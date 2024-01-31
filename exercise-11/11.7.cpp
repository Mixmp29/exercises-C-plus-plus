// Упражнение 11.7. Определите карту, ключ которой является фамилией семьи, а
// значение - вектором имен детей. Напишите код, способный добавлять новые семьи
// и новых детей в существующие семьи.

#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  std::map<std::string, std::vector<std::string>> familys;
  std::string first_name;
  std::string last_name;

  while (std::cin >> first_name >> last_name) {
    familys[last_name].push_back(first_name);
  }

  for (auto& map : familys) {
    std::cout << map.first << ":" << std::endl;
    for (auto& elem : map.second) std::cout << "\t" << elem << std::endl;
  }
}