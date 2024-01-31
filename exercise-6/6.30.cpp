#include <iostream>
#include <string>

// Упражнение 6.30. Откомпилируйте версию функции str_subrange(), представленной
// на стр. 298, и посмотрите, что ваш компилятор делает с указанными сообщениями
// об ошибках.

bool str_subrange(const std::string &str1, const std::string &str2) {
  if (str1.size() == str2.size()) return str1 == str2;

  auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();

  for (decltype(size) i = 0; i != size; ++i) {
    if (str1[i] != str2[i]) return false;
  }
}

// Компилятор ругается на 13 строчку и говорит: оператор return без значения в
// функции с возвращаемым значением типа bool.

// Если все же поставить какой-нибудь false в return и пройти весь цикл, то
// компилятор просто будет предупреждать, что работа функции долшла до конца. В
// таком случае результат bool будет неопределенным и при попытке вывести его
// значение выдаст результат 2.

int main() {
  bool subrange = str_subrange("hi", "hie");
  std::cout << subrange << std::endl;
}