// Упражнение 11.19. Определите переменную, инициализированную вызовом функции
// begin() контейнера multiset по имени bookstore из раздела 11.2.2 (стр. 543).
// Определите тип переменной, не используя ключевое слово auto или decltype.

#include <set>

#include "Sales_data3.h"

bool compareIsnb(const Sales_data &lhs, const Sales_data &rhs) {
  return lhs.isbn() < rhs.isbn();
}

int main() {
  std::multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)>
      bookstore(compareIsnb);

  std::multiset<Sales_data, bool (*)(const Sales_data &,
                                     const Sales_data &)>::iterator mset_it =
      bookstore.begin();
}