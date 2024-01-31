#include <iostream>

// Упражнение 3.30. Выявите ошибки индексации в следующем коде:

int main() {
  constexpr size_t array_size = 10;

  int ia[array_size];

  for (size_t ix = 1; ix <= array_size;
       ++ix) {  // Ошибка в месте условия оператора for: в конце перебор выйдет
                // за границы массива. Индекс может быть только строго меньше
                // размера массива.
    ia[ix] = ix;
  }

  for (size_t elem : ia) {
    std::cout << elem << std::endl;
  }
}