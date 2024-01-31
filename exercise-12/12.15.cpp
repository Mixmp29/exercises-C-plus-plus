// Упражнение 12.15. Перепешите первое упражнение так, чтобы использовать
// лямбда-выражение (см. раздел 10.3.2, стр. 497) вместо функции
// end_connection().

#include <memory>

struct destination {};
struct connection {};
connection connect(destination *);
void disconnect(connection);

void f(destination &d) {
  connection c = connect(&d);
  std::shared_ptr<connection> p(&c, [](connection *p) { disconnect(*p); });
}