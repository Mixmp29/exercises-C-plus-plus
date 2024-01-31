// Упражнение 9.39. Объясните, что выполняет следующий фрагмент программы:

#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> svec;  // size: 0, capacity 0.
  svec.reserve(1024);  // Резервирование памяти на 1024 элементов.
  std::string word;  // size: 0, capacity: 0;

  // Добавлять элементы до конца файла или ошибки ввода.
  while (std::cin >> word)
    //  Размер будет расти, емкость нет, пока размер не превысит ее.
    svec.push_back(word);

  // Увеличить размер (size) вектора в 1,5 раза.
  svec.resize(svec.size() + svec.size() / 2);
}