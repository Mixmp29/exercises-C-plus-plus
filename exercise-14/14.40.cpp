// Упражнение 14.40. Перепишите функцию biggies() из раздела 10.3.2 (стр. 501)
// так, чтобы использовать объект функции вместо лямбда-выражения.

// Можно взять изначальный код из 10.16.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct MinSort {
  bool operator()(const std::string& a, const std::string& b) {
    return a.size() < b.size();
  }
};

class SizeComp {
 public:
  SizeComp(size_t s) : size(s) {}

  bool operator()(const std::string& s) { return s.size() >= size; }

 private:
  size_t size;
};

class PrintString {
 public:
  PrintString(std::ostream& o = std::cout) : os(o) {}

  void operator()(const std::string& s) { std::cout << s << " "; }

 private:
  std::ostream& os;
};

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
  stable_sort(words.begin(), words.end(), MinSort());
  auto wc = find_if(words.begin(), words.end(), SizeComp(sz));
  auto count = words.end() - wc;
  std::cout << count << " " << make_plural(count, "word", "s") << " of length "
            << sz << " or longer" << std::endl;

  std::for_each(wc, words.end(), PrintString());
  std::cout << std::endl;
}

int main() {
  std::vector<std::string> svec;
  std::string word;
  while (std::cin >> word) svec.push_back(word);
  biggies(svec, 5);
}