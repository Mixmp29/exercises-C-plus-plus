#include <iostream>

// Упражнение 5.10. Программа подсчета гласных имеет одну проблему: она не
// учитывает заглавные буквы как гласные. Напишите программу, которая
// подсчитывает гласные буквы как в верхнем, так и в нижнем регистре. То есть
// значение счетчика aCnt должно увеличиваться при встрече как символа 'a', так
// и символа 'A' (аналогично для остальных гласных букв).

int main() {
  char ch;
  int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;

  while (std::cin >> ch) {
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
    }
  }

  std::cout << '\n'
            << "Number of vowel a: \t" << aCnt << '\n'
            << "Number of vowel e: \t" << eCnt << '\n'
            << "Number of vowel i: \t" << iCnt << '\n'
            << "Number of vowel o: \t" << oCnt << '\n'
            << "Number of vowel u: \t" << uCnt << std::endl;
}