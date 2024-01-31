// Упражнение 14.37. Напишите класс, проверяющий равенство двух значений.
// Используйте этот объект и библиотечные алгоритмы для написания кода замены
// всех экземпляров заданного значения в последовательности.

#include <algorithm>
#include <iostream>
#include <vector>

class Replace {
 public:
  Replace(int r) : replace(r) {}
  void operator()(int& val) {
    if (val != replace) val = replace;
  }

 private:
  int replace;
};

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6};
  std::for_each(vec.begin(), vec.end(), Replace(5));

  for (auto v : vec) std::cout << v << " ";
  std::cout << std::endl;
}