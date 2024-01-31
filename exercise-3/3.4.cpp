#include <iostream>
#include <string>

// Упражнение 3.4. Напишите программу, читающую две строки и сообщающую, равны
// ли они. В противном случае программа сообщает, которая из них больше. Затем
// измените программу так, чтобы она сообщала, одинаковая ли у строк длина, а в
// противном случае - которая из них длиннее.

int main() {
  std::string str1, str2;

  getline(std::cin, str1);
  getline(std::cin, str2);

  if (str1 == str2) {
    std::cout << "Lines are equal" << std::endl;
  } else {
    if (str1 > str2) {
      std::cout << "Line \"" << str1 << "\" is greater then \"" << str2 << "\""
                << std::endl;
    } else {
      std::cout << "Line \"" << str2 << "\" is greater then \"" << str1 << "\""
                << std::endl;
    }
  }

  if (str1.size() == str2.size()) {
    std::cout << "The lines are the same size" << std::endl;
  } else {
    if (str1.size() > str2.size()) {
      std::cout << "Size of the string \"" << str1
                << "\" is greater then size \"" << str2 << "\"" << std::endl;
    } else {
      std::cout << "Size of the string \"" << str2
                << "\" is greater then size \"" << str1 << "\"" << std::endl;
    }
  }
}