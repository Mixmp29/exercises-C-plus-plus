#include <string>

// Упражнение 6.2. Укажите, какие из следующих функций ошибочны и почему.
// Предложите способ их использования.

// (a) Тип возвращаемого значения не совпадает с типом переменной, которая
// используется оператором return. string нельзя конвертировать в int. Нужно
// поменять тип возвращаемого значения, липо тип переменной 's'.

std::string f() {
  std::string s;
  //...
  return s;
}

// (b) Отсутствует тип возвращаемого значения. Если функция ничего не возращает,
// то нужно хотя бы поставить void.

void f2(int i) { /* ... */
}

// (c) Имена объявленных переменных должны быть разными. Плюс там нет одной
// открытой фигурной скобки. Нужно поставить разные имена.

int calc(int v1, int v2) { /* ... */
}

// (d) Требуются фигурные скобки для тела функции. Тело функции определяется
// исключительно составным оператором (блоком).

double square(double x) { return x * x; }