#include <iostream>
#include <vector>

// Упражнение 5.17. Предположим, есть два вектора целых чисел. Напишите
// программу, определяющую, не является ли один вектор префиксом другого. Для
// векторов неравной длины сравнивайте количество элементов меньшего вектора.
// Например, если векторы содержат значения 0, 1, 1, 2 и 0, 1, 1, 2, 3, 5, 8
// соответственно, ваша программа должна возвратить true.

int main() {
  bool status;
  int val, sz1, sz2;
  std::vector<int> vec1;
  std::vector<int> vec2;

  std::cout << "Fill vec1 and vec2: " << std::endl;
  while (std::cin >> val) {
    if (val == -1)
      break;  // Если в вводе попался -1, то это сигнал на конец ввода в вектор.
    vec1.push_back(val);
  }
  while (std::cin >> val) {
    if (val == -1) break;
    vec2.push_back(val);
  }
  // Интересный случай. Если не делать проверку на -1, то тогда таким образом
  // нельзя заполнить два вектора. vec2 остается пустым.

  // Вариант ввода, если делать фиксированный размер заполняемого вектора
  // вручную.
  /* std::cout << "Enter vec1 size: ";
  std::cin >> sz1;

  std::cout << "Enter vec2 size: ";
  std::cin >> sz2;

  std::cout << "Fill vec1 and vec2: " << std::endl;
  for (int i = 0; i < sz1; vec1.push_back(val), ++i) std::cin >> val;
  for (int i = 0; i < sz2; vec2.push_back(val), ++i) std::cin >> val; */

  if (vec1.size() <=
      vec2.size()) {  // Используется size(), так как если просто сделать между
                      // ними обычное сравнение векторов, то может быть
                      // ситуация, что длинный вектор может стать меньше
                      // короткого, так как значения короткого могут в
                      // коком-либо месте стать больше, чем у длинного.
    for (size_t i = 0; i < vec1.size(); ++i) {
      if (vec1[i] != vec2[i])
        break;
      else if (i == vec1.size() - 1)
        status = true;
    }
  } else {
    for (size_t i = 0; i < vec2.size(); ++i) {
      if (vec2[i] != vec1[i])
        break;
      else if (i == vec2.size() - 1)
        status = true;
    }
  }

  if (status == 1)
    std::cout << "True" << std::endl;
  else
    std::cout << "False" << std::endl;
}