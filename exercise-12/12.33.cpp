// Упражнение 12.33. В главе 15 программ запроса будет дополнена, и классу
// QueryResult понадобятся дополнительные члены. Добавьте функции-члены по имени
// begin() и end(), возвращающие итераторы для набора номеров строк,
// возвращенных данным запросом, и функцию-член get_fine(), возвращающую
// указатель shared_ptr на файл в объекте QueryResult.

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <vector>

using line_no = std::vector<std::string>::size_type;

class QueryResult;

class TextQuery {
 public:
  TextQuery(std::ifstream &);
  QueryResult query(const std::string &) const;

 private:
  std::shared_ptr<std::vector<std::string>> file;
  std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult {
  friend std::ostream &print(std::ostream &, const QueryResult &);

 public:
  QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p,
              std::shared_ptr<std::vector<std::string>> f)
      : sought(s), lines(p), file(f) {}

  std::set<line_no>::iterator begin() const;
  std::set<line_no>::iterator end() const;
  std::shared_ptr<std::vector<std::string>> get_file() const;

 private:
  std::string sought;
  std::shared_ptr<std::set<line_no>> lines;
  std::shared_ptr<std::vector<std::string>> file;
};

TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<std::string>) {
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

std::shared_ptr<std::vector<std::string>> QueryResult::get_file() const {
  return file;
}

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
  std::ifstream in("exercise-12/terms.txt");
  runQueries(in);
}