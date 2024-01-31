// Упражнение 9.13. Как инициализировать контейнер vector<double> из контейнера
// list<int> и контейнера vector<int>? Напишите код для проверки ответов.

#include <iostream>
#include <list>
#include <vector>

int main() {
  std::list<int> list = {1, 2, 3};
  std::vector<int> vec{4, 5, 6};

  std::vector<double> vecList(list.begin(), list.end());
  // std::vector<double> vecVec = vec;  // Так нельзя, разные типы контейнеров.
  std::vector<double> vecVec(vec.begin(), vec.end());

  for (auto elem : vecList) std::cout << elem << " ";
  std::cout << std::endl;

  for (auto elem : vecVec) std::cout << elem << " ";
  std::cout << std::endl;
}