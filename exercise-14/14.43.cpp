// Упражнение 14.43. Используя библиотечные объекты функций, определите, делимо
// ли переданное значение типа int на некйи элемент в контейнере целых чисел.

// Буквально воспринял задание с неким элементом. Скорее имелся в виду поиск. В
// таком случае можно сделать find_if() c макросом функции для деления.

#include <functional>
#include <iostream>
#include <vector>

struct completeDivision {
  bool operator()(int val, size_t index, std::vector<int> &vec) {
    return !std::modulus<int>()(val, vec[index]);
    //     ^
    //     |
    // Не забыть обратить внимание на этот знак.
  }
};

int main() {
  completeDivision cd;
  std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
  std::cout << cd(3, 2, vec) << std::endl;
}