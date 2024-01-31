// Упражнение 8.10. Напишите программу для сохранения каждой строки из файла в
// векторе vector<string>. Затем используйте объект класса istringstream для
// чтения каждого элемента из вектора по одному слову за раз.

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void readFile(std::vector<std::string>& vec) {
  std::string str;

  std::ifstream input("Заметки");

  if (input) {
    while (getline(input, str)) vec.push_back(str);
  }

  input.close();
}

int main() {
  std::vector<std::string> vec;

  readFile(vec);

  for (auto elem : vec) {
    std::string s;
    std::istringstream word(elem);
    while (word >> s) std::cout << s << std::endl;
  }
}