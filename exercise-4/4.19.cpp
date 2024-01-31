#include <iostream>
#include <vector>

// Упражнение 4.19. С учетом того, что ptr указывает на тип int, vet - вектор
// vector<int>, а ival имеет тип int, объясните поведение каждого из следующих
// выражений. Есть ли среди них неправильные? Почему? как их исправить?

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5};
  int ival = 1;
  int* ptr = &ival;

  // В последующих двух выражениях все будет Оk, так как оператор '&&'
  // гарантирует последоавательную обработку слева на право.
  if (ptr != 0 && *ptr++)
    std::cout << "True\n";  // Ok. Сначала выполняется левое выражение от '&&',
                            // потом правое.
  if (ival++ && ival)
    std::cout << "True\n";  // Тоже самое. Результат (1 && 2) => (true && true)
                            // => true.

  ival = 1;

  // Здесь оператор '<=' не гарантирует последовательность обработки операндов,
  // поэтому поведение будет непредсказуемым. В зависимости от компилятора
  // результат может быть разным: сначала обработается либо левая часть, либо
  // правая. В моем случае компилятор просто ругается, что может быть
  // неопределена левая часть. В принципе он даже сделал обработку слева на
  // право.
  if (vec[ival++] <= vec[ival])
    std::cout << "True " << vec[ival++] << " " << vec[ival] << "\n";

  // Возможно имелось в виду следующее
  if (vec[ival] <= vec[ival + 1])
    std::cout << "True " << vec[ival] << " " << vec[ival + 1] << "\n";
  ;
}