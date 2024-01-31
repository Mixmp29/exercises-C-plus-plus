// Упражнение 12.20. Напишите программу, которая построчно читает исходный файл
// в операционной системе класса StrBlob и использует указатель StrBlobPtr для
// вывода каждого элемента.

#include <fstream>
#include <iostream>
#include <sstream>

#include "StrBlob.h"

int main() {
  std::ifstream in("exercise-12/Values.txt");
  std::string line;

  StrBlob blob;

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