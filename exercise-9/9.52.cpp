// Упражнение 9.52. Используйте стек для обработки выражений со скобками.
// Встретив открывающую скобку, запомните ее положение. Встретив закрывающую
// скобку, после открывающей скобки, извлеките эти элементы, включая открывающую
// скобку, и поместите полученной значение в стек, переместив таким образом
// заключенное в скобки выражение.

// Задание мне показалось довольно расплывчатым, возможно перевод очень корявый.
// Вот такое же задание из другого издания книги на английском:
// Use a stack to  process parenthesized expressions. When you see an open
// parenthesis, note that it was seen. When you see a close parenthesis after an
// open parenthesis, pop elements down to and including the open parenthesis off
// the stack. push a value onto the stack to indicate that a parenthesized
// expression was replaced.

// Используйте стек для обработки выражений в скобках. Когда вы увидите
// открывающуюся скобку, обратите внимание, что она была замечена. Когда вы
// видите закрывающуюся скобку после открывающей скобки, извлеките элементы из
// стека вниз до открывающей скобки и включая ее. Поместите значение в стек,
// чтобы указать, что выражение в скобках было заменено.

/*
Пример:
фждвылоажфдывло жфдло (жфдло(пдфыфджваождфы)ф) жфдло (фждло) жфдло

допустим, "метка" выглядит так: ***

после обработки должна получиться строчка:
фждвылоажфдывло жфдло (жфдло***ф) жфдло *** жфдло */

#include <iostream>
#include <stack>
#include <string>

int main() {
  char ch;
  bool lbrace;
  std::stack<char> expression;

  while (std::cin >> ch) {
    if (ch == '(') lbrace = true;

    if (ch == ')' && lbrace == true) {
      // Удалить все элементы до скобки '('.
      while (expression.top() != '(') expression.pop();
      expression.pop();  // Удалить скобку '('.
      lbrace = false;
      // Добавить 3 знака '*' на место вырезанного выражения.
      expression.push('*');
      expression.push('*');
      expression.push('*');
      continue;
    }

    expression.push(ch);
  }

  while (!expression.empty()) {
    std::cout << expression.top() << std::endl;
    expression.pop();
  }
}