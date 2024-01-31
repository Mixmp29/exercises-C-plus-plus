#include <vector>

// Упражнение 3.19. Укажите три способа определения вектора и заполнения его
// десятью элементами со значением 42. Укажите, есть ли предпочтительный способ
// для этого и почему?

int main() {
  std::vector<int> v1(10, 42);  // Прямая инициализация

  std::vector<int> v2{42, 42, 42, 42, 42,
                      42, 42, 42, 42, 42};  // инициализация копированием списка

  std::vector<int> v2 = {
      42, 42, 42, 42, 42,
      42, 42, 42, 42, 42};  // тоже самое что и выше, наверное не в счет.

  std::vector<int> v4;

  for (int i = 0; i < 10; ++i) {
    v4.push_back(42);
  }  // инициализация вектора по ходу выполнения программы.

  // Предпочтительный способ зависит от обстоятелств. Очевидно, что написание
  // числа 42 даже по 10 раз уже выматывает, поэтому, если необходим вектор с
  // заранее уже известным значением, которое нужно повторить несокльо раз, то
  // лушче использовать прямую инициализацию оператором ().

  // Если же значения неизестны и неизвестно сколько их будет, то лучше
  // использовать последний вариант.

  // Также утверждается, что функция-член push_back() является технически
  // эффективной функцией и порой даже эффективнее (). На практике
  // действительно проще просто объявить вектор, а потом заполнять его по ходу
  // дела. (считать здоровый файл или взять значения из устройства ввода от
  // пользователя)
}