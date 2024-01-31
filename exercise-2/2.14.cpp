#include <iostream>

// Упражнение 2.14. Допустим ли следующий код? Если да, то какие значения он
// отобразит на экране?
int main() {
  int i = 100, sum = 0;

  for (int i = 0; i != 10;
       ++i)  // Переопределение переменной i в области видимости for, которая
             // теперь скрывает i во внешней области видимости (функции main)
    sum += i;  // суммирование значений переменной i находящейся во внутренней
               // области видимости (оператора for)

  std::cout
      << i << " " << sum
      << std::endl;  // 100 45. Вывод переменной i из внутренней области
                     // видимости, теперь она не скрывается переменной с тем же
                     // индитификатором во внутренней области видимости.
}