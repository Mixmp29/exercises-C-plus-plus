#include <iostream>

// Упражнение 2.20. Что делает следующая программа?
int main() {
  int i = 42;
  int *pi = &i;
  *pi = *pi * *pi;  // i = i * i = 42 * 42 = 1764

  std::cout << *pi << " " << i << std::endl;
}