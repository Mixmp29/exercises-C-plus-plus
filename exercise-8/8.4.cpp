// Упражнение 8.4. Напишите функцию, которая открывает файл и читает его
// содержимое в вектор строк, сохраняя каждую строку как отдельный элемент
// вектора.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void readFile(std::vector<std::string>& vec) {
  std::string str;

  std::ifstream input("Заметки");

  if (input) {
    while (getline(input, str)) vec.push_back(str);
  }

  input.close();  // Выйдя из области видимости input удалится, а файл
                  // закроется, но для ясности я явно закрыл файл.
}

int main() {
  std::vector<std::string> vec;

  readFile(vec);

  for (auto elem : vec) std::cout << elem << std::endl;
}