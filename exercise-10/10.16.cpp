// Упражнение 10.16. Напишите собственную версию функции beiggies(), используя
// лямбда-выражения.

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
  auto wc = find_if(words.begin(), words.end(),
                    [sz](const std::string& s) { return s.size() >= sz; });
  auto count = words.end() - wc;
  std::cout << count << " " << make_plural(count, "word", "s") << " of length "
            << sz << " or longer" << std::endl;

  std::for_each(wc, words.end(),
                [](const std::string& s) { std::cout << s << " "; });
  std::cout << std::endl;
}

int main() {
  std::vector<std::string> svec;
  std::string word;
  while (std::cin >> word) svec.push_back(word);
  biggies(svec, 5);
}