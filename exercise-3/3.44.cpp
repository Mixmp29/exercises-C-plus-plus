#include <iostream>

// Упражнение 3.44. Перепешите программы из предыдущего упражнения, используя
// псевдоним для типа управляющих переменных цикла.

int main() {
  int ia[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  using refarr = int[4];
  typedef int &ref;

  for (refarr &row : ia) {
    for (ref col : row) {
      std::cout << col << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "--------------" << std::endl;

  for (size_t i = 0; i < 3; ++i) {
    for (size_t j = 0; j < 4; ++j) {
      std::cout << ia[i][j] << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "--------------" << std::endl;

  using int_array = int(*)[4];
  typedef int *pointer_int;

  for (int_array prow = ia; prow != ia + 3; ++prow) {
    for (pointer_int pcol = *prow; pcol != *prow + 4; ++pcol) {
      std::cout << *pcol << " ";
    }
    std::cout << std::endl;
  }

  /* Чтобы проще было понять работу псевдонимов using или typedef можно мыслить
     следующим образом:
     * используя ключевое слово typedef можно представить, что это шаблон - на
     место имени псевдонима в typedef будет ставиться имя переменной, которая
     будет объявлена этим псевдонимом.
     Пример:
        typedef int (*int_array)[4];
        После объявления псевдонимом переменной
        int_array prow это выражение будет равноценно int(*prow)[4];
        То есть prow подставился в typedef.

     * используя ключевое слово using принцип тот же самый что и для typedef,
     только шаблон типа переехал в правый операнд без псевдонима, а сам
     псевдоним стал левым операндом. Можно представить, что это тот же typedef,
     но без псевдонима справа.
     Пример:
        using int_array = int (*)[4];
        Тоже самое что и int (*int_array)[4];
   */
}