// Упражнение 10.11. Напишите программу, ипользующую функции stable_sort() и
// isShorter() для сортировки вектора, переданного вашей версии функции
// elimDups(). Для проверки правильности программы выведите содержимое вектора.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool isShorter(const std::string& str1, const std::string& str2) {
  return str1.size() < str2.size();
}

void print(std::vector<std::string>& vec) {
  for (auto elem : vec) std::cout << elem << " ";
  std::cout << std::endl;
}

void elimDups(std::vector<std::string>& word) {
  std::sort(word.begin(), word.end());  // Здесь stable_sort лучше не ставить,
                                        // так как поменяется после unique.
  auto end_unic = std::unique(word.begin(), word.end());
  word.erase(end_unic, word.end());
}

int main() {
  std::vector<std::string> svec;
  std::string word;
  while (std::cin >> word) svec.push_back(word);
  elimDups(svec);
  std::stable_sort(svec.begin(), svec.end(), isShorter);
  print(svec);
}