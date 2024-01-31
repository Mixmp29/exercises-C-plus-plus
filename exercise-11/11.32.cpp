// Упражнение 11.32. Используя контейнер multimap из предыдущего упражнения,
// напишите программу вывода списка авторов и их работ в алфавитном порядке.

#include <algorithm>
#include <iostream>
#include <map>
#include <string>

bool sort_elem(const std::pair<std::string, const std::string> a,
               std::pair<std::string, std::string> b) {
  return a.second[0] < b.second[0];
};

int main() {
  std::multimap<std::string, std::string> author;
  author.insert({"Tolstoy", "War and Peace"});
  author.insert({"Tolstoy", "Anna Karenina"});
  author.insert({"Dostoevsky", "Dead Souls"});
  author.insert({"Dostoevsky", "Сrime and punishment"});

  // Придумал только использовать вспомогательный вектор, который в последствии
  // отсортируется и копируется обратно в map.

  std::vector<std::pair<std::string, std::string>> v(author.begin(),
                                                     author.end());

  std::sort(v.begin(), v.end(), sort_elem);

  std::copy(v.begin(), v.end(), std::inserter(author, author.end()));
  std::multimap<std::string, std::string> author2(v.begin(), v.end());

  for (auto &elem : author2) {
    std::cout << elem.first << ": " << elem.second << std::endl;
  }
}