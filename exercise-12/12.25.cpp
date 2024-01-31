// Упражнение 12.25. С учетом следующего оператора new, Как будет удаляться
// указатель pa?

#include <memory>

int main() {
  int *pa = new int[10];

  delete[] pa;  // Вот так.
}