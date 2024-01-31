// Упражнение 9.40. Если программа в предыдущем упражнении читает 256 слов,
// какова ее вероятная емкость после вызова функции resize()? Что, если она
// читает 512? 1000 или 1048 слов.

#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> svec;  // size: 0, capacity 0.
  svec.reserve(1024);  // Резервирование памяти на 1024 элементов.
  std::string word;  // size: 0, capacity: 0;
  unsigned count;

  std::cout << "Write down the number of words entered in the theory: ";
  std::cin >> count;

  for (unsigned i = 0; i < count; ++i) svec.push_back("word");
  svec.resize(svec.size() + svec.size() / 2);

  std::cout << "size: " << svec.size() << ", capacity: " << svec.capacity()
            << std::endl;

  // 256 ->  size: 384, capacity: 1024.
  // 512 ->  size: 768, capacity: 1024.
  // 1000 -> size: 1500, capacity: 2000.
  // 1024 -> size: 1536, capacity: 2048.
  // 683 ->  size: 1024, capacity: 1024.
  // 684 -> size: 1026, capacity: 1368.

  // Судя по всему увеличение capacity в 2 раза зависит от size перед
  // резервированием и выполнением функции resize().
  // То есть по сути capacity = size * 2.
}