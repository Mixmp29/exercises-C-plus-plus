#include <iostream>
#include <string>

// Упражнение 6.45. Пересмотрите функции, написанные для предыдущих упражнений,
// и решите, должны ли они быть определены как встраиваемые. Если да, то
// сделайте это. В противном случае объясните, почему они не должны быть
// встраиваемыми.

// Не совсем понятно какие именно задания. Вля что-то вменяемое из предыдущих 10
// заданий.

inline bool isShorter(const std::string& s1, const std::string& s2) {
  return s1.size() < s2.size();
}
// Yeah. Все сказано в предыдущем задании.

inline std::string make_plural(size_t ctr, const std::string& word,
                               const std::string& ending) {
  return (ctr > 1) ? word + ending : word;
}
// Вполне можно.

int factorial(int val) {
  if (val != 1) return val * factorial(val - 1);
  return 1;
}  // Можно, но компилятор просто его не вставит

void reset(int a) { std::cout << "int " << a << std::endl; }
// Точно нет. Нет никакого возвращаемого значения.