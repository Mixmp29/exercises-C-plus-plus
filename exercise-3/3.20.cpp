#include <iostream>
#include <vector>

// Упражнение 3.20. Прочитайте набор целых чисел в вектор. Отобразите сумму
// каждой пары соседних элементов. Измените программу так, чтобы она отображала
// сумму первого и последнего элементов, затем сумму второго и предпоследнего и
// т.д.

int main() {
  int val;
  std::vector<int> vec;

  while (std::cin >> val) vec.push_back(val);

  std::cout << "Display the sum of each pair of adjacent elements: ";
  for (decltype(vec.size()) i = 1; i < vec.size(); ++i) {
    std::cout << vec[i - 1] + vec[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "Display the sum of the first and last elements, then the sum "
               "of the second and last, etc.: ";
  for (unsigned int i = 0; i < vec.size() / 2;
       ++i) {  // Предупреждение о сравнении значений знакового и беззнакового
               // типов, если у i тип int. У vec.size целочисленный беззнаковый
               // тип vector<int>::size_type. Может привести к непредвиденным
               // обстоятельствам, если i станет отрицательным. Всё ок, если
               // использовать unsigned int.
    std::cout << vec[i] + vec[vec.size() - 1 - i]
              << " ";  // Поскольку номера позиций начинаются с 0, нужно делать
                       // -1 для члена size()
  }
  std::cout << std::endl;
}