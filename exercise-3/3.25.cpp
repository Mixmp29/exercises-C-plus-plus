#include <iostream>
#include <vector>

// Упражнение 3.25. Перепишите программу кластеризации оценок из раздела 3.3.3
// (стр. 150) с использованием итераторов вместо индексации.

int main() {
  std::vector<unsigned> scores(11, 0);
  unsigned grade;
  while (std::cin >> grade) {
    if (grade <= 100) {
      // std::vector<unsigned>::iterator cluster = scores.begin() + (grade /
      // 10);
      auto cluster = scores.begin() + (grade / 10);
      ++*cluster;
    }
  }

  for (auto& score : scores) {
    std::cout << score << " ";
  }
  std::cout << std::endl;
}