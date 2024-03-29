// Упражнение 12.9. Объясните, что происхходит в следующем коде:

#include <memory>
#include <new>

int main() {
  // Выделение динамической памяти, их инициализация и присвоение их адресов
  // указателям q и r соответственно.
  int *q = new int(42), *r = new int(100);

  // r теперь указывает на объект типа int со значением 42. Объект типа int со
  // значением 100 не освобажден.
  r = q;
  // Выделение динамической памяти, их инициализация и присвоение их адресов
  // умным указателям q2 и r2 соответственно.
  auto q2 = std::make_shared<int>(42), r2 = std::make_shared<int>(100);

  // r2 теперь указывает на объект типа int со значением 42. Произошел декремент
  // счетчика r2. Счетчик владельцев у умного указателя r2 теперь равен 0.
  // Объект типа int со значением 100 освобажден.
  r2 = q2;
}