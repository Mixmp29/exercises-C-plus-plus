#include <iostream>

// Упражнение 5.9. Напишите программу, использующую серию операторов if для
// подсчета количества гласных букв в тексте, прочитанном из потока cin.

int main() {
  char ch;
  int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;

  while (std::cin >> ch) {
    if (ch == 'a')
      ++aCnt;
    else if (ch == 'e')
      ++eCnt;
    else if (ch == 'i')
      ++iCnt;
    else if (ch == 'o')
      ++oCnt;
    else if (ch == 'u')
      ++uCnt;
  }

  std::cout << '\n'
            << "Number of vowel a: \t" << aCnt << '\n'
            << "Number of vowel e: \t" << eCnt << '\n'
            << "Number of vowel i: \t" << iCnt << '\n'
            << "Number of vowel o: \t" << oCnt << '\n'
            << "Number of vowel u: \t" << uCnt << std::endl;
}