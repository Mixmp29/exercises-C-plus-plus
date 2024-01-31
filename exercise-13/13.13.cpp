// Упражнение 13.13. Наилучший способ изучения функций-членов управлений
// копированием и конструкторов - это определить простой класс с этими
// функциями-членами, каждая из которых выводит свое имя:

#include <iostream>
#include <vector>

struct X {
  X() { std::cout << "X()" << std::endl; }
  X(const X&) { std::cout << "X(const X&)" << std::endl; }
  ~X() { std::cout << "~X()" << std::endl; }
  X& operator=(const X& rhs) {
    std::cout << "operator=(const X&)" << std::endl;
    a = rhs.a;
    return *this;
  }

  int a = 0;
};

// Добавьте в структуру X оператор присвоения копии и деструктор, а затем
// напишите программу, использующую объекты класса X различными способами:
// передайте их как ссылочный и не ссылочный параметры; динамически
// зарезервируйте их; поместите в контейнеры и т.д. Изучайте ввод, ока не
// начнете хорошо понимать, когда и почему используется каждая функция-член
// управления копированием. По мере чтения вывода помните, что компилятор может
// обойти вызовы конструктора копий.

// По факту, интересно наблюдать как это работает по мере добавления кода с
// нуля.

X func(X a) { return X(); }
X func2(X a) { return a; }

int main() {
  X val1;
  X val2 = val1;
  val1 = val2;

  X val4 = X();  // <- Вроде как тут создание временного объекта и через него
                 // инициализация копированием. Однако, судя по всему,
                 // компилятор преобразует это в прямую инициализацию. В
                 // функциях, видимо, также.

  X* p = new X;
  delete p;  // Если закоментить, то деструктора не будет. Удалится только
             // указатель.

  X& val3 = val1;  // Ничего не происходит.

  std::cout << "-------- vector ------------" << std::endl;
  {  // Скобки создают отдельную область видимости.
    std::vector<X> vec(5);
  }

  std::cout << "-------- func ------------" << std::endl;
  {
    func(X());  // <- Прямая инициализация и прямамя инициализация.
  }
  {
    func(val4);  // Инициализация копированием и прямая инициализация
    //  копией при возврате.
  }
  {
    func2(val4);  // Инициализация копированием и инициализация
    // копированием при возврате.
  }
  {
    func2(X());  // Прямамя инициализация и инициализация
    // копированием при возврате.
  }
  std::cout << "----------------------------" << std::endl;
}