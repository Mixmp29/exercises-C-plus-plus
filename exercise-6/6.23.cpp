#include <iostream>

// Упражнение 6.23. Напишите собственные версии каждой из функций print(),
// представленных в этом разделею Вызовите каждую из этих функций для вывода i и
// j, определенных следующим образом:

// Немного затронется перегрузка.

// #1
void print(const int *arr) {
  std::cout << "--------#1--------" << std::endl;
  std::cout << *arr << std::endl;
}

// Номер 2 никогда не сработает, если только не дать другое ему имя и вызвать
// его. Компилятор также не позволит сделать переопределение функции с
// одинаковым типом параметров.

/* void print(const int arr[]) {
  std::cout << "--------#2--------" << std::endl;
  std::cout << *arr << std::endl;
} */

// Тоже самое касается и номера 3, однако я намеренно дал ему другое имя, чтобы
// подчеркнуть, что размерность 5 никак не влияет на сам тип. Он все равно будет
// const int* как в #1.
void print_n(const int arr[5]) {
  std::cout << "--------#3--------" << std::endl;
  std::cout << *arr << std::endl;
}

// Маркер использоваться не будет, так как нет в main массива char.

void print(const int *beg, const int *end) {
  std::cout << "--------#4--------" << std::endl;
  while (beg != end) std::cout << *beg++ << std::endl;
}

void print(const int ia[], size_t size) {
  std::cout << "--------#5--------" << std::endl;
  for (size_t i = 0; i != size; ++i) std::cout << ia[i] << std::endl;
}

void print(int (&arr)[10]) {
  std::cout << "--------#6--------" << std::endl;
  for (auto elem : arr) {
    std::cout << elem << std::endl;
  }
}

int main() {
  int i = 0, j[7] = {0, 1, 5, 3, 1, 2, 2}, k[10] = {1, 2, 3};
  // #1
  print(&i);
  // #1
  print(j);

  // Размерность в параметре не вежна, выдает тип const int* arr.
  // #3
  print_n(j);

  // #4
  print(std::begin(j), std::end(j));

  // #5
  print(std::begin(j), 7);

  // #6
  print(k);
}