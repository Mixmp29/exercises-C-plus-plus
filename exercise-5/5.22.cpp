// Упражнение 5.22. Последний пример этого раздела, с переходом назад к метке
// begin, может быть написан лучше с использованием цикла. Перепишите код так,
// чтобы устранить оператор goto.

int get_size() { return 5; }

int main() {
  int sz;

  do {
    sz = get_size();
  } while (sz <= 0);  // Если я правильно понял задание и если повторять
                      // синтаксис, то такой вариант.
}