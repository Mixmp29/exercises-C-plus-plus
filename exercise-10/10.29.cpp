// Упражнение 10.29. Напишите программу, использующую потоковые итераторы для
// чтения текстового файла в вектор строк.

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main() {
  std::ifstream in("exercise-10/Заметки.txt");
  std::istream_iterator<std::string> iter_in(in), end_in;
  std::vector<std::string> text(iter_in, end_in);

  for (auto elem : text) std::cout << elem << ' ';
  std::cout << std::endl;
}