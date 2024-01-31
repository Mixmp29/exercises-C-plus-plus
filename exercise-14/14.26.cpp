// Упражнение 14.26. Определите операторы индексирования для классов SteVec,
// String, StrBlob и StrBlobPtr.

// Как по мне в книге должным образом не уделили внимание на индексирование
// элементов динамически созданного массива. Ранее гововрилось, что выделенный
// через оператор new T[n] "массив" не возвращает тип самого массива, а тип
// элемента массива. Из этого следует, что нельзя использовать функции
// библиотеки такие как begin(arr) и end(arr) для данного массива, в следствии
// нельзя использовать серийный цикл for. На первый взгляд может показаться, что
// индексирование через '[]' не работает. Для alloc было просто описано, что
// выделяется непрерывное хранилище соответствующего размера.

// В общем, судя по всему, если есть указатель на непрерывную последовательно,
// то оператор индексирования '[n]' будет работать. Эквивалентно *(ptr + n);

#include <iostream>
#include <memory>
#include <vector>

int main() {
  int *pa = new int[10]();
  *(pa + 5) = 5;

  std::cout << pa[5] << std::endl;

  delete[] pa;

  std::vector<int> vec = {1, 2, 3, 4, 5};
  auto iter = vec.begin() + 2;
  std::cout << iter[1] << std::endl;
}

// Теперь, если возвращаться к заданию.

// Не очень понятно, что нужно сделать для индексирования в StrBlobPtr. Ведь это
// по сути тип итератора на вектор в StrBlob. Его сначала рзывмновывать
// (обращаться к значению), а потом использовать индекс, но для этого нужно
// использовать перегрузку оператора operator*(), а там потом можно использовать
// индекс самого вектора.

// В общем буду считать это действие лишним... Подумал я и потом поделал тесты
// выше. Оператор индексирования просто суммирует число к итератору и берет по
// нему значение. Либо этому в книге уделили мало внимания, либо я был
// невнимателен, либо подзабыл к этому времени.