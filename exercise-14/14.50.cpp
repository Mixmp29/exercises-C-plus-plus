// Упражнение 14.50. Представьте возможные последовательности преобразований
// типов для инициализации объектов ex1 и ex2. Объясните допустима ли их
// инициализация или нет.

struct LongDouble {
  LongDouble(double = 0.0);
  operator double();
  operator float();
};

int main() {
  LongDouble ldObj;
  int ex1 = ldObj;  // Ошибка. Компилятору непонятно какую функцию выбирать
  // double() или float() с последоующим встроенным преобразованием в int.
  float ex2 = ldObj;  // Ok. Явынй вызов float().
}