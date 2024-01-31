// Упражнение 2.31. С учетом объявлений в предыдущем упражнении укажите,
// допустимы ли следующие присвоения. Объясните, как спецификатор const верхнего
// или ниэнего уровня применяется в каждом случае.

int main() {
  const int v2 = 0;  // Константа верхнего уровня.
  int v1 = v2;  // Нет константы ни верхрего, ни нижнего уровня.

  int *p1 = &v1,  // Константа указателя нижнего уровня совпадает с константой
                  // адреса нижнего уровня. У верхнего нет. Константы верхнего
                  // можно ингорировать.
      &r1 = v1;  // Также константа нижнего совпадает с
                 // константой нижнего.

  int i = 0;  // В задании нет, но предположим, что оно есть.

  const int *p2 = &v2,  // Константы нижнего уровня совпадают,
                        // константы вернхенго нет.
      *const p3 = &i,  // Константа верхнего уровня указателя совпадает с
                       // константой адреса переменой. Допускается инициализация
                       // с переменной нижнего уровная без константы, так как
                       // int можно преобразовать в const int (но не наоборот).
          &r2 = v2;  // Константа ссылки нижнего уровня совпадает с константой
                     // нижнего уровня переменной.

  r1 = v2;  // Допустимо. Верхний уровень без константы и верхний уровень с
            // константой. Верхние уровни можно игнорировать. Присвоение путем
            // копирования значения правого операнда в левый операнд, не
            // изменяет сам правый операн.
}