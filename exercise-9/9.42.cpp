// Упражнение 9.42. Учитывая, что символы в строку следует читать по одному и
// заранее известно, что прочитать предстоит по крайней мере 100 символов, как
// можно было бы улучшить производительность программы?

// Из того, что пройдено по строке, не ясно, что нужно использовать. Возможно
// имеется в виду capacity. Можно заранее зарезервировать память под 100
// элементов, тогда строке не придется переносить кучу элементов типа char в
// случае резериварования при добавлении элемента.

#include <iostream>

int main() {
  std::string str;

  str.reserve(100);

  for (int i = 0; i < 100; ++i) {
    char ch;
    std::cin >> ch;
    str += ch;
  }

  std::cout << str << std::endl;

  std::cout << "size: " << str.size() << ", capacity: " << str.capacity()
            << std::endl;
}