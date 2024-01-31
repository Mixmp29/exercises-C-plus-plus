#include <iostream>
#include <stdexcept>

// Упражнение 5.25. Перепишите предыдущую программу так, чтобы использовать для
// обработки исключения блок try. Раздел catch должен отобразить сообщение и
// попросить пользователя ввести новое число и повторить код в блоке try.

int main() {
  int a, b;
  while (std::cin >> a >> b) {
    try {
      if (b == 0)
        throw std::runtime_error("The variable must be different from 0.");
      else {
        std::cout << "a / b = " << a / b << std::endl;
        break;
      }
    } catch (std::runtime_error const&
                 err) {  // Без сonst & компилятор выдает предупреждение:
                         // catching polymorphic type ‘class std::runtime_error.
      std::cout << err.what() << "\nTry Againt? Enter y or n" << std::endl;
      char c;
      std::cin >> c;
      if (!std::cin || c == 'n') break;
    }
  }
}