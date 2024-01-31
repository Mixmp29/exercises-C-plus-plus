// Упражнение 14.39. Перепешите предыдущую программу так, чтобы сообщать
// количество слов размером от 1 до 9 и 9 или более.

#include <fstream>
#include <iostream>
#include <string>

class CheckFile {
 public:
  CheckFile(size_t s) : size(s) {}
  int operator()(std::ifstream& file) {
    std::string word;
    int count = 0;
    while (file >> word) {
      if (word.size() >= 1 && word.size() <= size) ++count;
    }

    return count;
  }

 private:
  size_t size;
};

int main() {
  CheckFile checkFile(15);
  std::ifstream file("exercise-14/terms.txt");
  std::cout << checkFile(file) << std::endl;
}