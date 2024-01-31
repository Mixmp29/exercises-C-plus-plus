// Упражнение 12.22. Какие изменения следует внести в класс StrBlobPtr,
// чтобы получить класс, применимый с типом const StrBlob? Определить класс по
// имени ConstStrBlopPtr, способный указывать на const StrBlob.

#include <fstream>
#include <iostream>
#include <sstream>

#include "StrBlob.h"

// Класс дописан в StrBlob.h
// Класс повторяет StrBlobPtr: объявление, дружеские отношения, функции.
// Ключевым моментом пожалуй является определение конструктора с константным
// параметром типа StrBlob, объявление и определение константный функци-членов
// begin и end с типом ConstStrBlobPtr. Этот класс можно полноценно
// использовать вместо StrBlobPtr.

int main() {
  std::ifstream in("exercise-12/Values.txt");
  std::string line;

  const StrBlob blob;

  while (getline(in, line)) {
    std::string sval;
    std::istringstream str(line);
    while (str >> sval) blob.push_back(sval);
    for (auto beg = blob.begin(), end = blob.end(); compare(beg, end);
         beg.incr()) {
      std::cout << beg.deref() << " ";
    }
    std::cout << std::endl;

    for (int i = 0, e = blob.size(); i < e; ++i) {
      blob.pop_back();
    }
  }
}