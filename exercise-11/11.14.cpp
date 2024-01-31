// Упражнение 11.14. Дополните карту фамилии семей и их детей, написанную для
// упражнения в разделе 11.2.1 (стр. 543), вектором пар, содержащих имя ременка
// и день его рождения. (Это упражнение 11.7).

#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

int main() {
  std::map<std::string, std::vector<std::pair<std::string, std::string>>>
      familys;
  std::string first_name;
  std::string last_name;
  std::string birthday;

  while (std::cin >> first_name >> last_name >> birthday) {
    familys[last_name].push_back({first_name, birthday});
  }

  for (auto& map : familys) {
    std::cout << map.first << ":" << std::endl;
    for (auto& elem : map.second)
      std::cout << "\t" << elem.first << " " << elem.second << std::endl;
  }
}