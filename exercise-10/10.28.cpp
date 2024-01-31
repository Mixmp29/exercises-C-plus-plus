// Упражнение 10.28. Скопируйте вектор, содержащий значения от 1 до 9, в три
// других контейнера. Используйте адаптеры inserter, back_inserter и
// front_inserter соответственно для добавления элементов в эти контейнеры.
// Предскажите вид результатирующей последовательности в зависимости от вида
// адаптера вставки и проверьте свои предсказания на написанной программе.

#include <algorithm>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <vector>

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::deque<int> deque;
  std::list<int> list;
  std::forward_list<int> f_list;

  // Вставляет элемент перед указанным итератором. Тут кстати begin() = end()
  // из-за пустого контейнера, так что есть возможность поставить и end().
  // Результат: 1, 2, 3, 4, 5, 6, 7, 8, 9.
  std::copy(vec.begin(), vec.end(), std::inserter(deque, deque.begin()));

  // Всегда вставляет элемент в конец контейнера.
  // Результат: 1, 2, 3, 4, 5, 6, 7, 8, 9.
  std::copy(vec.begin(), vec.end(), std::back_inserter(list));

  // Всегда вставляет элемент в начало последователности.
  // Перевернет последовательность, так как читается вектор слева на право, а
  // вставляется справа на лево.
  // Результат: 9, 8, 7, 6, 5, 4, 3, 2, 1.
  std::copy(vec.begin(), vec.end(), std::front_inserter(f_list));

  for (auto elem : vec) std::cout << elem << " ";
  std::cout << std::endl;
  for (auto elem : deque) std::cout << elem << " ";
  std::cout << std::endl;
  for (auto elem : list) std::cout << elem << " ";
  std::cout << std::endl;
  for (auto elem : f_list) std::cout << elem << " ";
  std::cout << std::endl;
}