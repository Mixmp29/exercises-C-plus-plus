// Упражнение 14.38. Напишите класс, проверяющий соответствие длины заданной
// строки указанному значению. Используйте такой объект в программе для
// оповещения о количестве слов во входном файле, имеющий размеры от 1 до 10
// включительно.

#include <fstream>
#include <iostream>
#include <string>

class CheckFile {
 public:
  int operator()(std::ifstream& file) {
    std::string word;
    int count = 0;
    while (file >> word) {
      if (word.size() >= 1 && word.size() <= 10) ++count;
    }

    return count;
  }

 private:
};

int main() {
  CheckFile checkFile;
  std::ifstream file("exercise-14/terms.txt");
  std::cout << checkFile(file) << std::endl;
}