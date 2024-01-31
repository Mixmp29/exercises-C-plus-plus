#include <iostream>

// Упражнение 3.37. Что делает следующая программа?

int main() {
  const char ca[] = {'h', 'e', 'l', 'l', 'o'};
  // Определение массива типа const char и его инициализация списком без
  // нулевого символа (функции для строк с этим массивом лучше не использовать).

  const char *cp = ca;
  // Указатель на массив ca. Имя ca само является указателем, при его обращении
  // оно возвращает адрес, поэтому не нужен оператор обращиния к адресу &.

  while (*cp) {  // Пока перебор не наткнется на пустое (неинициализированное)
                 // значение
    std::cout << cp << std::endl;  // вывести значение по адресу в указателе.
    ++cp;
  }

  // С массивом строк правда есть и другие способы вывода.

  std::cout << ca << std::endl;  // Выведет всю строку.
}