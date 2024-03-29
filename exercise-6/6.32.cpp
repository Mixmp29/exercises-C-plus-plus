#include <iostream>

// Упражнение 6.32. Укажите, корректна ли следующая функция. Если да, то
// объясните, что она делает; в противном случае исправьте ошибки, а затем
// объясните.

// Функция возвращает ссылку на элемент массива по индексу.
int &get(int *arry, int index) { return arry[index]; }

// Добавил от себя. Кстати, тут стало понятно почему указатель на первый элемент
// на массив != массив из main. Может показаться, что в функции указатель на
// массив, может вести точно также, как оригинал. Главное не уходить за границу.
// Однако программа их различает (разные типы) и из-за этого могут быть
// недоступны инуструменты, которые можно использовать на массиве. К примеру
// sizeof(arry) в функции выдаст размер указателя, а не массива. Или недоступны
// функции std::begin() и std::end(). Эти инструменты можно вернуть, если
// параметр объявить как ссылку/указатель на массив, однако для этого нужно
// точно знать размерность. Если размерность неизестна, то остается передавать
// дополнительные параметры для работы с элементами массива.

void print(int (&arry)[10]) {
  auto begin = std::begin(arry);
  auto end = std::end(arry);
  while (begin != end) std::cout << *begin++ << " ";
  std::cout << std::endl;
}

int main() {
  int ia[10];  // Определение массива по умолчанию. Все элементы имеют
               // неопределенное состояние.

  print(ia);

  // Данный цикл присвоит значения всем элементам массива от 0 до 9.
  for (int i = 0; i != 10; ++i) {
    get(ia, i) = i;  // Вызов функции, результат которой ссылка на элемента
                     // массива. Эта ссылка является l-value, следовательно ей
                     // можно присовить значение. В данном случае присовение
                     // значения элементу по индексу.
  }

  print(ia);
}

// Программа написана корректно.