// Упражнение 12.28. Напишите программу, реализующую текстовые запросы, не
// определяя классы управления данными. Программа должна получать файл и
// взаимодействовать с пользователем, запрашивая слова, искомые в этом файле.
// Используйте контейнеры vector, map и set для хранения данных из файла и
// создания результатов запросов.

// Ну... Писать такое конечно проще, зато пользователь мог бы пользоваться всего
// тремя строками кода.

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <ostream>
#include <set>
#include <sstream>
#include <vector>

void ignorePunct(std::string& word) {
  word = word.substr(0, word.find_last_of(",.!?-"));
}

void tolower(std::string& word) {
  for (auto& c : word) {
    c = std::tolower(c);
  }
}

int main() {
  std::ifstream in("exercise-12/terms.txt");

  std::vector<std::string> vec;
  std::map<std::string, std::set<int>> map;

  std::string str;
  unsigned line_index = 0;
  while (getline(in, str)) {
    vec.push_back(str);

    std::istringstream line(str);
    std::string word;
    while (line >> word) {
      ignorePunct(word);
      tolower(word);
      map[word].insert(line_index);
    }

    ++line_index;
  }

  std::string find = "my";

  auto ptr = map.find(find);

  if (ptr == map.end())
    std::cout << "There is no such word in the file." << std::endl;

  std::cout << "element occusr " << ptr->second.size()
            << ((ptr->second.size() < 2) ? " time" : " times") << std::endl;

  for (auto& elem : ptr->second) {
    std::cout << "(line " << elem + 1 << ") " << vec[elem] << std::endl;
  }
}