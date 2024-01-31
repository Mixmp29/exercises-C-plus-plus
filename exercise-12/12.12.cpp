// Упражнение 12.12. Используя объявления указателей p и sp, объясните каждый из
// следующих вызовов функции process(). Если вызов корректен, объясните, что он
// делает. Если вызов некорректен, объясните почему:

#include <memory>
#include <new>

void process(std::shared_ptr<int> p) {}

int main() {
  auto p = new int();
  auto sp = std::make_shared<int>();

  process(sp);  // Ok. Передается shared_ptr напрямую

  process(new int());  // Not ok. Инициализировать shared_ptr можно только явно
                       // прямой инициализацией.
  process(p);  // Not ok. Тоже самое что и выше, буквально, что само выражене,
               // что комментарий.

  process(std::shared_ptr<int>(p));
}