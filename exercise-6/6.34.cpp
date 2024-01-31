#include <iostream>

// Упражнение 6.34. Что случится, если условие остановки функции factorial()
// будет таким: if (val != 0)

// Ничего такого, если оператор return возвращает 1. В таком случае будет лишнее
// умножение на единицу: 1 * 1 * 2 * ... * n.

int factorial(int val) {
  if (val != 0) return val * factorial(val - 1);
  // Это выражение в return будет повторяться и углубляться в скобки
  // столько раз, пока условие в if будет истинно.
  return 1;
}
// Эквивалентно return 5 * (4 * (3 * (2 * (1 * (1)))))
/* 5 * factorial(4)
          ^
          |
       4 * factorial(3)
              ^
              |
           3 * factorial(2)
                  ^
                  |
               2 * factorial(1)
                      ^
                      |
                   1 * factorial(0)
                          ^
                          |
                          1   */

// Однако,если он будет val, то результат такой функции всегда будет 0, так как
// после этой проверки val = 0, которая потом в конце рекурсии возвращается
// оператором return. Результатом такой рекурсии будет: 0 * 1 * 2 * ... * n.

int zerofactorial(int val) {
  if (val != 0) return val * factorial(val - 1);
  return val;
}
// Эквивалентно return 5 * (4 * (3 * (2 * (1 * (0)))))
/* 5 * factorial(4)
          ^
          |
       4 * factorial(3)
              ^
              |
           3 * factorial(2)
                  ^
                  |
               2 * factorial(1)
                      ^
                      |
                   1 * factorial(0)
                          ^
                          |
                          0   */

int main() { std::cout << factorial(5) << std::endl; }