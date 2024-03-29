// Упражнение 9.33. Что будет, если в последнем примере этого раздела не
// присваивать переменной begin результат вызова функции insert()? Напишите
// программу без этого присвоения, чтобы убедиться в правильности своего
// предположения.

// Можно было бы предположить, что он бы просто некорректно работал и пропускал
// половину значений, может даже иногда перепрыгивал end(), однако стоит
// помнить, что итераторы после вставки уже не являются корректными, то есть они
// уже не указывают на элемент, который должен быть после вставленного элемента.
// Если проследить ошибки через debug, то будет видно, что после insert() begin
// сбивается и после первой итерации добавляет значения подсчитанные непонятно
// каким образом. После ломается где-то внутри (пока не понимаю на чем именно,
// дошел до delete в файле new_allocator). В общем программ пошла по
// непредсказуемому пути. Компилятор не увидит ошибки, она проявится во время
// выполнения программы.

#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};

  auto begin = v.begin();

  while (begin != v.end()) {
    ++begin;
    v.insert(begin, 42);
    ++begin;  // Итератор уже не валиден для использования.
  }

  for (auto elem : v) std::cout << elem << ' ';
  std::cout << std::endl;
}