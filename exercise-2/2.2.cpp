/* Упражнение 2.2. Какие типы вы использовали бы для коэффициента, основной
 * суммы и платежей при вычислении выплат по закладной? Объясните, почему вы
 * выбрали каждый из типов?
 *
 * Я не нашёл быстро похожую формулу и данные, которые таи используются, но омгу
 * предположить:
 * Для коэффициента int, а для суммы и платежей double.
 * Так как дело имеется с деньгами, то значения будут с плавающей запятой.
 * int для коэффициента, так как скорее всего подразумевается целове число*/

#include <iostream>

int main() {
  bool a = true;
  int b = 2;
  std::cout << a + b << std::endl;
}