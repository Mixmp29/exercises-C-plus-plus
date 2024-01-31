// Упражнение 12.27. Классы TextQuery и QueryResult используют только те
// возможности, которые уже были описаны ранее. Не заглядывая вперед напишите
// собственные версии этих классов.

// На момент выполнения этого задания я не очень разобрался, полчему результат
// функции query() должен храниться в QueryResult. Как минимум в моей реализации
// можно было обойтись без вспомогательного объекта.

// В общем, привет из будущего. Указатель должен быть не на карту, а на набор в
// карте. Функция print() должна быть только дружественной и только у
// QueryResult. В QueryResult достаточно хранить искомую строк, указатель на
// вектор и указатель на набор.

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
  friend void print(std::ostream&, QueryResult);

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

  QueryResult query(std::string);

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

QueryResult TextQuery::query(std::string s) {
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

void print(std::ostream& os, QueryResult obj) { obj.print(os); }

int main() {
  std::ifstream in("exercise-12/terms.txt");
  TextQuery tq(in);

  print(std::cout, tq.query("my"));
}