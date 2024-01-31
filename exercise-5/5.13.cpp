#include <vector>

// Упражнение 5.13. Каждая из приведенных ниже программ содержит
// распространенную ошибку. Выявите и исправьте каждую их них.

int main() {
  // (a)
  unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
  char ch = 'a';  // new_text();
  switch (ch) {
    case 'a':
      aCnt++;
    case 'e':
      eCnt++;
    default:
      iouCnt++;
  }
  // 1) Нету break после каждого case, при 'a' будет суммировано и 'e' и
  // default.
  // 2) Имя iouCnt сбивает с толку. Лучше его переименовать otherCnt, так будет
  // понятно, что будут суммироваться остальные символы.
  // 3) Подсчет немного бессмысленен, так как switch пройдется один раз, но
  // предположим, что это сделано для краткости задания.

  // Исправленная версия:
  unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
  char ch = 'a';  // new_text();
  switch (ch) {
    case 'a':
      aCnt++;
      break;
    case 'e':
      eCnt++;
      break;
    default:
      iouCnt++;
      break;  // <- здесь это не обязательно, но и не запрещено.
  }

  // (b)
  std::vector<int> ivec = {1, 2, 3};
  unsigned index = 1;  // some_value()
  switch (index) {
    case 1:
      int ix = 0;  // Не Ок. Может произойти неявный обход инициализации. Этот
                   // маневр запрещен языком, поэтому компилятор выдаст
                   // соответствующую ошибку.
      ivec[ix] = index;  // Если бы предыдущее определение и этот оператор были
                         // в фигурных скобках, то было бы Ок.
      break;
    default:
      ix = ivec.size() - 1;  // В теории переменная ix будет видна, но пуста.
                             // Программа все равно выдаст ошибку еще раньше.
      ivec[ix] = index;
  }

  // Исправленная версия:
  std::vector<int> ivec = {1, 2, 3};
  unsigned index = 1;  // some_value()
  switch (index) {
    case 1: {
      int ix = 0;  // get_value()
      ivec[ix] = index;
      break;
    }
    default: {
      int ix = ivec.size() - 1;
      ivec[ix] = index;
    }
  }

  // (c)
  unsigned evenCnt = 0, oddCnt = 0;
  int digit = /* get_num() */ 15 % 10;
  switch (digit) {
    case 1, 2, 3, 5, 7, 9:  // В языке для случаев, где для разных меток case
                            // нужно делать одинаковый код, предусмотрен другой
                            // синтаксис: не через запятую, а через
                            // последовательность "case *:", где '*' какое-либо
                            // целочисленное значение метки.
      oddCnt++;  // Лучше делать префикстный инкремент, чтобы не делать лишних
                 // операций.
      break;
    case 2, 4, 6, 8, 10:
      evencnt++;  // Скорее всего опечатка, но тут регистр у 'c' маленький,
                  // такой переменной нет для программы. И тоже бы лучше
                  // префиксный делать.
      break;
  }

  // Исправленная версия:
  unsigned evenCnt = 0, oddCnt = 0;
  int digit = /* get_num() */ 15 % 10;
  switch (digit) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 9:
      ++oddCnt;
      break;
    case 2:
    case 4:
    case 6:
    case 8:
    case 10:
      ++evenCnt;
      break;
  }

  // (d)
  unsigned ival = 512, jval = 1024, kval = 4096;
  unsigned bufsize;
  unsigned swt = 455;  // get_bufCnt();
  switch (swt) {
    case ival:
      bufsize = ival * sizeof(int);
      break;
    case jval:
      bufsize = jval * sizeof(int);
      break;
    case kval:
      bufsize = kval * sizeof(int);
      break;
  }
  // Здесь все в порядке за одним большим исключением - метки case должны быть
  // кокнстантными. В этом случае нужно либо явно поставить значения этих
  // переменных, либо лучше на них просто поставить const, сами переменные не
  // изменяются в коде.

  // Исправленная версия:
  const unsigned ival = 512, jval = 1024, kval = 4096;
  unsigned bufsize;
  unsigned swt = 455;  // get_bufCnt();
  switch (swt) {
    case ival:
      bufsize = ival * sizeof(int);
      break;
    case jval:
      bufsize = jval * sizeof(int);
      break;
    case kval:
      bufsize = kval * sizeof(int);
      break;
  }
}