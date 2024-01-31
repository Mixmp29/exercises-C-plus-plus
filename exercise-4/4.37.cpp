#include <string>

// Упражнение 4.37. Перепишите каждое из следующих приведений старого стиля так,
// чтобы использовался именнованный оператор приведения.

int main() {
  int i;
  double d;
  const std::string *ps;
  char *pc;
  void *pv;

  // Сначала сделал так
  std::string *s;
  s = const_cast<std::string *>(ps);
  pv = reinterpret_cast<void *>(s);

  // Потом понял, что можно проще
  pv = reinterpret_cast<void *>(const_cast<std::string *>(ps));

  i = static_cast<int>(*pc);
  pv = static_cast<void *>(&d);
  pc = static_cast<char *>(pv);
}