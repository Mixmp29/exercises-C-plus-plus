#include <iostream>
#include <string>
#include <vector>

// Упражнение 5.14. Напишите программу для чтения строк сто стандартного
// устройства ввода и поиска совпадающих слов. Программа должна находить в
// вводе максимальнгое количество дубликатов или сообщение, что никаких
// повторений не было. Например, при вводе how now now now brown cow cow вывод
// должен указать, что слово now встретилось три раза.

int main() {
  // Есть более простые пути решения этой задачи. К прмеру можно использовать
  // контейнер map или использовать алгоритмы поиска с подсчетом, однако,
  // поскольку таких инструментов еще по тексту не встречалось, попробую
  // обойтись без них.

  std::string word, maxWord;  // Слово и слово, которое будет хранить
                              // максимальное значение.
  int max = 0;  // Максимального значение повторения слова.
  std::vector<std::string> text;  // Текст будет храниться в одномерном векторе,
                                  // для задачи этого хватит и так будет проще.
  std::vector<std::string> dictionary;  // Словарь слов из текста
                                        // без повторений.

  while (std::cin >> word) {
    // Сбор всего текста.
    text.push_back(word);

    // Cбор слов без повторений.
    if (dictionary.begin() == dictionary.end()) {  // Проверка на пустой вектор.
      dictionary.push_back(word);  // Если он пустой, то добавить первое слово.
    } else {
      for (size_t i = 0; i <= dictionary.size(); ++i) {
        if (dictionary[i] == word)  // Если слово уже есть, то выйти из цикла
          break;
        // Если слова в векторе нет, то добавить.
        else if (i + 1 == dictionary.size())
          dictionary.push_back(word);
      }
    }
  }

  // Поиск максимально повторяемого слова.
  for (auto dword : dictionary) {
    int count = 0;

    for (auto tword : text) {
      // Если слово находится в тексте, то увеличить его счетчик, столько раз
      // сколько он повторяется.
      if (dword == tword) count++;
    }

    // После поиска определение нового максимально повторяемого слова
    if (max < count) {
      max = count;
      maxWord = dword;
    }
  }

  if (max == 0)
    std::cout << "No repeated words." << std::endl;
  else
    std::cout << "Word \"" << maxWord << "\" repeated " << max << " times."
              << std::endl;
}