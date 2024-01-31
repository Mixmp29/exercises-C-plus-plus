#include <iostream>

// Упражнение 6.50. С учетом приведенных на стр. 317 объявлений функции f()
// перечислите подходящие функции для каждого из следующих вызовов. Укажите
// наилучшее соответствие, или если его нет, то из-за отсутствия соответствия
// или неоднозначности вызова?

void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);

// (a) f(2.56, 42) // Подходят f(int, int) и f(double, double). Компилятор
// выдаст ошибку об неоднозначности выибора функции, так как они обе имеют
// одинаковый приоритет соответствия: по первому аргументу подходит версия с
// double, по второму версия с int - непонятно какую выбрать.

// (b) f(42) // Подходит f(int) и f(double, double = 3.14). Большее соответствие
// имеет версия с int, так как она больше всего подходит по соответсвию типов.

// (с) f(42, 0) // Подходят f(int, int) и f(double, double = 3.14). Больше всего
// подходит версия с int по большему соответсвию типов у обоих аргументов.

// (d) f(2.56, 3.14) // Подходят f(int, int) и f(double, double = 3.14). Больше
// всего подходит версия с double по большему соответсвию типов у обоих
// аргументов.