// Упражнение 10.33. Напишите программу, получающую имена входного и двух
// выходных файлов. Входной файл должен содержать целые числа. Используя
// итератор istream_iterator, прочитайте входной файл. Используя итератор
// ostream_iterator, запишите нечетные числа в первый входной файл. За каждым
// значением должен следовать пробел. Во второй файл запишите четные числа.
// Каждое из этих значений должно быть помещено в отдельную строку.

#include <fstream>
#include <iterator>
#include <string>

int main() {
  std::ifstream in("exercise-10/values.txt");
  std::ofstream out_odd("exercise-10/odd_values.txt");
  std::ofstream out_even("exercise-10/even_values.txt");
  std::istream_iterator<int> iter_in(in), end_in;
  std::ostream_iterator<int> iter_out_odd(out_odd, " ");
  std::ostream_iterator<int> iter_out_even(out_even, "\n");

  while (iter_in != end_in)
    if (*iter_in % 2)
      *iter_out_odd++ = *iter_in++;
    else
      *iter_out_even++ = *iter_in++;
}