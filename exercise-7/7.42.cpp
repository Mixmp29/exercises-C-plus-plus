// Упражнение 7.42. Вернитесь к классу, написанному для упражнения 7.40 в
// разделе 7.5.1 (стр. 377), и решите, может ли какой-нибудь изего контрукторов
// использовать елегирование. Если да, то напишите делегирующий конструктор
// (конструкторы) для своего класса. В противно случае рассмотрите список
// абстракций и выберите ту, которая, по вашему исползовала бы делегирующий
// конструктор. Напишите определение класса этой абстракции.

#include <iostream>
#include <string>
#include <vector>

class Diary {
  friend Diary compareEntry(const Diary&, const Diary&);
  friend std::istream& read(std::istream&, Diary&);
  friend std::ostream& print(std::ostream&, const Diary&);

 public:
  Diary(int d, int m, int y, const std::string& s)
      : day(d), moth(m), year(y), entries({s}) {}

  Diary() : Diary(0, 0, 0, {}){};
  Diary(int d, int m, int y) : Diary(d, m, y, {}) {}

  Diary& changeDate(int, int, int);
  Diary& addEntries(std::istream&);
  Diary& TransferEntries(const Diary&);

 private:
  Diary& pushEntries(const Diary& item) {
    for (const std::string& elem : item.entries) entries.push_back(elem);

    return *this;
  }

  int day = 0;
  int moth = 0;
  int year = 0;
  std::vector<std::string> entries;
};

int main() {}