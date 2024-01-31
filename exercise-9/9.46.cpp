// Упражнение 9.46. Перепишите предыдущее упражнение, используя на сей раз
// позицию, длину и функцию insert().

#include <iostream>
#include <string>

// Во во, да.

std::string fullName(std::string name, const std::string prefix,
                     const std::string suffix) {
  name.insert(0, prefix, 0, prefix.size());
  name.append(suffix);

  return name;
}

int main() { std::cout << fullName("Carl", "Mr. ", " III") << std::endl; }