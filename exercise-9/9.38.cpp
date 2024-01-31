// Упражнение 9.38. Напишите программу, позволяющую исследовать рост вектора в
// библиотеке, которую вы используете.

#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec;

  std::cout << "size: " << vec.size() << ", capacity: " << vec.capacity()
            << std::endl;

  vec = {1, 2, 3, 4, 5, 6, 7};  // Создает capacity равный size.

  std::cout << "size: " << vec.size() << ", capacity: " << vec.capacity()
            << std::endl;

  vec.push_back(8);  // Работает тактика удвоение capacity;

  std::cout << "size: " << vec.size() << ", capacity: " << vec.capacity()
            << std::endl;

  for (int i = 9; i <= 14; ++i) vec.push_back(i);  // Размер и емкость равны.

  std::cout << "size: " << vec.size() << ", capacity: " << vec.capacity()
            << std::endl;

  vec.push_back(15);  // Ага, прям в два раза больше от предыдущего.

  std::cout << "size: " << vec.size() << ", capacity: " << vec.capacity()
            << std::endl;
}