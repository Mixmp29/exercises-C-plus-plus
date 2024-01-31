// Упражнение 9.28. Напишите функцию, получающую контейнер forward_list<string>
// и два дополнительных аргумента типа string. Функция должна находить первую
// строку и вставлять вторую непосредственно после первой. Если первая строка не
// найдена, то вставьт вторую строку в конец списка.

#include <forward_list>
#include <iostream>
#include <string>

void find_and_insert(std::forward_list<std::string>& f_list, std::string first,
                     std::string second) {
  bool not_find = true;
  auto curr = f_list.begin();
  auto before_end = f_list.before_begin();  // На случай, если слово не найдено.
  while (curr != f_list.end()) {
    if (*curr == first) {
      curr = f_list.insert_after(
          curr,
          second);  // Тут думал, использовать insert или emplace? Потом
                    // вспомнил, что emplace лучше использовать, когда
                    // нужно явно задать нужные аргументы параметрам
                    // конструктора класса объекта. То есть в данном
                    // случае нужно просто добавить копию объекта, не более.
      not_find = false;
    } else {
      before_end = curr;
      ++curr;
    }
  }

  if (not_find) f_list.insert_after(before_end, second);
  // before_end был нужен так как, у контейнера forward_list нет декремента.
  // Нельзя воспользоваться итератором --curr.
}

int main() {
  std::forward_list<std::string> f_list = {"Gary", "Sanderson", "John",
                                           "Vladimir", "Makarov"};

  find_and_insert(f_list, "John", "MacTavish");

  for (auto elem : f_list) {
    static int firstlast = 0;
    std::cout << elem << ' ';
    if (firstlast % 2) std::cout << std::endl;
    ++firstlast;
  }
}