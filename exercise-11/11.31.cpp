// Упражнение 11.31. Напишите программу, определяющую контейнер multimap авторов
// и их работ. Используйте функцию find() для поиска элемента и его удаление.
// Убедитесь в корректности работы программы, когда искомого элемента нет в
// карте.

#include <iostream>
#include <map>
#include <string>

int main() {
  std::multimap<std::string, std::string> author;
  author.insert({"Tolstoy", "War and Peace"});
  author.insert({"Tolstoy", "Anna Karenina"});
  author.insert({"Dostoevsky", "Dead Souls"});
  author.insert({"Dostoevsky", "Сrime and punishment"});

  // Можно это использовать, но написано использовать find() для поиска.
  // auto erase = author.equal_range("Dostoevsky");

  for (auto beg = author.find("Dostoevsky"); beg != author.end();
       beg = author.find("Dostoevsky"))
    author.erase(beg);

  if (author.find("Dostoevsky") == author.end())
    std::cout << "All works of Dostoevsky have been deleted" << std::endl;
}