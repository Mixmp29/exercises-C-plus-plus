// Упражнение 11.23. Перепешите карту, хранящую вектора имен детей с ключом в
// виде фамилии семью из упражнений раздела 11.2.1 (стр. 543), так, чтобы
// использовался контейнер multimap.

#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  std::multimap<std::string, std::vector<std::string>> familys;
  std::string first_name;
  std::string last_name;

  while (std::cin >> first_name >> last_name) {
    // Приходится проверять есть ли уже фамилия.
    auto ret = familys.find(last_name);
    if (ret != familys.end())
      ret->second.push_back(first_name);
    else
      familys.insert({last_name, {first_name}});
  }

  for (auto& map : familys) {
    std::cout << map.first << ":" << std::endl;
    for (auto& elem : map.second) std::cout << "\t" << elem << std::endl;
  }
}