#include <iostream>
#include <vector>

// Упражнение 3.20. Прочитайте набор целых чисел в вектор. Отобразите сумму
// каждой пары соседних элементов. Измените программу так, чтобы она отображала
// сумму первого и последнего элементов, затем сумму второго и предпоследнего и
// т.д.

// Упражнение 3.24. Переделайте последнее упражнение раздела 3.3.3 с
// использованием итераторов.

int main() {
  int val;
  std::vector<int> vec;

  while (std::cin >> val) vec.push_back(val);

  std::cout << "Display the sum of each pair of adjacent elements: ";
  for (auto i = vec.begin() + 1; i != vec.end(); ++i) {
    std::cout << *(i - 1) + *i << " ";
  }
  std::cout << std::endl;

  // Можно еще так.
  std::cout
      << "Display the sum of each pair of adjacent elements another way: ";
  for (auto first = vec.cbegin(), second = vec.cbegin() + 1;
       second != vec.end(); ++first, ++second) {
    std::cout << *first + *second << " ";
  }
  std::cout << std::endl;

  std::cout << "Display the sum of the first and last elements, then the sum "
               "of the second and last, etc.: ";

  // Первое что пришло в голову, чтобы адаптировать прошлую задачу под
  // итераторы. Выглядит довольно запутанно.

  for (auto i = vec.begin(); i != vec.end() - vec.size() / 2; ++i) {
    std::cout << *i + *(vec.end() - 1 - (i - vec.begin())) << " ";
    // -1, так как итератор end() показывает
    // на несуществующий элемент за последним
    // элементом. (vec.begin() - i) вернет расстояние между
    // итератами (целочисленное числовое значение). Затем из end()
    // вычитается это значение, чтобы дойти до правого элемента.
  }
  std::cout << std::endl;

  std::cout << "Display the sum of the first and last elements, then the sum "
               "of the second and last, etc. another way: ";

  // Лучше сделать так. Условие b < e нужно для отслеживания итератора b, чтобы
  // тот не перенгал e (не встал на позицию справо от него).
  for (auto b = vec.cbegin(), e = vec.cend() - 1; b < e; ++b, --e) {
    std::cout << *b + *e << " ";
  }
  std::cout << std::endl;
}