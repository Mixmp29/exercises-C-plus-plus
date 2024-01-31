// Упражнение 14.53. С учетом определения класса SmallInt на стр. 743
// определите, допустимо ли следующее выражение суммы. Если да, то какой
// оператор суммы используется? В противном случае, как можно изменить код,
// чтобы сделать его допустимым?

// Можно добавить функцию operator+ для работы с double. Результат суммируется,
// а потом преобразуется в int, а потом в double.

// Можно также просто убрать функцию суммирования у SmallInt, но это такой себе
// вариант.

// Или, в зависимости от желаемого результата, можно определить внешнюю
// функцию operator+ (никак не связанную с классом через friend), сразу
// возвращающую результат double. Вместо дружественной операции описанной выше.

#include <iostream>

class SmallInt {
  friend SmallInt operator+(const SmallInt&, const SmallInt&);
  /* friend SmallInt operator+(const SmallInt&, const double&);
   */
 public:
  SmallInt(int = 0) { std::cout << "SmallInt(int = 0)" << std::endl; }
  operator int() const {
    std::cout << "SmallInt(int = 0)" << std::endl;
    return val;
  }

 private:
  size_t val;
};

/* SmallInt operator+(const SmallInt&, const SmallInt&) {
  std::cout << "SmallInt operator+(const SmallInt&, const SmallInt&)"
            << std::endl;
  return SmallInt();
}
 */

// double operator+(const SmallInt&, const double&);

SmallInt operator+(const SmallInt&, const SmallInt&) {
  std::cout << "SmallInt operator+(const SmallInt&, const SmallInt&)"
            << std::endl;
  return SmallInt();
}

int main() {
  SmallInt si;
  double d = si + 3.14;  // Ошибка. Можно преобразовать si в int, потом в
                         // double, так и 3.14 в SmallInt.
}