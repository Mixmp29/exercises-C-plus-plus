// Упражнение 8.11. Программа этого раздела определила свой объекта класса
// istringstream во внешнем цикле while. Какие изменения необходимо внести,
// перенеся определение объекта record во вне цикла while, и убедитесь, все ли
// необходимые изменения внесены.

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct PersonInfo {
  std::string name;
  std::vector<std::string> phones;
};

int main() {
  std::string line, word;
  std::vector<PersonInfo> people;

  std::istringstream record(line);  // Содержит копию строки.

  while (getline(std::cin, line)) {
    PersonInfo info;

    record.str(line);  // Берет новую копию строки.

    record >> info.name;
    while (record >> word) info.phones.push_back(word);
    // По окончании цикла record имеет статус failbit() и eofbig().

    people.push_back(info);

    record.clear();
    // Делает record снова допустимым состоянием. Только в этот
    // раз все нормально, так как тип одинаковый (привет из 8.1).
  }

  for (auto elem : people) {
    std::cout << elem.name << " ";
    for (auto phone : elem.phones) std::cout << phone << " ";
    std::cout << std::endl;
  }
}