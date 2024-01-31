// Упражнение 10.22. Перепешите программу подсчета слов размером 6 символов с
// использованием функций вместо лямбда-выражений.

// Тут отсылка к заданию 10.20. Честно говоря, я не совсем понял, что за
// программа на проверку размера 6 символов тогда требоавалась, когда
// показывался пример только sz. Возможно это нужно было сделать отдельно, я же
// сделал в этом коде. Судя по всему упражнения дальше также нужно постепенно
// заменять на обычные функции с bind(), что уже сделано в этом коде.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std::placeholders;

std::string make_plural(int count, const std::string& word,
                        const std::string& ending) {
  return (count > 1) ? word + ending : word;
}

bool isShorter(const std::string& str1, const std::string& str2) {
  return str1.size() < str2.size();
}

bool checkSZ(const std::string& s, std::string::size_type sz) {
  return s.size() >= sz;
}

std::ostream& print(std::ostream& os, const std::string& s, const char ch) {
  return os << s << ch;
}

void elimDups(std::vector<std::string>& word) {
  std::sort(word.begin(), word.end());
  auto end_unic = std::unique(word.begin(), word.end());
  word.erase(end_unic, word.end());
}

void biggies(std::vector<std::string>& words, std::string::size_type sz,
             std::ostream& os = std::cout, char ch = ' ') {
  elimDups(words);

  stable_sort(words.begin(), words.end(), isShorter);

  auto wc = std::stable_partition(words.begin(), words.end(),
                                  std::bind(checkSZ, _1, sz));

  auto count =
      std::count_if(words.begin(), words.end(), std::bind(checkSZ, _1, sz));

  std::cout << count << " " << make_plural(count, "word", "s") << " of length "
            << sz << " or longer" << std::endl;

  std::for_each(words.begin(), wc, std::bind(print, ref(os), _1, ch));
  std::cout << std::endl;
}

int main() {
  std::vector<std::string> svec;
  std::string word;
  while (std::cin >> word) svec.push_back(word);
  biggies(svec, 6);
}