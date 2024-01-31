// Упражнение 9.49. У символов может быть надстрочная часть, расположенная выше
// середины строки, как у d или f, или подстрочная, ниже середины строки, как у
// p или g. Напишите программу, которая читает содержащий слова файл и сообщает
// самое длинное слово, не содержащее ни надстрочных, ни подстрочных элементов.

#include <fstream>
#include <iostream>
#include <string>

bool no_super_or_sub_script(const std::string word,
                            const std::string super_or_sub_script) {
  // Если в строке нет надстрочной или подстрочной части строки...
  if (word.find_first_of(super_or_sub_script) == std::string::npos)
    return true;
  else
    return false;
}

int main() {
  std::string superscript = "bdfhklt";
  std::string subscript = "gjpqy";
  std::string word;
  std::string max_word;
  std::string::size_type max_size = 0;

  std::ifstream input("exercise-9/text.txt");

  while (input >> word) {
    if (no_super_or_sub_script(word, superscript) &&
        no_super_or_sub_script(word, subscript) && word.size() > max_size) {
      max_size = word.size();
      max_word = word;
    }
  }
  input.close();

  std::cout << max_word << std::endl;
}