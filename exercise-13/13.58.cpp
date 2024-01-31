// Упражнение 13.58. Напишите версию класса Foo с операторами вывода в функциях
// sorted(), чтобы проветить свои ответы на два предыдущих упражнения.

#include <algorithm>
#include <iostream>
#include <vector>

class Foo {
 public:
  Foo sorted() &&;
  Foo sorted() const &;

  /*  private: */  // Прикрою на время проверки.
  std::vector<int> data = {1, 3, 2};
};

Foo Foo::sorted() && {
  std::cout << "sorted() &&" << std::endl;
  std::sort(data.begin(), data.end());
  return *this;
}

/* Foo Foo::sorted() const & {
  std::cout << "sorted() const &" << std::endl;
  Foo ret(*this);
  std::sort(ret.data.begin(), ret.data.end());
  return ret;
} */

/* Foo Foo::sorted() const & {
  std::cout << "sorted1() const &" << std::endl;
  Foo ret(*this);
  return ret.sorted();
} */

Foo Foo::sorted() const & {
  std::cout << "sorted2() const &" << std::endl;
  // Копирует объект значение *this, тем самым возвратив r-value, которое пойдет
  // на сортировку. После возвращается копия результата на этого r-value.
  return Foo(*this).sorted();
}

int main() {
  Foo val;
  Foo val2 = val.sorted();

  // Вектор в val не изменен.
  for (auto v : val.data) std::cout << v << " ";
  std::cout << std::endl;

  for (auto v : val2.data) std::cout << v << " ";
  std::cout << std::endl;
}