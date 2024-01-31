// Упражнение 10.9. Реализуйте собственную версию функции elimDups(). Проверьте
// ее в программе, выводящей содержимое вектора после чтения ввода, после вызова
// функции unuque() и после вызова функции erase().

// Примечание: для того, чтобы функция unic сработала, нужно чтобы повторяющиеся
// элементы были рядом.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void print(std::vector<std::string>& vec) {
  for (auto elem : vec) std::cout << elem << " ";
  std::cout << std::endl;
}

void elimDups(std::vector<std::string>& word) {
  sort(word.begin(), word.end());
  print(word);
  auto end_unic = std::unique(word.begin(), word.end());
  print(word);
  word.erase(end_unic, word.end());
  print(word);
}

int main() {
  std::vector<std::string> svec;
  std::string word;
  while (std::cin >> word) svec.push_back(word);
  elimDups(svec);
}