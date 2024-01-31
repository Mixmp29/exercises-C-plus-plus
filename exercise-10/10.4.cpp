// Упражнение 10.4. Если вектор v имеет тип vector<double>, в чем состоит ошибка
// вызова accumulate(v.cbegin(), v.cend(), 0) (если она есть)?

// Технически ошибки нет, так как тип int может суммировать double, однако
// результатом суммирования будет int значение. Более того суммирование int
// будет преобразовывать double в int до сложения.

#include <iostream>
#include <numeric>
#include <vector>

int main() {
  std::vector<double> dvec = {0.1, 0.2, 0.3, 4.9, 3.5};  // 9
  std::cout << std::accumulate(dvec.begin(), dvec.end(), 0) << std::endl;
}