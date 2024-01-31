// Упражнение 8.6. Перепишите программу книжного магазина из раздела 7.1.1 (стр.
// 333) так, чтобы читать транзакции из файла. Передавайте имя файла как
// аргумент функции main() (см. раздел 6.2.5, стр. 288).

#include <fstream>
#include <iostream>

#include "Sales_data3.h"

int main(int argc, char** argv) {
  Sales_data total;

  // На заметку: если копилировать файл из другой дирриктории, то файл будет
  // искаться именно в этой другой дирректории.

  // Я компилирую файлы так: "g++ -Wall -o exercise-8/execute/8.6 exercise-8".
  // Файл у меня в exercise-8. Но искать он будет не в exercise-8, а в месте,
  // где компилируются файлы.

  std::ifstream input(argv[1]);  // exercise-8/infile.txt

  if (read(input, total)) {
    Sales_data trans;

    while (read(input, trans)) {
      if (total.isbn() == trans.isbn()) {
        total.combine(trans);
      } else {
        print(std::cout, total) << '\n';
        total = trans;
      }
    }
    print(std::cout, total) << '\n';
  } else {
    std::cerr << "No data?!" << std::endl;
    return -1;
  }

  input.close();

  return 0;
}