// Упражнение 12.29. Перепешите цикц взаимодействия с пользователем, используя
// цикл do while (см. раздел 5.4.4, стр. 253). Объясните, какая версия
// предпочтительней и почему.

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

class QueryResult;

class TextQuery {
  friend QueryResult;
  friend std::ostream& print(std::ostream&, QueryResult);

 public:
  TextQuery(std::ifstream& text)
      : vec(std::make_shared<std::vector<std::string>>()),
        map(std::make_shared<std::map<std::string, std::set<int>>>()) {
    std::string str;
    unsigned line_index = 0;
    while (getline(text, str)) {
      vec->push_back(str);

      std::istringstream line(str);
      std::string word;
      while (line >> word) {
        ignorePunct(word);
        tolower(word);
        (*map)[word].insert(line_index);
      }

      ++line_index;
    }
  }

  QueryResult query(const std::string&);

 private:
  std::shared_ptr<std::vector<std::string>> vec;
  std::shared_ptr<std::map<std::string, std::set<int>>> map;
};

class QueryResult {
 public:
  QueryResult(TextQuery obj, std::map<std::string, std::set<int>>::iterator ptr)
      : iter(ptr), vec(obj.vec), map(obj.map) {}

  std::ostream& print(std::ostream& os);

 private:
  std::map<std::string, std::set<int>>::iterator iter;
  std::shared_ptr<std::vector<std::string>> vec;
  std::shared_ptr<std::map<std::string, std::set<int>>> map;
};

QueryResult TextQuery::query(const std::string& s) {
  auto ptr = map->find(s);
  if (ptr != map->end()) return QueryResult(*this, ptr);
  return QueryResult(*this, map->end());
}

std::ostream& QueryResult::print(std::ostream& os) {
  if (iter == map->end())
    return os << "There is no such word in the file." << std::endl;

  os << "element occusr " << iter->second.size()
     << ((iter->second.size() < 2) ? " time" : " times") << std::endl;
  for (auto& elem : iter->second) {
    os << "(line " << elem + 1 << ") " << (*vec)[elem] << std::endl;
  }
  return os;
}

std::ostream& print(std::ostream& os, QueryResult obj) { return obj.print(os); }

void runQueries(std::ifstream& infile) {
  TextQuery tq(infile);
  /* while (true) {
    std::cout << "elnter word to look for, or q to quit: ";
    std::string s;
    if (!(std::cin >> s) || s == "q") break;
    print(std::cout, tq.query(s)) << std::endl;
  } */

  std::string s;  // Пришлось вынести переменную.
  /* do {
    std::cout << "elnter word to look for, or q to quit: ";
    std::cin >> s;  // Перенести ввод сюда.
    print(std::cout, tq.query(s)) << std::endl;
  } while (std::cin && s != "q"); */

  // В целом имеет право на существование, как и первый. Только необходимости
  // правда в проверке после блока кода нет. Можно передать в обычный while().

  while (std::cin >> s && s != "q") {
    std::cout << "elnter word to look for, or q to quit: ";
    std::cin >> s;
    print(std::cout, tq.query(s)) << std::endl;
  }
}

int main() {
  std::ifstream in("exercise-12/terms.txt");
  runQueries(in);
}