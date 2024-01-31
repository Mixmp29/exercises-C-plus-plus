// Упражнение 14.34. Определите класс объекта функции для выполнения действий
// условного оператора: оператор вызова этого класса должен получать три
// параметра. Он должен проверить свой первый параметр, и если эта проверка
// успешна, возвратить второй параметр; в противном случае он должен возвратить
// свой третий параметр.

#include <iostream>
#include <string>

struct Check {
  std::string operator()(int val, const std::string& ok,
                         const std::string& not_ok) {
    return (val != 0) ? ok : not_ok;
  }
};

int main() {
  Check check;

  std::cout << check(1, "true", "false") << std::endl;
}