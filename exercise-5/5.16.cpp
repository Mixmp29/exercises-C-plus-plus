#include <iostream>
#include <vector>

// Упражнение 5.16. Цикл while особенно хорош, когда необходимо выполнить некое
// условие; напирмер, когда нужно читать значения до конца файла. Цикл for
// считают циклом пошагового выполнения: индекс проходит диапазон значений в
// коллекции. Напишите идиоматическое использование каждого цикла, а затем
// перепишите каждый случай использования в другой конструкии цикла. Если бы вы
// могли использовать тольк один цикл, то какой бы вы выбрали и почему?

int main() {
  std::string str;
  std::vector<std::string> text;

  while (std::cin >> str) text.push_back(str);

  for (size_t i = 0; i < str.size(); ++i)
    ;

  //////////////////////////////////////////////

  for (; std::cin >> str;) text.push_back(str);

  size_t i = 0;
  while (i < str.size()) {
    ++i;
    ;
  }

  // Если бы был выбор между этими двумя, то выбрал бы for, так как его можно
  // легко и быстро адаптировать под поведение while. Сам while адаптировать под
  // for уже труднее: можно запутаться и наделать ошибок, если код уже будет
  // здоровый.

  // А так лучше себя не ограничивать. Если в коде встретить while, то скорее
  // всего неизвестно когда условие станет ложным. Если встретить for, то сразу
  // видно когда условие достигнет своего конца.
}