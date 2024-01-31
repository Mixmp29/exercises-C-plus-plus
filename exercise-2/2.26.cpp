int main() {
  const int buf;
  // при объявлении константа всегда должна быть инициализирована

  int cnt = 0;         // ok
  const int sz = cnt;  // ok
  ++cnt;               // ok
  ++sz;  // not ok. Значение константы нельзя изменять
}