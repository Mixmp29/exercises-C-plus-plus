#include <iostream>
#include <string>
#include <vector>

// Упражнение 3.17. Прочитайте последовательность слов из потока cin и сохраните
// их в векторе. Прочитав все слова, обработайте вектор и переведите символы
// каждого слова в верхний регистр. Отобразите преобразованные элементы по
// восемь слов на строку.

int main() {
  std::string word;
  std::vector<std::string> text;

  while (std::cin >> word) {
    text.push_back(word);
  }

  for (std::vector<int>::size_type i = 0, countStr = 0; i < text.size(); ++i) {
    // toupeer можно было сделать и предыдущем цикле сразу, но, для большего
    // разбора раздела и соответствия заданию, функция была использована в этом.
    for (char &c : text[i]) {
      c = toupper(c);
    }

    std::cout << text[i] << " ";

    ++countStr;

    // Поскольку по книге ещё не был изучен опертор деления с остатком %, был
    // добавлен счетчик слов countStr.
    if (countStr == 8) {
      std::cout << '\n';
      countStr = 0;
    }
  }
}