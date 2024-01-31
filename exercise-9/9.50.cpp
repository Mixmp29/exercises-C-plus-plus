// Упражнение 9.50. Напишите программу обработку вектора vector<string>,
// элементы которого представляют целочисленные значения. Вычислите сумму всех
// элементов вектора. Измените программу так, чтобы она суммировала строки,
// которые представляют значения с плавающей точкой.

#include <iostream>
#include <string>
#include <vector>

int main() {
  /* std::vector<std::string> svec = {"12", "36", "1", "3"};
  int result;
  for (auto item : svec) {
    result += std::stoi(item);
  }

  std::cout << result << std::endl; */

  std::vector<std::string> svec = {"12", "36", "1", "3", "3.15", "2.16"};
  double result;
  for (auto item : svec) {
    if (item.find_first_of(".") != std::string::npos) result += std::stod(item);
  }

  std::cout << result << std::endl;
}