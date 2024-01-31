// Упражнение 14.52. Какой из операторов operator+, если таковые вообще имеются,
// будет выбран для каждого из следующих выражений суммы? Перечислите
// функции-кандидаты, подходящие функции и преобразования типов для аргументов
// каждой подходящей функции:

#include <iostream>

class SmallInt {
  friend SmallInt operator+(const SmallInt&, const SmallInt&);

 public:
  SmallInt(int = 0) { std::cout << "SmallInt(int = 0)" << std::endl; }
  operator int() const {
    std::cout << "SmallInt(int = 0)" << std::endl;
    return val;
  }

 private:
  size_t val;
};

SmallInt operator+(const SmallInt&, const SmallInt&) {
  std::cout << "SmallInt operator+(const SmallInt&, const SmallInt&)"
            << std::endl;
  return SmallInt();
}

struct LongDouble {
  LongDouble(double = 0.0) {
    std::cout << "LongDouble(double = 0.0)" << std::endl;
  }
  operator double() {
    std::cout << "operator double()" << std::endl;
    return double();
  }
  // operator float();

  LongDouble operator+(const SmallInt&) {
    std::cout << "LongDouble operator+(const SmallInt&)" << std::endl;
    return LongDouble();
  }
};

LongDouble operator+(LongDouble&, double) {
  std::cout << "LongDouble operator+(LongDouble&, double)" << std::endl;
  return LongDouble();
}

int main() {
  SmallInt si;
  LongDouble ld;
  std::cout << "----------" << std::endl;
  ld = si + ld;  // Встроенный оператор суммы. Предполагаю из-за того, что
                 // нельзя сделать несколько пользовательских преобразований
                 // подряд, остается только преобразование во встроенные типы.
  std::cout << "----------" << std::endl;
  ld = ld + si;  // Вызов функции-члена класса, так как
                 // это прямой вызов этого члена через объект.
}