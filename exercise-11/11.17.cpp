// Упражнение 11.17. C учетом того, что c - контейнер multiset строк, а v -
// вектор строк, объясните следующие вызовы. Укажите, допустим ли каждый из них:

// В начале я невнимательно прочитал заание и выполнил его c multimap. Написал
// много, поэтому снизу оставлю записи.

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

int main() {
  std::multiset<std::string> c = {"string5", "string6"};

  std::multimap<int, std::string> c1 = {{1, "string3"}, {2, "string4"}};
  std::multimap<int, std::string> c2 = {{1, "string1"}, {2, "string2"}};

  std::vector<std::string> v = {"some", "string", "here"};

  // Допустимо. Последовательность переносит только элементы, а в наборе ключи и
  // есть элементы.
  std::copy(v.begin(), v.end(), std::inserter(c, c.end()));

  // Допустимо. Даже, если у set нет push_back().
  // push_back().
  // std::copy(v.begin(), v.end(), std::back_inserter(c));

  // Тоже самое, что и сверху.
  // std::copy(c.begin(), c.end(), std::inserter(v, v.end()));

  // Тоже самое, что и сверху.
  // std::copy(c.begin(), c.end(), std::inserter(v, v.end()));

  // Вариант c map.

  // Судя по всему нет простого способа копирования элементов multimap в vector,
  // только, если элементы вектора не имеют тип pair.
  /* std::vector<std::pair<int, std::string>> v = {
      {1, "some"}, {2, "string"}, {3, "here"}}; */

  // Недопустимо. Не будет работать, так как не предусмотрен оператор
  // присваимвания между
  //  этими типами контейнеров.
  // std::copy(v.begin(), v.end(), std::inserter(c, c.end()));

  // Недопустимо. Та же причина, что и сверху. К тому же у map нет функции
  // push_back().
  // std::copy(v.begin(), v.end(), std::back_inserter(c));

  // Тоже самое, что и сверху.
  // std::copy(c1.begin(), c.end(), std::inserter(v, v.end()));

  // Тоже самое, что и сверху.
  // std::copy(c1.begin(), c.end(), std::inserter(v, v.end()));

  // Но если элементы вектора pair, то ок.

  // Работает. В обоих случаях будет одинаковый разультат, поскольку multimap
  // упорядочивает ключи.
  // std::copy(c2.begin(), c2.end(), std::inserter(c, c.begin()));
  // std::copy(c2.begin(), c2.end(), std::inserter(c, c.begin()));

  // Итог таков: для всех map алгоритмы для копирования и схожих алгоритмов
  // можно использовать для контейнеров с элементами pair.

  for (auto elem : v) std::cout << elem << std::endl;
  std::cout << "-----------" << std::endl;

  for (auto &elem : c) std::cout << elem << std::endl;
}