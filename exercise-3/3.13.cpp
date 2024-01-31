#include <iostream>
#include <string>
#include <vector>

// Упражнение 3.13. Сколько элементов находится в каждом из следующих векторов?
// Каковы значения этих элементов?

int main() {
  std::vector<int>
      v1;  // Объявлен vecotor типа int, где нет ни единого элемента. Обращение
           // к несуществующему элменту через оператор индексирования [] будет
           // дозволено при создании компилятором исполняемого файла, но после
           // его запуска выдаст оибку сегментирования (образ памяти сброшен на
           // диск) из-за обращения к памяти, доступ к которой запрещён.

  std::vector<int> v2(
      10);  // Последовательность из 10 элементов, инициализированных типом int
            // значением по умолчанию 0.

  std::vector<int> v3(10, 42);  // Последовательность из 10 элементов,
                                // инициализированных значением 42.

  std::vector<int> v4{10};  // Последоватльность из одного элемента,
                            // инциализированного значением 10. Типы совпадают,
                            // предусмотрена списочная инциализация.

  std::vector<int> v5{
      10, 42};  // Последовательность из 2 элементов, инициализированных
                // значениями 10 и 42 соответственно. Типы совпадают, списочная
                // инициализация возможна.

  std::vector<std::string> v6{
      10};  // Последовательность из 10 элементов. Попытка инициализации списком
            // из одного элемента со значением 10. Однако 1) здесь несоответсвие
            // типов, 2) в классе string непредусмотрена списочная
            // инициализация значением int, поэтому компилятор будет искать
            // другие способы инициализации. Самое похожее это (10). Будут
            // созданы 10 объектов типа string. Если бы значения в списочной
            // инициализации были типа string, то всё было бы окей.

  std::vector<std::string> v7{
      10, "hi"};  // Последовательность из 10 элементов, каждый из которых
                  // инициализирован значением "hi".
}