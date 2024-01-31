#include <iostream>

// Упражнение 5.20. Напишите программу, которая читает последовательность строк
// со стандартного устройства ввода до тех пор, пока не встретится повторяющееся
// слово или пока ввод слов не будет закончен. Для чтения текста по одному слову
// используйте цикл while. Для выхода из цикла при встрече двух совпадающих слов
// подряд используйте оператора break. Выведите повтояющееся слово, если оно
// есть, а в противном случае отобразите сообщение, свидетельствующее о том, что
// повторяющихся слов нет.

int main() {
  std::string repeat, word;

  while (std::cin >> word) {
    if (word == repeat) break;
    repeat = word;
  }

  if (word == repeat) std::cout << "Repeat word: " << repeat << std::endl;
}