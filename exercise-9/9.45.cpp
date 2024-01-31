// Упражнение 9.45. Напишите функцию, получающую строку, представляющую имя и
// две другие строки, представляющие префикс, такой, как "Mr." или "Ms.", а
// также суффикс, такой, как "Jr." или "III". Используя итераторы, а также
// функции insert и append(), создайте новую строку с суффиксом и префиксом,
// добавленным к имени.

#include <iostream>
#include <string>

// Проще использовать индекс, но в задании написано про итератор.

std::string fullName(std::string name, const std::string prefix,
                     const std::string suffix) {
  name.insert(name.begin(), prefix.begin(), prefix.end());
  name.append(suffix);
  return name;
}

int main() { std::cout << fullName("Carl", "Mr. ", " III") << std::endl; }