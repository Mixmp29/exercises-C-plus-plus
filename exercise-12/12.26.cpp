// Упражнение 12.26. Перепешите программу на стр. 613, используя класс
// allocator.

#include <iostream>
#include <memory>
#include <string>

int main() {
  std::size_t n = 32;
  std::allocator<std::string> alloc;
  std::string *const p = alloc.allocate(n);
  std::string s;
  std::string *q = p;

  while (std::cin >> s && q != p + n) *q++ = s;

  const std::size_t size = q - p;

  // delete [] p не нужен. Нужна специальная очистка и освобождение для объекта
  // типа allocator.

  // Удалить каждый созданный элемент.
  while (q != p) {
    alloc.destroy(--q);
  }

  // Освободить всю зарезервированную память.
  alloc.deallocate(p, n);
}