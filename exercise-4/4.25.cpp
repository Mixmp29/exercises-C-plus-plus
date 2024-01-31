#include <iostream>

// Упражнение 4.25. Каково значение выражения ~'q' << 6 на машине с 32-битовыми
// целыми числами и 8-битовыми символами, с учетом, что символ 'q' имеет битовое
// представление 01110001?

int main() {
  unsigned char bits = ~'q';       // ~01110001 => 10001110
  unsigned int elem = bits << 6;   // 10001110 << 6 => 00100011 10000000
  std::cout << elem << std::endl;  // 9088

  // Если все же сделать единым выражением
  unsigned int elem2 = ~'q' << 6;
  // Оператор '~' имеет больший приоритет, чем '<<', поэтому сначала выполнится
  // побитовая операция NOT. Быты 'q' переводятся в int, сделовательно слева от
  // них появится еще 24 старших бита 0. Затем производится операция NOT на все
  // 32 бита. Получается 24 единиц и 10001110 в конце. (В предыдущем варианте
  // эти единины не сохранялись, так как char имеет всего 8 бит) Потом все эти
  // биты сдвигаются влево на 6 позиций. Получается очень большое число.

  //    ~00000000 00000000 00000000 01110001
  // =>  11111111 11111111 11111111 10001110

  //    11111111 11111111 11111111 10001110 << 6
  // => 11111111 11111111 11100011 10000000 = 4294960000
  std::cout << elem2 << std::endl;

  // Стоит отметить, что хотя по книге int является 16 бит, если он является
  // unsigned, то он выростает до 32 бит. Тоже самое касается и других
  // целочисленных типов: long -> 32; unsigned long -> 64.

  // Также, если используется тип unsigned, то не нужно следить за самым
  // последним по индексу битом, которй представляет из себя знаковый бит.
}