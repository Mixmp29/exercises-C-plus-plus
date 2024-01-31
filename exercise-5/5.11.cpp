#include <iostream>

// Упражнение 5.11. Измените рассматриваемую программу так, чтобы она
// подсчитывала также количество пробелов, символов табуляции и новой строки.

int main() {
  std::string str;
  int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0,
      tabCnt = 0, newStrCnt = 0;

  // Пришлось вспоминать как работают строки.

  // Поскольку обычный ввод cin считывает только видимые символы, необходимо
  // считывать строку полностью. После чего проходиться по каждому символу
  // строки и искать нужные.
  while (std::getline(std::cin, str)) {
    for (char ch : str) {
      switch (ch) {
        case 'a':
        case 'A':
          ++aCnt;
          break;
        case 'e':
        case 'E':
          ++eCnt;
          break;
        case 'i':
        case 'I':
          ++iCnt;
          break;
        case 'o':
        case 'O':
          ++oCnt;
          break;
        case 'u':
        case 'U':
          ++uCnt;
          break;
        case ' ':
          ++spaceCnt;
          break;
        case '\t':
          ++tabCnt;
          break;
      }
    }
    ++newStrCnt;  // Так как getline() отбрасывает '\n' в конце каждой строки
                  // достаточно делать инкремент после каждого цикла, потому как
                  // это эквиалентно действию перехода на нову стоку.
  }

  std::cout << '\n'
            << "Number of vowel a: \t" << aCnt << '\n'
            << "Number of vowel e: \t" << eCnt << '\n'
            << "Number of vowel i: \t" << iCnt << '\n'
            << "Number of vowel o: \t" << oCnt << '\n'
            << "Number of vowel u: \t" << uCnt << '\n'
            << "Number of space: \t" << spaceCnt << '\n'
            << "Number of tab: \t\t" << tabCnt << '\n'
            << "Number of new line: \t" << newStrCnt << std::endl;
}