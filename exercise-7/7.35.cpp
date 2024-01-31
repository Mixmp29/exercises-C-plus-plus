// Упражнение 7.35. Объясните код, приведенный ниже. Укажите, какое из
// определений, Type или initVal, будет использовано для каждого из имен. Если
// есть ошибки, найдите и исправьте их.

#include <string>

/* typedef std::string Type;
Type initVal();

class Exercise {
 public:
  typedef double Type;  // Ошибка. Переопределение типа Type. Хоть и компилятор
                        // принял его у меня, не следует так делать.
  Type setVal(Type);
  Type initVal();  // Окей. Имя функции-члена перекрывает имся из глобальной
                   // области видимости.
 private:
  int val;
};

// Ошибка. На месте возвращаемого значения используется Type из глобальной
// области видимости.
Type Exercise::setVal(Type parm) {
  val = parm + initVal();  // Ok. Используется initVal из класса.
  return val;
} */

class Exercise {
 public:
  typedef double Type;
  Type setVal(Type);
  Type initVal() { return 0; }

 private:
  int val;
};

Exercise::Type Exercise::setVal(Type parm) {
  val = parm + initVal();
  return val;
}

int main() {}