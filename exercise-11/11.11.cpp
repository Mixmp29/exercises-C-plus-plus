// Упражнение 11.11. Переопределите bookstore, не используя спецификатора
// decltype.

#include <set>

#include "Sales_data3.h"

bool compareIsnb(const Sales_data &lhs, const Sales_data &rhs) {
  return lhs.isbn() < rhs.isbn();
}

int main() {
  std::multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)>
      bookstore(compareIsnb);
}