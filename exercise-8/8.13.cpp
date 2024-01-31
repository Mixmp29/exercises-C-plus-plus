#include <fstream>
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

  std::ifstream input("exercise-8/phones.txt");
  std::istringstream record(line);

  while (getline(input, line)) {
    PersonInfo info;
    record.str(line);

    record >> info.name;
    while (record >> word) info.phones.push_back(word);

    people.push_back(info);

    record.clear();
  }

  for (auto elem : people) {
    std::cout << elem.name << " ";
    for (auto phone : elem.phones) std::cout << phone << " ";
    std::cout << std::endl;
  }
}