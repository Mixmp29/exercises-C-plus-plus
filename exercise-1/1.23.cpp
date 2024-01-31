#include <iostream>

#include "Sales_item.h"

// Упражнение 1.23-1.24. Напишите программу, которая читает несколько транзакций
// и подсчитывает количество транзакций для каждого ISBN. Записи для каждого
// ISBN должны быть сгрупированы.

int main() {
  Sales_item currTrans, trans;

  if (std::cin >> currTrans) {
    int count = 1;

    while (std::cin >> trans) {
      if (currTrans.isbn() == trans.isbn()) {
        ++count;
      } else {
        std::cout << "ISBN " << currTrans.isbn() << " has " << count
                  << " transactions" << std::endl;
        currTrans = trans;
        count = 0;
      }
    }
    std::cout << "ISBN " << currTrans.isbn() << " has " << count
              << " transactions" << std::endl;
  }

  return 0;
}

/* #include <iostream>
#include <map>

#include "Sales_item.h"

int main() {
  std::map<std::string, int> transISBN;
  Sales_item trans;

  while (std::cin >> trans) {
    if (transISBN.find(trans.isbn()) != transISBN.end()) {
      transISBN[trans.isbn()]++;
    } else {
      transISBN[trans.isbn()] = 1;
    }
  }

  for (auto& [isbn, count] : transISBN) {
    std::cout << isbn << ": " << count << std::endl;
  }

  return 0;
} */