// Упражнение 9.41. Напишите программу, инициализирующую строки из вектора
// vector<char>.

#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<char> sv = {'h', 'e', 'l', 'l', 'o'};
  std::string str1(sv.begin(), sv.end());

  std::cout << str1 << std::endl;
}