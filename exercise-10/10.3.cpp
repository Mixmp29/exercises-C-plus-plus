// Упражнение 10.3. Примените функцию accumulate() для суммирования элементов
// вектора vector<int>

#include <iostream>
#include <numeric>
#include <vector>

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << std::accumulate(vec.begin(), vec.end(), 0) << std::endl;
}