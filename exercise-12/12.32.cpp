// Упражнение 12.32. Перепишите классы TextQuery и QueryResult так, чтобы для
// хранения входного файла вместо вектора vector<string> использовался класс
// StrBlob.

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <vector>

#include "StrBlob.h"

using line_no = std::vector<std::string>::size_type;

class QueryResult;

class TextQuery {
 public:
  TextQuery(std::ifstream &);
  QueryResult query(const std::string &) const;

 private:
  StrBlob file;
  std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult {
  friend std::ostream &print(std::ostream &, const QueryResult &);

 public:
  QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, StrBlob f)
      : sought(s), lines(p), file(f) {}

 private:
  std::string sought;
  std::shared_ptr<std::set<line_no>> lines;
  StrBlob file;
};

TextQuery::TextQuery(std::ifstream &is) {
  std::string text;
  while (getline(is, text)) {
    file.push_back(text);
    int n = file.size() - 1;

    std::istringstream line(text);
    std::string word;
    while (line >> word) {
      auto &lines = wm[word];
      if (!lines) lines.reset(new std::set<line_no>);
      lines->insert(n);
    }
  }
}

QueryResult TextQuery::query(const std::string &sought) const {
  static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
  auto loc = wm.find(sought);
  if (loc == wm.end())
    return QueryResult(sought, nodata, file);
  else
    return QueryResult(sought, loc->second, file);
}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
  os << qr.sought << " occurs " << qr.lines->size() << " "
     << ((qr.lines->size() < 2) ? " time" : " times") << std::endl;

  for (auto num : *qr.lines)
    // У StrBlob нет функции, возвращающей значение по индексу, есть только по
    // итератору, но он только прямой, то есть не поддерживает арифметических
    // действий с указателем. Следовательно, либо нужно добавить функцию
    // возвращения значения по индексу, либо по итератору, который может дойти
    // до нужной позиции по числу. Для второго варианта по-хорошему нужно
    // дописать ConstStrBlobPtr до категории указателя произвольного доступа, а
    // для этого нужно добавить арифметические действия, полноценне сравнение,
    // декремент и операции между итераторами. Первый вариант попроще. Если
    // нужно будет, то допишу все, что нужно позже.
    os << "\t(line " << num + 1 << ") " << qr.file.curr(num) << std::endl;

  return os;
}

void runQueries(std::ifstream &infile) {
  TextQuery tq(infile);

  while (true) {
    std::cout << "elnter word to look for, or q to quit: ";
    std::string s;
    if (!(std::cin >> s) || s == "q") break;
    print(std::cout, tq.query(s)) << std::endl;
  }
}

int main() {
  std::ifstream in("exercise-12/terms.txt");
  runQueries(in);
}