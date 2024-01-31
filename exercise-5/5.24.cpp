#include <iostream>
#include <stdexcept>

// Упражнение 5.24. Перепишите предыдущую программу так, чтобы она передавала
// исключение, если второе число - нуль. Проверье свою программу с нулевым
// вводом, чтобы увидеть происходящее при отсутствии обработчика исключений.

int main() {
  int a, b;
  std::cin >> a >> b;
  if (b == 0)
    throw std::runtime_error("The variable must be different from 0.");
  std::cout << "a / b = " << a / b << std::endl;

  // Вызывается функция terminate после создания экземпляра std::runtime_error.
}