// Упражнение 8.12. Почему в классе PersonInfo не использованы внутриклассовые
// инициализаторы?

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Переменная name инициализируется значением по умолчанию "".
// А в векторе неизветсно сколько будет элементов, поэтому объявления
// достаточно.

struct PersonInfo {
  std::string name;  // Инициализируется по умолчанию "".
  std::vector<std::string> phones;
};