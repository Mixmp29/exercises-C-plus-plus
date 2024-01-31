// Упражнение 8.8. Пересмотрите программу из предыдущего упражнения так, чтобы
// добавить ее вывод в заданный файл. Запустите программу для того же выходного
// файла по крайней мере дважды и удостоверьтесь, что данные сохраняются.

// Упражнение 8.7. Пересмотрите программу книжного магазина из предыдущего
// раздела так, чтобы вывод записывался в файл. Передайте имя этого файла как
// второй аргумент функции main().

#include <fstream>
#include <iostream>

#include "Sales_data3.h"

int main(int argc, char** argv) {
  Sales_data total;

  std::ifstream input(argv[1]);  // exercise-8/infile.txt
  std::ofstream output(argv[2],
                       std::ofstream::app);  // "exercise-8/outfile.txt"

  if (read(input, total)) {
    Sales_data trans;

    while (read(input, trans)) {
      if (total.isbn() == trans.isbn()) {
        total.combine(trans);
      } else {
        print(output, total) << '\n';
        total = trans;
      }
    }
    print(output, total) << '\n';
  } else {
    std::cerr << "No data?!" << std::endl;
    return -1;
  }

  input.close();
  output.close();

  return 0;
}