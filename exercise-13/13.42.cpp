// Упражнение 13.42. Проверьте свой класс StrVec, использовав его в классах
// TextQuery и QueryResult (см. раздел 12.3, стр. 617) вместо вектора
// vector<string>.

// Работает нормально. line_no только оставил прежним.

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <vector>

#include "StrVec.h"

using line_no = std::vector<std::string>::size_type;

class QueryResult;

class TextQuery {
 public:
  TextQuery(std::ifstream &);
  TextQuery(const TextQuery &rhs) : file(std::make_shared<StrVec>(*rhs.file)) {
    // Не получится просто перенести указатели наборов через инициализацию, надо
    // все сделать ручками.
    for (auto map : rhs.wm) {
      wm[map.first] = std::make_shared<std::set<line_no>>(*(map.second));
    }
  }

  TextQuery &operator=(const TextQuery &rhs) {
    file = std::make_shared<StrVec>(*rhs.file);
    for (auto map : rhs.wm) {
      wm[map.first] = std::make_shared<std::set<line_no>>(*(map.second));
    }

    return *this;
  }

  QueryResult query(const std::string &) const;

 private:
  std::shared_ptr<StrVec> file;
  std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult {
  friend std::ostream &print(std::ostream &, const QueryResult &);

 public:
  QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p,
              std::shared_ptr<StrVec> f)
      : sought(s), lines(p), file(f) {}

  std::set<line_no>::iterator begin() const;
  std::set<line_no>::iterator end() const;
  std::shared_ptr<StrVec> get_file() const;

 private:
  std::string sought;
  std::shared_ptr<std::set<line_no>> lines;
  std::shared_ptr<StrVec> file;
};

TextQuery::TextQuery(std::ifstream &is) : file(new StrVec) {
  std::string text;
  while (getline(is, text)) {
    file->push_back(text);
    int n = file->size() - 1;

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

std::set<line_no>::iterator QueryResult::begin() const {
  return lines->begin();
}

std::set<line_no>::iterator QueryResult::end() const { return lines->end(); }

std::shared_ptr<StrVec> QueryResult::get_file() const { return file; }

std::ostream &print(std::ostream &os, const QueryResult &qr) {
  os << qr.sought << " occurs " << qr.lines->size() << " "
     << ((qr.lines->size() < 2) ? " time" : " times") << std::endl;

  for (auto num : *qr.lines)
    os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num)
       << std::endl;

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
  std::ifstream in("exercise-13/terms.txt");
  runQueries(in);
}