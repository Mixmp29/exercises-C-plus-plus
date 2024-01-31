// Упражнение 13.22. Пердположим, класс HasPtr должен вести себя, как значение.
// Таким образом, у каждого его объекта должна быть собственная копия строки, на
// которую указывает объект. Определения функций-членов управления копированием
// рассматривается в следующем разделе, но уже сейчас известно все необходимое
// для их реализации.

// Судя по всему это своеборазное повторение. Класс уже написан по
// заданиям 13.5, 13.8, 13.11. Дальше можно будет сверить свою реализацию и
// книги.

// Я вот только потом заметил, что старый объект у меня не освобождается, просто
// меняется указатель на новый. Утечка получается.

#include <string>

class HasPtr {
 public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}
  ~HasPtr() {
    delete ps;
  }  // Нужно сделать освобождение string явно, иначе будет просто удален
     // указатель, а не объект.

  HasPtr &operator=(const HasPtr &rhs) {
    // Провтыкал тут ещё одну важную вещь. Надо освободить область памяти, на
    // которую указывает ps, а только потом присваивать ему новую строку. Иначе
    // указатель поменяет свой объект, а старое значение так и не удалится.
    // ps = new std::string(*rhs.ps);
    std::string *newp =
        new std::string(*rhs.ps);  // <- Под копией объекта понимается вот это.
    delete ps;  // <- Не забыть освободить старый объект. ps теперь пустой
                // (потерянный).
    ps = newp;
    i = rhs.i;
    return *this;  // <- Про это забывать не нужно.
  }

 private:
  std::string *ps;
  int i;
};