// Упражнение 14.42. Используя библиотечные объект и адаптеры функций,
// определите объекты для:

#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std::placeholders;  // Не забыть эту штуку.

//(a) Подсчета количеств значений больше 1024
struct A {
  int operator()(std::vector<int>& vec) {
    return std::count_if(vec.begin(), vec.end(),
                         std::bind(std::greater<int>(), _1, 1024));
    // Очень долго не мог додуматься до этой фигни. Нашел
    // на формуе хотя бы.
  }
};

//(b) Поиск первой строки, не равной pooh
struct B {
  std::vector<std::string>::iterator operator()(std::vector<std::string>& vec) {
    return std::find_if(
        vec.begin(), vec.end(),
        std::bind(std::not_equal_to<std::string>(), _1, "pooh"));
  }
};

//(c) Умножения всех значений на 2
struct C {
  void operator()(std::vector<int>& vec) {
    std::transform(vec.begin(), vec.end(), vec.begin(),
                   std::bind(std::multiplies<int>(), _1, 2));
    // for (auto& v : vec) v = std::multiplies<int>()(v, 2);
  }
};

int main() {
  std::vector<int> vec = {1234, 342, 5235, 23, 23, 434, 102};
  std::cout << A()(vec) << std::endl;

  C()(vec);

  for (auto v : vec) std::cout << v << " ";
  std::cout << std::endl;
}
