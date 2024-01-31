#include <iostream>

// Упражнение 3.35. Напишите программу, которая использует указатели для
// обнуления элементов массива.

int main() {
  int array[5]{1, 2, 3, 4, 5};

  for (auto elem : array) std::cout << elem << " ";
  std::cout << std::endl;

  for (int *p = array; p != &array[5];
       ++p) {  // В объявлении: указатель на первый элемент массива array. В
               // условии: пока адрес p не станет равным адресу позиции после
               // конца массива.
    *p = 0;
  }

  for (auto elem : array) std::cout << elem << " ";
  std::cout << std::endl;
}