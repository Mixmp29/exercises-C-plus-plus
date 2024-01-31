// Упражнение 12.14. Напишите собственную версию функции, использующую указатель
// shared_ptr для управления соединенеием.

#include <memory>

struct destination {};
struct connection {};
connection connect(destination *);
void disconnect(connection);

void end_connection(connection *p) { disconnect(*p); }

void f(destination &d) {
  connection c = connect(&d);
  std::shared_ptr<connection> p(&c, end_connection);
}