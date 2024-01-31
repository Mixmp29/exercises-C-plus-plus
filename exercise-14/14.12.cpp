// Упражнение 14.12. Определите оператор ввода для класса, использованного в
// упражнении  7.40 раздела 7.5.1 (стр. 377). Обеспечьте обработку оператором
// ошибок ввода.

#include <iostream>
#include <string>
#include <vector>

class Diary {
  // Дружеское отношение необходим для доступа к закрытым членам.
  friend Diary compareEntry(const Diary&, const Diary&);
  friend std::ostream& operator<<(std::ostream&, const Diary&);
  friend std::istream& operator>>(std::istream&, Diary&);

 public:
  Diary() = default;  // Стандартный конструктор, так как оперделены еще два, а
                      // аргумент по умолчанию одним параметром ни один
                      // конструктор не инициализирован.
  Diary(int d, int m, int y) : day(d), moth(m), year(y) {}  // Дата без записи.
  Diary(int d, int m, int y, const std::string& s)  // Дата с записью.
      : day(d), moth(m), year(y), entries({s}) {}

  // Константныйх членов-функций нет, так как они все меняют значения объекта.
  // Также константность объекта или ссылка на константный объект ставится в
  // случае, если параметр не будет изменяться по ходу программы.
  // У членов-функции возвращаемое значение типа ссылки на Diary для того, чтобы
  // изменялся сам объект в случае объединенных вызовов, а не копия результата.

  Diary& changeDate(int, int, int);  // Поменять дату у объекта.
  Diary& addEntry(const std::string&);  // Добавить запись у объекту.
  Diary& addEntries(std::istream&);  // Добавить серию записей в объект.
  // Добавить объекту записи из другого объекта.
  Diary& TransferEntries(const Diary&);

 private:
  Diary& pushEntries(const Diary& item) {
    for (const std::string& elem : item.entries) entries.push_back(elem);

    return *this;
  }

  int day = 0;                       // День.
  int moth = 0;                      // Месяц.
  int year = 0;                      // Год.
  std::vector<std::string> entries;  // Записи строкой.
};

Diary& Diary::changeDate(int d, int m, int y) {
  day = d;
  moth = m;
  year = y;

  return *this;
}

Diary& Diary::addEntry(const std::string& s) {
  entries.push_back(s);

  return *this;
}

Diary& Diary::addEntries(std::istream& is) {
  std::string entry;
  while (getline(is, entry)) entries.push_back(entry);

  return *this;
}

Diary& Diary::TransferEntries(const Diary& item) {
  // Каждый элемент записи item.entries добавить в this->entries.
  pushEntries(item);

  return *this;
}

// Объединить записи. Возвращает новый объект записей.
Diary compareEntry(const Diary& lhs, const Diary& rhs) {
  Diary sum = lhs;

  // Каждый элемент записи rhs.entries добавить в sum.entries.
  sum.pushEntries(rhs);

  return sum;
}

// Вывод содержимого объекта в терминал. Возвращает объект ostream;
std::ostream& operator<<(std::ostream& os, const Diary& item) {
  os << "\nDate: " << item.day << "." << item.moth << "." << item.year;
  os << "\nEntries:\n";
  for (const std::string& elem : item.entries)
    os << "\t* " << elem << std::endl;

  return os;
}

// Чтение содержимого потока ввода в объект. Возвращает объект istream;
std::istream& operator>>(std::istream& is, Diary& item) {
  std::string entry;
  is >> item.day >> item.moth >> item.year;
  if (is) {
    item.entries.clear();
    std::cin.ignore();  // В конце cin есть '\n'. Этот вызов позволит убрать
                        // этот лишний символ.
    while (getline(is, entry)) item.entries.push_back(entry);
  } else
    item = Diary();

  return is;
}

int main() {
  Diary plan(12, 12, 2023, "Sit home and do homework.");
  plan.addEntry("Cook the fish.");
  std::cout << plan;

  std::cin >> plan;
  std::cout << plan;

  Diary plan2;
  std::cout << plan2;

  plan2.changeDate(14, 12, 2023).TransferEntries(plan).addEntry("Play in COD.");
  std::cout << plan2;

  Diary plan3(15, 12, 2023);
  plan3.addEntries(std::cin);
  std::cout << plan3;

  Diary plan4 = compareEntry(plan2, plan3).changeDate(17, 12, 2023);
  std::cout << plan4;
}