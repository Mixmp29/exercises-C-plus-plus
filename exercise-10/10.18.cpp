// Упражнение 10.18. Перепишите функцию biggiest() так, чтобы использовать
// алгоритм partition() вместо алгорима find_if(). Алгоритм partition() описан в
// упражнении 10.13. раздела 10.3.1 (стр. 496).

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string make_plural(int count, const std::string& word,
                        const std::string& ending) {
  return (count > 1) ? word + ending : word;
}

void print(std::vector<std::string>& vec) {
  for (auto elem : vec) std::cout << elem << " ";
  std::cout << std::endl;
}

void elimDups(std::vector<std::string>& word) {
  std::sort(word.begin(), word.end());
  auto end_unic = std::unique(word.begin(), word.end());
  word.erase(end_unic, word.end());
}

void biggies(std::vector<std::string>& words,
             std::vector<std::string>::size_type sz) {
  elimDups(words);
  stable_sort(words.begin(), words.end(),
              [](const std::string& a, const std::string& b) {
                return a.size() < b.size();
              });
  auto wc =
      std::partition(words.begin(), words.end(), [sz](const std::string& s) {
        return s.size() >= sz;
      });  // Похоже сортирует от большего к меньшему при таком условии. То есть
           // находит максимально подходящие элементы в убывающем порядке.
  auto count =
      wc - words.begin();  // Нужно не забыть поменять итераторы, так как
                           // большие части теперь находятся в начале.
  std::cout << count << " " << make_plural(count, "word", "s") << " of length "
            << sz << " or longer" << std::endl;

  std::for_each(words.begin(), wc, [](const std::string& s) {
    std::cout << s << " ";
  });  // Тоже самое, что коммент выше.
  std::cout << std::endl;
}

int main() {
  std::vector<std::string> svec;
  std::string word;
  while (std::cin >> word) svec.push_back(word);
  biggies(svec, 5);
}