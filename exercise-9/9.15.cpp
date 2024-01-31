// Упражнение 9.15. Напишите программу, выясняющую, равны ли два векора
// vector<int>.

#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec1 = {1, 2, 3};
  std::vector<int> vec2 = {1, 2, 3};

  std::cout << (vec1 == vec2 ? true : false) << std::endl;
}