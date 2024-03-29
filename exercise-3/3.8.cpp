#include <iostream>
#include <string>

// Упражнение 3.8. Перепешите программу первого упражнения, сначала используя
// оператор while, а затем традиционный цикл for. Какой из этих трех подходов вы
// предпочитаете и почему?

int main() {
  std::string str("Hello, World!");
  std::string::size_type i = 0;

  while (i < str.size()) {
    str[i] = 'X';
    ++i;
  }

  for (decltype(str.size()) i = 0; i < str.size(); ++i) {
    str[i] = 'Y';
  }

  std::cout << str << std::endl;

  // Предпочтительнее использовать классический for, так как в задаче исзестно
  // количество итераций с помощью функции члена size(). В нём сразу видно от
  // какого до какого символа пойдёт перебор.
  // В while делать интерации не очень удобно. Ещё я там забыл поставить
  // инкрмент индекса :). While предпочтительней использовать, если по условию
  // неизвестно, когда условие цикла станет ложным.
}