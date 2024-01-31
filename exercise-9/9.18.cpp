// Упражнение 9.18. Напишите программу чтения последовательности строк со
// стандартного устройства ввода в контейнер deque. Для записи элементов в
// контейнер deque используйте итераторы и цикл.

#include <deque>
#include <iostream>
#include <string>

int main() {
  std::string word;
  std::deque<std::string> deque;

  while (std::cin >> word) {
    deque.insert(deque.end(), word);  // Эквивалентно push_back().
  }

  for (auto elem : deque) std::cout << elem << std::endl;
}