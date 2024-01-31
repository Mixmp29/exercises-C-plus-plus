// Упражнение 13.21. Должны ли класс TextQuery и QueryResult определять
// собственные версии функци-членов управления копированием? Если да, то почему?
// Если нет, то почему? Реализуйте функции управления копированием, необходимые,
// по-вашему в этих классах.

// Все зависит от того, какую реализацию мы хотим. Нынешняя реализация при
// копировании любого вида попросту будет указывать на тот же объект.
// Если же по каким-либо причинам необходимо создавать указатели на отдельные
// элементы, то нужно создать эти фукнкции явно и выделять память для каждого
// указателя, который будет указывать на ЗНАЧЕНИЕ по указателю исходного
// объекта.

// Честно говоря я не вижу надобности в подобном. Искомые слова можно найти
// через повторное использование запросов, а для нового объекта наверное
// захочется взять новый файл. Могу предположить, что это пожно сделать для
// параллельного поиска разных слов, но в такой реализации куча своих нюансов.

// Но чисто для тренировки можно дописать пару строк. Допишу инициализацию
// копией и оператор присвоения копией. Деструктор по умолчанию справится со
// всем сам.

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
  TextQuery(const TextQuery &rhs)
      : file(std::make_shared<std::vector<std::string>>(*rhs.file)) {
    // Не получится просто перенести указатели наборов через инициализацию, надо
    // все сделать ручками.
    for (auto map : rhs.wm) {
      wm[map.first] = std::make_shared<std::set<line_no>>(*(map.second));
    }
  }

  TextQuery &operator=(const TextQuery &rhs) {
    file = std::make_shared<std::vector<std::string>>(*rhs.file);
    for (auto map : rhs.wm) {
      wm[map.first] = std::make_shared<std::set<line_no>>(*(map.second));
    }
  }

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

  // Не вижу надобности в определении копирования любого вида для этого класса,
  // так как пока он используется только классом TextQuery, который использует
  // этот объект только для запроса и вывода. Да и смысл теряется немного, если
  // сделать инициализацию копирования с отдельным набором, то он не будет
  // указывать на объект в карте. В общем много нюансов в зависимости от
  // требуемого решения задачи.

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