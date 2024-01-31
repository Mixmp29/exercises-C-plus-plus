// Упражнение 10.13. Библиотека определяет алгоритм partition(), получающий
// предикат и делящий контейнер так, чтобы значения, для которых предикат
// возвращае true, раполагались в начале последовательности, а для которых он
// возвращает значение false - в конец. Алгоритм возвращает итератор на
// следующий элемент после последнего, для которого предикат возвратил значение
// true. Напишите функцию, которая получает строку и возвращает логическое
// значение, указывающее, содержит ли строка 5 символов и больше. Используйте
// эту функцию для разделения words. Выведите элементы, у которых есть пять или
// более симовлов.

#include <algorithm>
#include <iostream>
#include <string>

bool bigStr(const std::string& s) { return s.size() >= 5; }

int main() {
  std::vector<std::string> word = {"Hello,", "this", "is", "some", "string"};

  std::partition(word.begin(), word.end(), bigStr);

  for (auto elem : word) std::cout << elem << " ";
  std::cout << std::endl;
}