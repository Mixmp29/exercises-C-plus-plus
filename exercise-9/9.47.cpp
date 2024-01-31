// Упражнение 9.47. Напишите программу, которая находит в строке "ab2c3d7R4E6"
// каждую цифру, а затем каждую букву. Напишите две версии программы: с
// использованием функции find_first_of() и функции find_first_not_of().

#include <iostream>
#include <string>

void find_first(const std::string& str, std::string numbers) {
  std::string::size_type pos = 0;
  while ((pos = str.find_first_of(numbers, pos)) != std::string::npos) {
    std::cout << "Find number at index: " << pos << " elem is " << str[pos]
              << std::endl;
    ++pos;
  }

  pos = 0;
  while ((pos = str.find_first_not_of(numbers, pos)) != std::string::npos) {
    std::cout << "Find character at index: " << pos << " elem is " << str[pos]
              << std::endl;
    ++pos;
  }
}

void find_last(const std::string& str, std::string numbers) {
  std::string::size_type pos = str.size() - 1;
  while ((pos = str.find_last_of(numbers, pos)) != std::string::npos) {
    std::cout << "Last number at index: " << pos << " elem is " << str[pos]
              << std::endl;
    if (pos == 0)
      break;
    else
      --pos;
  }

  pos = str.size() - 1;
  while ((pos = str.find_last_not_of(numbers, pos)) != std::string::npos) {
    std::cout << "Last character at index: " << pos << " elem is " << str[pos]
              << std::endl;
    if (pos == 0)
      break;
    else
      --pos;
  }
}

int main() {
  std::string str = "ab2c3d7R4E6";
  std::string numbers = "0123456789";

  find_first(str, numbers);
  find_last(str, numbers);
}